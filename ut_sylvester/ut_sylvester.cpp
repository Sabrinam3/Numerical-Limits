/*!	\file	ut_sylvester.cpp
	\author	Garth Santor
	\date	2018.09.09
	\brief	Test sylvester number function implementations.
*/


// import student's sylvester implementation
#include "../include/sylvester.hpp"

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


// Sylvester tests
// =======================================================================================================

std::vector<cpp_int> sylvesterNumbers{ 2, 3, 7, 43, 1'807, 3'263'443,
	10'650'056'950'807, cpp_int("113423713055421844361000443"),
	cpp_int("12864938683278671740537145998360961546653259485195807"),
};



BOOST_AUTO_TEST_CASE(sylvester_test_recursive) {
	cpp_int idx = 0;
	for (auto sn : sylvesterNumbers)
		BOOST_CHECK(sn == rsylvester(idx++));
}



BOOST_AUTO_TEST_CASE(pell_test_loop_cpp_int) {
	cpp_int idx = 0;
	for (auto sn : sylvesterNumbers)
		BOOST_CHECK(sn == sylvester(idx++));
	BOOST_CHECK(sylvester(cpp_int(10)) == cpp_int("27392450308603031423410234291674686281194364367580914627947367941608692026226993"
		"63433211840458243863492954873728399236975848797430631773058075388342946034495641"
		"0077034761330476016739454649828385541500213920807"));
}

