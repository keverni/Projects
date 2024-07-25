using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;

namespace Алгоритм_Электропотребление
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            
        }
        
        private void Form2_Load(object sender, EventArgs e)
        {

            DataTable table2 = new DataTable();
            table2 = ExcelData2.Clone();
            int TheftRow = 0;
            bool flag = false;
            for (int i = 1; i < ExcelData2.Rows.Count - 1; i += 3)
            {
                double Y = 0, Y2 = 0;
                for (int c = 2; c < ExcelData2.Columns.Count; c++)
                {
                    try
                    {
                        Y = Convert.ToDouble(ExcelData2.Rows[i][c]);
                        Y2 = Convert.ToDouble(ExcelData2.Rows[i + 1][c]);
                    }
                    catch
                    {
                        continue;
                    }
                    if ((Y2 >= Y && Y2 != 0 && Y != 0) || Y2 >= 2)
                    {

                        DataRow row = ExcelData2.Rows[i];
                        if (!ContainsDataRow(table2, row))
                        {
                            DataRow row1 = ExcelData2.Rows[i + 1];
                            table2.ImportRow(row);
                            table2.ImportRow(row1);
                        }
                        if (flag == false)
                        {
                            flag = true;
                            TheftRow = i;
                        }


                        //dataGridView2.Rows[i].Cells[c].Style.BackColor = Color.Red;
                        //dataGridView2.Rows[i + 1].Cells[c].Style.BackColor = Color.Red;

                    }
                    Y = 0;
                    Y2 = 0;

                }
                if (flag)
                {
                    DrawGraphs(ExcelData2, TheftRow);
                    flag = false;
                }
            }
            
            dataGridView2.AutoGenerateColumns = true;
            dataGridView2.DataSource = table2;
            for (int c = 2; c < dataGridView2.ColumnCount; c++)
            {
                double Y = 0, Y2 = 0;

                for (int i = 0; i < dataGridView2.RowCount; i += 2)
                {

                    try
                    {

                        Y = Convert.ToDouble(dataGridView2[c, i].Value);

                        Y2 = Convert.ToDouble(dataGridView2[c, i + 1].Value);


                    }
                    catch
                    {
                        continue;
                    }


                    if ((Y2 >= Y && Y2 != 0 && Y != 0) || Y2 >= 2)
                    {

                        dataGridView2.Rows[i].Cells[c].Style.BackColor = Color.Red;
                        dataGridView2.Rows[i + 1].Cells[c].Style.BackColor = Color.Red;
                        Y = 0;
                        Y2 = 0;
                    }


                }
            }

        }
        public DataTable ExcelData2 { get; set; }

        public bool ContainsDataRow(DataTable dataTable, DataRow dataRow)
        {
            foreach (DataRow row in dataTable.Rows)
            {
                if (DataRowEquals(row, dataRow))
                {
                    return true;
                }
            }
            return false;
        }

        public bool DataRowEquals(DataRow row1, DataRow row2)
        {
            if (row1.ItemArray.Length != row2.ItemArray.Length)
            {
                return false;
            }

            for (int i = 0; i < row1.ItemArray.Length; i++)
            {
                if (!row1.ItemArray[i].Equals(row2.ItemArray[i]))
                {
                    return false;
                }
            }

            return true;
        }
        public void DrawGraphs(DataTable dataTable, int c)
        {
            ZedGraphControl graphControl = new ZedGraphControl();
            graphControl.Dock = System.Windows.Forms.DockStyle.Fill;

            // Добавление элемента управления на форму или другой контейнер
            // Например, можно добавить на новую форму
            Form4 graphForm = new Form4();
            graphForm.Width = 1920;
            graphForm.Height = 1080;
            graphForm.Text = "График хищения";
            graphForm.Controls.Add(graphControl);
            graphForm.Size = new System.Drawing.Size(1100, 700);

            // Создание графика
            GraphPane graphPane = graphControl.GraphPane;
            graphPane.Title.Text = " ";
            
            graphPane.XAxis.Title.Text = "T(Дни)";
            graphPane.YAxis.Title.Text = "P(кВт*ч)";

            // Перебор строк DataTable
            for (int row = c; row < c + 1; row++)
            {
                // Создание новой кривой для каждой строки
                LineItem curve = graphPane.AddCurve("А+", null, null, Color.Blue, SymbolType.None);
                LineItem curve1 = graphPane.AddCurve("А-", null, null, Color.Red, SymbolType.None);
                // Добавление точек графика из значений строки
                PointPairList points = new PointPairList();
                PointPairList points1 = new PointPairList();
                for (int i = 2; i < (dataTable.Columns.Count / 2) - 1; i++)
                {
                    double x = i - 2;
                    double x1 = i - 2;
                    double y;
                    double y1;

                    // Проверка на DBNull перед преобразованием
                    if (dataTable.Rows[row][i] != DBNull.Value && dataTable.Rows[row + 1][i] != DBNull.Value)
                    {
                        y = Convert.ToDouble(dataTable.Rows[row][i]);
                        y1 = Convert.ToDouble(dataTable.Rows[row + 1][i]);
                    }
                    else
                    {
                        y = 0; // Значение по умолчанию или другая обработка DBNull
                        y1 = 0; // Значение по умолчанию или другая обработка DBNull
                    }

                    points.Add(x, y);
                    points1.Add(x1, y1);
                }

                curve.Points = points;
                curve1.Points = points1;
            }



            // Перерисовка графика
            graphControl.AxisChange();
            graphControl.Invalidate();

            // Отображение окна с графиками
            graphForm.ShowDialog();
        }


    }
}
