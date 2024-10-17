#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.2.rec/Lab_06.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int testArray[] = { 2, 4, 6, 8, 10 };
			int size = sizeof(testArray) / sizeof(testArray[0]);
			int i = 0;
			int S = 0;
			int N = 0;
			double result = CalculateArithmeticMean(testArray, size,i,S,N);

			Assert::AreEqual(6.0, result);
		}
	};
}
