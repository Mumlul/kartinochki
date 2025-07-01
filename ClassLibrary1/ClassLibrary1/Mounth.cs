using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public class Mounth : Road
    {
        private int mounth;

        public int Mounth2
        {
            get { return mounth; }
            set 
            {
                if (value < 0 || value > 12)
                {
                    do
                    {
                        Console.WriteLine("Введите подходящий мясяц");
                        mounth = Convert.ToInt32(Console.ReadLine());
                    }
                    while (mounth < 0 || mounth > 12);
                    
                }
                else mounth = value;
            }
        }

        private int[] mouths = new int[] { 3, 4, 9, 10 };
        public Mounth(double w, double l, double we, int mounth) : base(w, l, we)
        {
            this.Mounth2 = mounth;
        }

        public override double Quality()
        {
            if (mounth > 5 && mounth < 8)
            {
                return base.Quality() * 1.1;
            }
            else if (mouths.Contains(mounth))
            {
                return base.Quality() * 1.6;
            }
            else
            {
                return base.Quality() * 2.1 + mounth * 10;
            }
        }

    }
}
