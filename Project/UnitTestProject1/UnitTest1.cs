using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using BL;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            double expectedResult = 130;
            double actualResult;
            Ingineer engneer1 = new Ingineer();

            actualResult = engneer1.CalculateSalary(100, 20, 10);

            Assert.AreEqual(expectedResult, actualResult);
        }

        
    }
}
