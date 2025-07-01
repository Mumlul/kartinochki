using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public class Road
    {
        public double width;
        public double lenght;
        public double weight;

        private static List<Road> roads = new List<Road>();

        public Road(double w, double l, double we)
        {
            this.width = w;
            this.lenght = l;
            this.weight = we;

            roads.Add(this);
        }

        public virtual double Quality()
        {
            return Math.Round(width * lenght * weight / 1000, 2);
        }

        public static int GetRoadsCount() => roads.Count;

    }
}
