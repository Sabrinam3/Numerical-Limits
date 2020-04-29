#pragma once
/*!	\file	catalan.hpp
	\author	Sabrina Tessier
	\date	September, 15, 2018
	\brief	Sabrina's Catalan number function implementations.
*/
#include <boost/multiprecision/cpp_int.hpp>
using cpp_int = boost::multiprecision::cpp_int;

/*!	\brief	Iteratively compute and return the factorial of 'n'
/param cpp_int n - the number to calculate the factorial of
/return the factorial of n
*/
cpp_int calcFactorial(cpp_int n)
{
	cpp_int fact = 1;
	for (size_t x = 2; x <= n; ++x)
	{
		fact *= x;
	}
	return fact;
}

/*!	\brief	Calculate and return the n'th catalan number using the binomial formula
/param cpp_int n - the number in the catalan sequence to calculate
/return the n'th catalan number
*/
cpp_int catalan_binomial(cpp_int n)
{
	cpp_int catalan = (calcFactorial(2 * n)) / (calcFactorial(n + 1) * calcFactorial(n));
	return catalan;
}

/*!	\brief	Calculate and return the n'th catalan number using the product series formula
/param cpp_int n - the number in the catalan sequence to calculate
/return the n'th catalan number
*/
cpp_int catalan_product_series(cpp_int n)
{
	if (n < 2)
		return 1;
	cpp_int top = 1;
	cpp_int bottom = 1;
	for (cpp_int k = 2; k <= n; ++k)
	{
		top *= k + n;
		bottom *= k;
	}
	return top / bottom;
}

