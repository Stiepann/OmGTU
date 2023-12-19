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
            double expectedResult = 10500;
            double actualResult;
            Engineer engneer1 = new Engineer();

            actualResult = engneer1.CalculateSalary(100, 20, 10);

            Assert.AreEqual(expectedResult, actualResult);
        }

        
    }
}
