using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public class Engineer : Person
    {
        public string position { get; set; }
        public int hours { get; set; }
        public int overHours { get; set; }
        public int bonus { get; set; }

        public Engineer()
            : base()
        {

        }
        public Engineer(string firstName, string SecondName, string Patnymic, string Position, int Hours, int OverHours, int Bonus)
            : base(firstName, SecondName, Patnymic)
        {
            this.position = Position;
            this.hours = Hours;
            this.overHours = OverHours;
            this.bonus = Bonus;
        }
        public override double CalculateSalary(int hours, int overhours, int bonus)
        {
            return 150 * hours + 25 * overhours + 15 * bonus;
        }
    }
}
