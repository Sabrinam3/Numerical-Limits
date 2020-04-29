/*!	\file	Limits_main.cpp
	\author Sabrina Tessier
	\date	September 15, 2018
	\brief	Test the numerical limits of our algorithms.
*/
#define NOMINMAX
#include "../include/pell.hpp"
#include "../include/sylvester.hpp"
#include "../include/catalan.hpp"
#include <limits>
#include <iomanip>
#include "stopwatch.hpp"

using namespace std;
cpp_int findMax128Signed(cpp_int &calc_result, cpp_int &limit, char &c);
cpp_int findMax128Unsigned(cpp_int &calc_result, cpp_int &limit, char &c);
cpp_int rpower(cpp_int base, cpp_int exp);
void exploreLimits(std::string &currentTest, char &c, cpp_int &calc_result, cpp_int &maxValue);
void timerCatalan();

/*!	\brief	Find the max 'n' that can be calculated for pell, sylvester, and catalan algorithms using the datatype specified by template argument L
*/
template <typename L>
cpp_int findMax(cpp_int &result,  L &dataType, cpp_int &maxValue, char &c)
{
	bool maxReached = false;
	//cpp_int maxVal = 0;
	cpp_int nextResult = 0;

	while (!maxReached)
	{
		//See which function should be called
		if (c == 'p')
		{
			nextResult = pell(maxValue);
		}
		else if (c == 's')
		{
			nextResult = sylvester(maxValue);
		}
		else if (c == 'c')
		{
			nextResult = catalan_product_series(maxValue);
		}

		//Check if the nextResult is larger than the max. If it is, the function is done. If it's not, assign to 'result' and keep going
		if (nextResult <= numeric_limits<L>::max() )
		{
			result = nextResult;
			++maxValue;
		}
		else
		{
			maxReached = true;
		}
	}

	return maxValue - 1;
}

int main()
{
	//Set the locale
	locale here("");
	cout.imbue(here);

	//variable to hold the result of the calculation and the max number in series that can be calculated
	cpp_int calc_result = 0;
	cpp_int maxValue = 0;

	// Pell function test
	std::string currentTest = "Pell";
	char c = 'p';
	exploreLimits(currentTest, c, calc_result, maxValue);
	
	//Sylvester function test
	//reset maxValue
	maxValue = 0;
	currentTest = "Sylvester";
	c = 's';
	cout << "\n\n";
	exploreLimits(currentTest, c, calc_result, maxValue);
	
	//Catalan function test
	//reset maxValue
	maxValue = 0;
	currentTest = "Catalan";
	c = 'c';
	cout << "\n\n";
	exploreLimits(currentTest, c, calc_result, maxValue);

	//Execute timed run of catalan(0) to catalan(1000) using both implementations
	timerCatalan();
}

