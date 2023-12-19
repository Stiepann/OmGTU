using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public class Worker : Person
    {
        public string position { get; set; }
        public int hours { get; set; }

        public Worker()
            : base()
        {

        }
        public Worker(string firstName, string SecondName, string Patnymic, string Position, int Hours)
            : base(firstName, SecondName, Patnymic)
        {
            this.position = Position;
            this.hours = Hours;
        }
        public override double CalculateSalary(int hours, int overhours, int bonus)
        {
            return 200 * hours + 250*overhours + 0*bonus;
        }
    }
}
