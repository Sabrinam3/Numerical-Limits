/*!	\file	ut_catalan.cpp
	\author	Garth Santor
	\date	2018.09.09
	\brief	Test catalan number function implementations.
*/


// import student's catalan implementation
#include "../include/catalan.hpp"

// import the boost unit test framework
#define BOOST_TEST_MODULE GradePellFunction
#include <boost/test/auto_unit_test.hpp>
#include <boost/mpl/list.hpp>

// import the boost multiprecision integer library
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// import standard libraries
#include <cstdint>
#include <vector>
using namespace std;


// Catalan tests
// =======================================================================================================

std::vector<cpp_int> catalanNumbers{ 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, 18367353072152, 69533550916004, 263747951750360, 1002242216651368, 3814986502092304,
};



BOOST_AUTO_TEST_CASE(catalan_test_binomial) {
	cpp_int idx = 0;
	for (auto cn : catalanNumbers)
		BOOST_CHECK(cn == catalan_binomial(idx++));
}



BOOST_AUTO_TEST_CASE(catalan_test_product_series) {
	cpp_int idx = 0;
	for (auto cn : catalanNumbers)
		BOOST_CHECK(cn == catalan_product_series(idx++));

	BOOST_CHECK(catalan_product_series(cpp_int(100)) == cpp_int("896519947090131496687170070074100632420837521538745909320"));
}

