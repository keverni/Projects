using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Алгоритм_Электропотребление
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }
        Form7 form7 = new Form7();
        private void Form6_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            form7.Selenia = 1;
            form7.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string pdfFolderPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "PdfFiles");
            string pdfFilePath = Path.Combine(pdfFolderPath, "ВЛ-10 кВ  Ф-106 ПС  1.pdf");
            Console.WriteLine(pdfFilePath);
            form7.PDFOpen(pdfFilePath);
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }
        
    }
}
