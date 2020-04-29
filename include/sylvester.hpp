#pragma once
/*!	\file	sylvester.hpp
	\author	Sabrina Tessier
	\date	September 15, 2018
	\brief	Sabrina's Sylvester number function implementations.
*/
#include <boost/multiprecision/cpp_int.hpp>
using cpp_int = boost::multiprecision::cpp_int;

/*!	\brief	Calculate and return the n'th sylvester number iteratively
/param cpp_int n - the number in the sylvester sequence to calculate
/return the n'th sylvester number
*/
cpp_int sylvester(cpp_int n)
{
	if (n == 0)
		return 2;
	cpp_int previous = 2;
	cpp_int sylvester = 0;
	for (size_t i = 0; i < n; ++i)
	{
		sylvester = ((previous * previous) - previous) + 1;
		previous = sylvester;
	}
	return sylvester;
}

/*!	\brief	Calculate and return the n'th sylvester number recursively
/param cpp_int n - the number in the sylvester sequence to calculate
/return the n'th sylvester number
*/
cpp_int rsylvester(cpp_int n)
{
	if (n == 0)
		return 2;
	return ((rsylvester(n - 1) * rsylvester(n - 1)) - rsylvester(n - 1)) + 1;
}