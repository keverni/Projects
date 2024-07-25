using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;
using ExcelDataReader;
using System.IO;
//using System.Windows.Forms.DataVisualization.Charting;
using ZedGraph;

namespace Алгоритм_Электропотребление
{
    public partial class Form1 : Form
    {
        private string fileName = string.Empty;

        private DataTableCollection tableCollection = null;




        public Form1()
        {
            InitializeComponent();
            Text = "AG 2023 ИИ";
            StartPosition = FormStartPosition.CenterScreen;
        }
        public Form1 form1 { get; set; }
        Form2 form2 = new Form2();
        Form3 form3 = new Form3();
        Form4 form4 = new Form4();
        Form5 form5 = new Form5();
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                DialogResult res = openFileDialog1.ShowDialog();

                if (res == DialogResult.OK)
                {
                    fileName = openFileDialog1.FileName;
                    Console.WriteLine(fileName);
                    Text = fileName;

                    OpenExcelFile(fileName);


                }
                else
                {
                    throw new Exception("Файл не выбран!");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


        private void OpenExcelFile(string path)
        {
            FileStream stream = File.Open(path, FileMode.Open, FileAccess.Read);

            IExcelDataReader reader = ExcelReaderFactory.CreateReader(stream);

            DataSet db = reader.AsDataSet(new ExcelDataSetConfiguration()
            {
                ConfigureDataTable = (x) => new ExcelDataTableConfiguration()
                {
                    UseHeaderRow = true
                }
            });

            tableCollection = db.Tables;
            toolStripComboBox1.Items.Clear();

            foreach (DataTable tabe in tableCollection)
            {
                toolStripComboBox1.Items.Add(tabe.TableName);
            }

            toolStripComboBox1.SelectedIndex = 0;
        }
        DataTable tableTheft = new DataTable();
        DataTable tableDataError = new DataTable();
        DataTable tableChart = new DataTable();
        DataTable tableCheckTheft = new DataTable();
        private void toolStripComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            DataTable table = tableCollection[Convert.ToString(toolStripComboBox1.SelectedItem)];

            dataGridView1.AutoGenerateColumns = true;
            dataGridView1.DataSource = table;
            tableTheft = table;
            tableDataError = table;
            tableChart = table;
            tableCheckTheft = table;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool flagTheft = false;
            bool flagDataError = false;
            bool flagCheckTheftError = false;
            double summa1 = 0, summa = 0;
            for (int c = 2; c < dataGridView1.ColumnCount; c++)
            {
                double Y = 0, Y2 = 0, temp = 0;
                summa = 0;

                for (int i = 1; i < dataGridView1.RowCount - 1; i += 3)
                {
                    

                    try
                    {

                        Y = Convert.ToDouble(dataGridView1[c, i].Value);

                        Y2 = Convert.ToDouble(dataGridView1[c, i + 1].Value);

                        temp = Convert.ToDouble(dataGridView1[c + 1, i].Value);


                    }
                    catch
                    {
                        flagDataError = true;
                    }

                    if (Y > temp)
                    {
                        if (flagCheckTheftError == false)
                        {
                            flagCheckTheftError = true;
                        }
                       
                    }
                    if ((Y2 >= Y && Y2 != 0 && Y != 0) || Y2 >= 2)
                    {
                        if (flagTheft == false)
                        {
                            flagTheft = true;
                        }



                        
                    } else if (Y2 == 0 || Y == 0)
                    {

                        if (flagDataError == false)
                        {
                            flagDataError = true;
                        }
                        
                    }
                    summa += Y;
                    Y = 0;
                    Y2 = 0;
                    temp = 0;
                }
                if (summa1 == 0)
                {
                    summa1 = summa;
                } else
                {
                    if (((summa / summa1) * 100) > 10)
                    {
                        flagCheckTheftError = true;
                    } else
                    {
                        summa1 = summa;
                    }
                }
            }

            if (flagTheft)
            {
                ErrorTheft();
            }
            if (flagDataError)
            {
                DataError();
            }
            if (flagCheckTheftError)
            {
                CheckTheftError();
            }

        }
        private void ErrorTheft()
        {

            form2.ExcelData2 = tableTheft;
            form2.Show();
        }
        private void DataError()
        {
            form3.ExcelData3 = tableDataError;
            form3.Show();
        }
        private void CheckTheftError()
        {
            form5.ExcelData5 = tableCheckTheft;
            form5.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {

            
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        public void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void файлToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            AnotherGraph(tableChart);
        }
        


        public static void AnotherGraph(DataTable dataTable)
        {
            ZedGraphControl graphControl = new ZedGraphControl();
            graphControl.Dock = DockStyle.Fill;

            // Создание формы для отображения графика
            Form graphForm = new Form();
            
            graphForm.Size = new System.Drawing.Size(1100, 700);
            graphForm.Text = "График расхождения показаний";
            graphForm.Controls.Add(graphControl);

            // Создание графика
            GraphPane graphPane = graphControl.GraphPane;
            //graphPane.Title.Text = "График относительных потерь";
            graphPane.Title.Text = "";
            graphPane.XAxis.Title.Text = "T(Дни)";
            graphPane.YAxis.Title.Text = "P(кВт*ч)";
            PointPairList points = new PointPairList();
            // Перебор столбцов DataTable
            for (int i = 3; i < (dataTable.Columns.Count / 2) - 1; i++)
            {
                double firstValue = 0;
                double sumValue = 0;

                // Добавление точек графика из значений столбца
                
                for (int row = 1; row < dataTable.Rows.Count; row += 3)
                {
                    if (row == 1)
                    {
                        if (dataTable.Rows[row][i] != DBNull.Value)
                        {
                            firstValue = Convert.ToDouble(dataTable.Rows[row][i]) * 60;
                        }
                    }
                    else
                    {
                        if (dataTable.Rows[row][i] != DBNull.Value)
                        {
                            sumValue += Convert.ToDouble(dataTable.Rows[row][i]);
                        }
                    }
                }

                // Умножение первого значения на 60 и деление на сумму всех значений
                double x = i - 3;
                double y = firstValue  - sumValue;
                points.Add(x, y);

                // Добавление кривой на график
                
            }
            graphPane.AddCurve("", points, Color.Blue, SymbolType.None);

            // Перерисовка графика
            graphControl.AxisChange();
            graphControl.Invalidate();

            // Отображение окна с графиком
            graphForm.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form6 form6 = new Form6();
            form6.Show();
        }
    }

}

