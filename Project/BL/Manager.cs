using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public class Manager : Person
    {
        public string position { get; set; }
        public int hours { get; set; }
        public int bonus { get; set; }
        public int overhours { get; set; }

        public Manager()
            : base()
        {

        }
        public Manager(string firstName, string SecondName, string Patnymic, string Position, int Hours, int OverHours, int Bonus)
            : base(firstName, SecondName, Patnymic)
        {
            this.position = Position;
            this.hours = Hours;
            this.bonus = Bonus;
            this.overhours = OverHours;
        }
        public override double CalculateSalary(int hours, int overhours, int bonus)
        {
            return 250 * hours + 350 * overhours + 1000 * bonus;
        }
    }
}
