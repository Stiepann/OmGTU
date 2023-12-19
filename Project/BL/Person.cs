using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public class Person:IPerson
    {
        private string firstName;

        public string FirstName
        {
            get { return firstName; }
            set { firstName = value; }
        }

        
        private string SecondName;

        public string SecondName1
        {
            get { return SecondName; }
            set { SecondName = value; }
        }
        private string Patnymic;

        public string Patnymic1
        {
            get { return Patnymic; }
            set { Patnymic = value; }
        }
        private DateTime DateOfBirth;

        public DateTime DateOfBirth1
        {
            get { return DateOfBirth; }
            set { DateOfBirth = value; }
        }
        private string possition;

        public string Possition
        {
            get { return possition; }
            set { possition = value; }
        }
        public Person() { }

        public Person(string _firstName, string _SecondName,string _Patnymic) 
        {
            FirstName = _firstName;
            SecondName1 = _SecondName;
            Patnymic1 = _Patnymic;
        }
        public string ShortName()
        {
            return SecondName + " " + FirstName.Substring(0, 1) + "." + Patnymic.Substring(0, 1);
        }
        public virtual double CalculateSalary(int hours, int overhours, int bonus)
        {
            return 0;
        }
    }
}
