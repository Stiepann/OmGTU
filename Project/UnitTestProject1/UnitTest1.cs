﻿using System;
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
            double expectedResult = 23350;
            double actualResult;
            Engineer engneer1 = new Engineer();

            actualResult = engneer1.CalculateSalary(150, 25, 15);

            Assert.AreEqual(expectedResult, actualResult);
        }

        
    }
}
