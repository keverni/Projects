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
using PdfiumViewer;
namespace Алгоритм_Электропотребление
{
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Selenia == 1)
            {
                string pdfFolderPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "PdfFiles");
                string pdfFilePath = Path.Combine(pdfFolderPath, "ВЛ-0,38 кВ ТП 1 Ф 106 ПС 1.pdf");
                Console.WriteLine(pdfFilePath);
                PDFOpen(pdfFilePath);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (Selenia == 1)
            {
                string pdfFolderPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "PdfFiles");
                string pdfFilePath = Path.Combine(pdfFolderPath, "ВЛ-0,38 кВ ТП-2 Ф-106 ПС 1.pdf");
                Console.WriteLine(pdfFilePath);
                PDFOpen(pdfFilePath);
            }
        }
        public int Selenia { get; set; }

        public void PDFOpen(string path)
        {
            if (System.IO.File.Exists(path))
            {
                Form8 form8 = new Form8();
                var doc = PdfDocument.Load(path);
                form8.Docum = doc;
                form8.Show();
            }
            else
            {
                MessageBox.Show("Файл PDF не найден!");
            }
        }
    }
}
