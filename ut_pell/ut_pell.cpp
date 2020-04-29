/*!	\file	ut_pell.cpp
	\author	Garth Santor
	\date	2018.09.09
	\brief	Test pell number function implementations.
*/


// import student's pell implementation
#include "../include/pell.hpp"

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


// Pell tests
// =======================================================================================================

std::vector<uint64_t> pellNumbers{ 0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2'378, 5'741, 13'860, 33'461,
	80'782, 195'025, 470'832, 1'136'689, 2'744'210, 6'625'109, 15'994'428, 38'613'965, 93'222'358,
	225'058'681, 543'339'720, 1'311'738'121, 3'166'815'962, 7'645'370'045, 18'457'556'052, 44'560'482'149,
	107'578'520'350, 259'717'522'849 };


BOOST_AUTO_TEST_CASE(pell_test_recursive_uint64_t) {
	uint64_t idx = 0;
	for (auto pn : pellNumbers)
		BOOST_CHECK_EQUAL(pn, rpell(idx++));
}

BOOST_AUTO_TEST_CASE(pell_test_loop_uint64_t) {
	uint64_t idx = 0;
	for (auto pn : pellNumbers)
		BOOST_CHECK_EQUAL(pn, pell(idx++));
}

BOOST_AUTO_TEST_CASE(pell_test_loop_cpp_int) {
	cpp_int idx = 0;
	for (auto pn : pellNumbers)
		BOOST_CHECK(pn == pell(idx++));
	BOOST_CHECK(pell(cpp_int(100)) == cpp_int("66992092050551637663438906713182313772"));
}

