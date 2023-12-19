using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BL;
using System.IO;

namespace Project
{
    public partial class Form1 : Form
    {
        public IPerson person = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Person pers1 = new Person (textBox2.Text, textBox1.Text, textBox3.Text);
            label4.Text = pers1.ShortName();
            Person p = new Person(); 
            p.CalculateSalary(Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox3.Text));

            IPerson ing1 = new Ingineer();
            IPerson mng1 = new Manager();

            label4.Text = ing1.CalculateSalary(Convert.ToInt32(textBox4.Text), Convert.ToInt32(textBox5.Text), Convert.ToInt32(textBox6.Text)).ToString();
            label6.Text = mng1.CalculateSalary(Convert.ToInt32(textBox4.Text), Convert.ToInt32(textBox5.Text), Convert.ToInt32(textBox6.Text)).ToString();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            /*ServiceLocator.Instance.Register("Manager", new Manager());
            ServiceLocator.Instance.Register("Ingineer", new Ingineer());
            string path = @"C:\ФИТ-201\1.txt";
            string typeName = "";*/

            if (File.Exists(path))
            {

                File.ReadLines(path).First();
                typeName = File.ReadAllText(path);
            }

            person = (IPerson)ServiceLocator.Instance.GetService(typeName);

            label7.Text = person.CalculateSalary(Convert.ToInt32(textBox4.Text), Convert.ToInt32(textBox5.Text), Convert.ToInt32(textBox6.Text)).ToString();

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void labbbbbbbbb_Click(object sender, EventArgs e)
        {

        }
    }
}
