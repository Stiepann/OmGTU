using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public class Ingineer : Person
    {
        public string position { get; set; }
        public int hours { get; set; }
        public int overHours { get; set; }

        public Ingineer()
            : base()
        {

        }
        public Ingineer(string firstName, string SecondName, string Patnymic, string Position, int Hours, int OverHours)
            : base(firstName, SecondName, Patnymic)
        {
            this.position = Position;
            this.hours = Hours;
            this.overHours = OverHours;
        }
        public override double CalculateSalary(int hours, int overhours, int bonus)
        {
            return 300 * hours + 500 * overhours + 0 * bonus;
        }
    }
}
