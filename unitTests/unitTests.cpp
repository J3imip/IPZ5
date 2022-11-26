#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\jeimi\source\repos\IPZ 3\IPZ 3\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(unitTests)
	{
	public:
		TEST_METHOD(calculate_FirstFormula)
		{
			//test formula that corresponds to the condition that x<0
			int actual = calculate(-1, 1);
			Assert::AreEqual(0, actual);
		}
		TEST_METHOD(calculate_SecondFormula)
		{
			//test formula that corresponds to the condition that x>=0
			int actual = calculate(1, 2);
			Assert::AreEqual(-2, actual);
		}
		TEST_METHOD(checkInputParameters_startEnd_exceptionThrown)
		{
			//test for validation function (must throw an exception if start of the interval is greater than end)
			try
			{
				checkInputParameters(2, 1); //start greater than end error.
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkInputParameters_startEnd_exceptionNotThrown)
		{
			try
			{
			//test for validation function (must not throw an exception if start of the interval is less than end)
				checkInputParameters(1, 2);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(checkInputParameters_stepIsTooLarge_exceptionThrown)
		{
			try
			{
				//check if exception is thrown if step is bigger than the interval
				checkInputParameters(1, 2, 3);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkInputParameters_stepEqualsZero_exceptionThrown)
		{
			try
			{
				//check if exception is thrown if step is equals 0
				checkInputParameters(1, 2, 0);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkInputParameters_step_exceptionNotThrown)
		{
			try
			{
				//check if exception isn't thrown if step is correct
				checkInputParameters(1, 2, 1);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(checkInputParameters_n_exceptionNotThrown)
		{
			try
			{
				//check if n is integer
				checkInputParameters(1);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(checkInputParameters_n_exceptionThrown)
		{
			try
			{
				//check if n is integer
				checkInputParameters(0.5);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkInputParameters_startEnd_exceptionThrown_incorrect)
		{
			try
			{
				//wittingly incorrect test, start is bigger than end
				checkInputParameters(2, 1);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