/*!	\brief	Discovers and prints maximum calculations possible for each datatype and prints the result
*/
void exploreLimits(std::string &currentTest, char &c, cpp_int &calc_result, cpp_int &maxValue)
{
	//VARIABLES TO FEED INTO TEMPLATE FUNCTION THAT FINDS MAX CALCULATION
//signed/unsigned 16 bit integer
	int16_t int16;
	uint16_t uint16;
	//signed/unsigned 32 bit integer
	int32_t int32;
	uint32_t uint32;
	//signed/unsigned 64 bit integer
	int64_t int64;
	uint64_t uint64;
	cout << right << setw(55) << currentTest << " Limits" << endl;
	cout << setw(120) << setfill('=') << "\n";
	cout << setfill(' ');
	maxValue = findMax(calc_result, int16, maxValue, c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 16-bit signed" << endl;
	maxValue = findMax(calc_result, uint16, maxValue,c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 16-bit unsigned" << endl;
	maxValue = findMax(calc_result, int32, maxValue,c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 32-bit signed" << endl;
	maxValue = findMax(calc_result, uint32, maxValue,c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 32-bit unsigned" << endl;
	maxValue = findMax(calc_result, int64, maxValue, c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 64-bit signed" << endl;
	maxValue = findMax(calc_result, uint64, maxValue,c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 64-bit unsigned" << endl;
	//SPECIAL CASE: limits for 128-bit integers cannot be calculated by using numeric_limits.
	//values to represent the max signed/unsigned 128-bit integers
	cpp_int max128Unsigned = rpower(2, 128) - 1;
	cpp_int max128Signed = max128Unsigned / 2;
	//Find the numeric limits for the 128-bit integers
	maxValue = findMax128Signed(calc_result, max128Signed, c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 128-bit signed" << endl;
	maxValue = findMax128Unsigned(calc_result, max128Unsigned, c);
	cout << right << setw(40) << calc_result << " = " << currentTest << "(" << maxValue << ") -> 128-bit unsigned" << endl;	
}

/*!	\brief	Calculate and return the base to the power of exp
*/
cpp_int rpower(cpp_int base, cpp_int exp)
{
	if (exp == 0)
		return cpp_int(1);
	auto x = rpower(base, exp / 2);
	if (exp % 2 == 0)
		return x * x;
	else
		return base * x * x;
}
/*!	\brief	Determines the highest number in the pell, sylvester, and catalan series that can be calculated using an 128-bit signed integer
*/
cpp_int findMax128Signed(cpp_int &calc_result, cpp_int &limit, char &c)
{
	cpp_int n = 0;
	cpp_int nextResult = 0;
	bool done = false;
	while (!done)
	{
		if (c == 'p')
		{
			nextResult = pell(n);
		}
		else if (c == 's')
		{
			nextResult = sylvester(n);
		}
		else if (c == 'c')
		{
			nextResult = catalan_product_series(n);
		}
		if (nextResult <= limit)
		{
			calc_result = nextResult;
			++n;
		}
		else
		{
			done = true;
		}
	}
	return n - 1;
}
/*!	\brief	Determines the highest number in the pell, sylvester, and catalan series that can be calculated using an 128-bit unsigned integer
*/
cpp_int findMax128Unsigned(cpp_int &calc_result, cpp_int &limit, char &c)
{
	cpp_int n = 0;
	cpp_int nextResult = 0;
	bool done = false;
	while (!done)
	{
		if (c == 'p')
		{
			nextResult = pell(n);
		}
		else if (c == 's')
		{
			nextResult = sylvester(n);
		}
		else if (c == 'c')
		{
			nextResult = catalan_product_series(n);
		}
		if (nextResult <= limit)
		{
			calc_result = nextResult;
			++n;
		}
		else
		{
			done = true;
		}
	}
	return n - 1;
}

/*!	\brief	Times the execution of binomial and product-series catalan from n = 0 to n = 1000 and declares which implementation is faster and by how many 'ticks'
*/
void timerCatalan()
{
	//Declare a stopwatch object to use to time the functions
	gats::StopWatch sw;
	//Time the binomial calculation
	sw.start();
	for (cpp_int i = 0; i <= 1000; ++i)
	{
		catalan_binomial(i);
	}
	sw.stop();
	LONGLONG firstTicks = sw.ticks();

	//Second implementation- product series
	sw.start();
	for (cpp_int i = 0; i <= 1000; ++i)
	{
		catalan_product_series(i);
	}
	sw.stop();
	LONGLONG secondTicks = sw.ticks();

	cout << "\n\n" << right << setw(62)<< "Timer results:" << endl;
	cout << setw(120) << setfill('=') << "\n";
	cout << setfill(' ');
	cout << "Binomial of catalan(0) to catalan(1000) took " << firstTicks << " ticks." << endl;
	cout << "Product series of catalan(0) to catalan(1000) took " << secondTicks << " ticks" << endl;
	
	if (firstTicks < secondTicks)
	{
		cout << "\nBinomal catalan function is the winner! It was faster by " << secondTicks - firstTicks << " ticks." << endl;
	}
	else
	{
		cout << "\nProduct series function is the winner! It was faster by " << firstTicks - secondTicks << " ticks." << endl;
	}
}


