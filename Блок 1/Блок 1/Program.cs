using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;

namespace Блок_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Переменные для создания классов
            double width,lenght,weight;
            string line;
            string[] values;
            int mount;

            //Получаем/записываем значения
            Console.WriteLine("Введите ширину,длину,вес покрытия,число месяца (через пробел)");
            line = Console.ReadLine();
            line = line.Replace('.', ',');
            values = line.Split(' ');
            width = double.Parse(values[0]);
            lenght = double.Parse(values[1]);
            weight = double.Parse(values[2]);
            mount = int.Parse(values[3]);

            //Создаем основнойкласс
            Road r1=new Road(width,lenght,weight);
            //Вызываем метод качества осн.
            Console.WriteLine(r1.Quality());
            //Создаем класс наследник
            Mounth m1=new Mounth(width,lenght,weight,mount);
            //Вызываем метод качества наследник
            Console.WriteLine(m1.Quality());
            Console.ReadLine();
        }
    }
}
