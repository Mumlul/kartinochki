using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ClassLibrary1;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Road r1 = new Road(10, 20, 30);

            double asnw = r1.Quality();

            Assert.AreEqual(6,asnw);
        }


        [TestMethod]
        public void TestMethod2()
        {
            Road r1 = new Road(10, 20, 30);

            Assert.AreEqual(10, r1.width);
            Assert.AreEqual(20, r1.lenght);
            Assert.AreEqual(30, r1.weight);
        }


        [TestMethod]
        public void TestMethod3()
        {
            Road r1 = new Road(10, 20, 30);
            var answ =Road.GetRoadsCount();
            Assert.AreEqual(1, Road.GetRoadsCount());
        }
    }
}
