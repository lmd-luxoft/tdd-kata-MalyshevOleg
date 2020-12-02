#include "pch.h"
#include "TestFixtureWithParam.h"
#include "TestFixture.h"
#include <vector>


std::vector<Param> CreateParametersSet()
{
	std::vector<Param> p;
	p.push_back(Param("", Calculator::errEmpty));
	p.push_back(Param("aaa", Calculator::errNotDigitArgs));
	p.push_back(Param("4;2", Calculator::errNonCorrectDelim));
	p.push_back(Param("4,", Calculator::errUnclosedDelim));
	p.push_back(Param("1", 1));
	p.push_back(Param("2,2", 4));
	p.push_back(Param("1,2,3", 6));
	p.push_back(Param("1,2,3,4", 10));
	p.push_back(Param("1\n", Calculator::errUnclosedDelim));
	p.push_back(Param("1\n2\n", Calculator::errUnclosedDelim));
	p.push_back(Param("1\n2\n3", 6));
	p.push_back(Param("//;\n1-2//|\n3|5,6-7", Calculator::errNonCorrectDelim));
	p.push_back(Param("//need_end", Calculator::errNonCorrectDelim));
	p.push_back(Param("//\n", Calculator::errNonCorrectDelim));
	p.push_back(Param("//[;]\n1;2//[|]\n3|5,6|7;9", 33));
	p.push_back(Param("-1-0,-20,-30,5,-4", Calculator::errNotDigitArgs));
	p.push_back(Param("-10,-20", Calculator::errException));
	p.push_back(Param("1001,1003,2,1000,999", 2001));
	p.push_back(Param("//[***]\n1***2***3", 6));
	p.push_back(Param("//[***][##\n1***2***3", Calculator::errUnclosedDelim));
	p.push_back(Param("//[***][##]\n1***2##3", 6));
	p.push_back(Param("//[*][%]\n1*2%3", 6));
	p.push_back(Param("//[****][%%%]\n1****2%%%3", 6));
	//[****][%%%]\n1****2%%%3


	return p;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest,
			TestFixtureWithParam, 
			::testing::ValuesIn(CreateParametersSet()));

