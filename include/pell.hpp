#pragma once
/*!	\file	pell.hpp
	\author	Sabrina Tessier
	\date	September 15, 2018
	\brief	Sabrina's Pell number function implementations.
*/
#include <boost/multiprecision/cpp_int.hpp>
using cpp_int = boost::multiprecision::cpp_int;

/*!	\brief	Calculate and return the n'th pell number iteratively
/param cpp_int n - the number in the pell sequence to calculate
/return the n'th pell number
*/
cpp_int pell(cpp_int n)
{
	if (n < 2)
	{
		return n;
	}

	cpp_int first = 0;
	cpp_int second = 1;
	cpp_int pell = 0;

	for (size_t i = 1; i < n; ++i)
	{
		pell = 2 * second + first;
		first = second;
		second = pell;
	}

	return pell;
}

/*!	\brief	Calculate and return the n'th pell number recursively
/param cpp_int n - the number in the pell sequence to calculate
/return the n'th pell number
*/
cpp_int rpell(cpp_int n)
{
	if (n < 2)
	{
		return n;
	}

	return 2 * rpell(n - 1) + rpell(n - 2);
}