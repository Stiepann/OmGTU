using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BL
{
    public interface IPerson
    {
        double CalculateSalary(int hours, int overhours, int bonus);
    }
}
