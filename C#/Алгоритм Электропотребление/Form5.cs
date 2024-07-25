using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Алгоритм_Электропотребление
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }
        
        Form2 form2 = new Form2();
        private void Form5_Load(object sender, EventArgs e)
        {
            DataTable table5 = ExcelData5.Clone();
            double summa1 = 0, summa = 0;
            int TheftRow = 0;
            bool flag = false;
            for (int c = 2; c < ExcelData5.Columns.Count; c++)
            {
                double Y = 0, Y2 = 0;
                for (int i = 1; i < ExcelData5.Rows.Count - 1; i += 3)
                {
                    try
                    {
                        Y = Convert.ToDouble(ExcelData5.Rows[i][c]);
                        Y2 = Convert.ToDouble(ExcelData5.Rows[i][c + 1]);
                    }
                    catch
                    {
                        continue;
                    }
                    if (Y > Y2)
                    {

                        DataRow row = ExcelData5.Rows[i];
                        if (!form2.ContainsDataRow(table5, row))
                        {
                            DataRow row1 = ExcelData5.Rows[i + 1];
                            table5.ImportRow(row);
                            table5.ImportRow(row1);
                        }
                        if (flag == false)
                        {
                            flag = true;
                            TheftRow = i;
                        }


                        //dataGridView2.Rows[i].Cells[c].Style.BackColor = Color.Red;
                        //dataGridView2.Rows[i + 1].Cells[c].Style.BackColor = Color.Red;

                    }
                    summa += Y;
                    Y = 0;
                    Y2 = 0;

                }
                if (flag)
                {
                    form2.DrawGraphs(ExcelData5, TheftRow);
                    flag = false;
                }
                if (summa1 == 0)
                {
                    summa1 = summa;
                }
                else
                {
                    if (((summa / summa1) * 100) - 100 > 10)
                    {
                        string name = ExcelData5.Columns[c].ColumnName;
                        TextBox textBox = new TextBox();
                        textBox.Width = 300;
                        textBox.Height = 20;
                        textBox.Location = new Point(230, 300);
                        textBox.Text = string.Format("Проверить на хищение столбец {0}", name);
                        Controls.Add(textBox);
                    }
                    else
                    {
                        summa1 = summa;
                    }
                }
            }

            dataGridView5.DataSource = table5;
            for (int c = 2; c < dataGridView5.ColumnCount; c++)
            {
                double Y = 0, Y2 = 0;

                for (int i = 0; i < dataGridView5.RowCount - 1; i += 2)
                {

                    try
                    {

                        Y = Convert.ToDouble(dataGridView5[c, i].Value);

                        Y2 = Convert.ToDouble(dataGridView5[c + 1, i].Value);


                    }
                    catch
                    {
                        continue;
                    }

                    if (Y > Y2)
                    {

                        dataGridView5.Rows[i].Cells[c].Style.BackColor = Color.Red;
                        dataGridView5.Rows[i].Cells[c + 1].Style.BackColor = Color.Red;
                        Y = 0;
                        Y2 = 0;
                    }
                }
            }
            dataGridView5.DataSource = table5;
        }
        public DataTable ExcelData5 { get; set; }
    }
}
