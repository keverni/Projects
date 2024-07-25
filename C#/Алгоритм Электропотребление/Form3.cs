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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();

        }
        Form2 form2 = new Form2();
        private void Form3_Load(object sender, EventArgs e)
        {
            DataTable table3 = ExcelData3.Clone();
            // ВЕРНУТЬСЯ(КОСЯК С КОЛОНКАМИ)
            for (int c = 2; c < (ExcelData3.Columns.Count / 2) - 1; ++c)
            {
                for (int i = 1; i < ExcelData3.Rows.Count - 1; i += 3)
                {
                    
                    if (ExcelData3.Rows[i][c] == DBNull.Value && string.IsNullOrEmpty(ExcelData3.Rows[i][c].ToString()))
                    {
                        DataRow row = ExcelData3.Rows[i];
                        if (!form2.ContainsDataRow(table3, row))
                        {
                            table3.ImportRow(row);
                        }
                    }

                    if (ExcelData3.Rows[i + 1][c] == DBNull.Value && string.IsNullOrEmpty(ExcelData3.Rows[i + 1][c].ToString()))
                    {
                        DataRow row1 = ExcelData3.Rows[i + 1];
                        if (!form2.ContainsDataRow(table3, row1))
                        {
                            table3.ImportRow(row1);
                        }
                    }
                    
                }
                
            }
            
            dataGridView3.DataSource = table3;
            for (int c = 2; c < dataGridView3.ColumnCount; c++)
            {
                double Y = 0, Y2 = 0;

                for (int i = 0; i < dataGridView3.RowCount - 1; i += 2)
                {

                    try
                    {

                        Y = Convert.ToDouble(dataGridView3[c, i].Value);

                        Y2 = Convert.ToDouble(dataGridView3[c, i + 1].Value);


                    }
                    catch
                    {
                        dataGridView3.Rows[i].Cells[c].Style.BackColor = Color.Red;
                        dataGridView3.Rows[i + 1].Cells[c].Style.BackColor = Color.Red;
                    }
                }
            }

        }
        public DataTable ExcelData3 { get; set; }

    }
}
