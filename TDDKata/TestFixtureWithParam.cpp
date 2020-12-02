#include "pch.h"
#include "TestFixtureWithParam.h"


//INSTANTIATE_TEST_CASE_P(Parmetrized, TestFixtureWithParams, ::testing::Values(Param("2,3"), 5), Param("2,4"));
/*
std::vector<Param> CreateParametersSet()
{
	std::vector<Param> p;
	p.push_back(Param("2,3", 5));
	p.push_back(Param("2,3,1", 6));
	return p;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam, ::testing::ValuesIn(CreateParametersSet));

*/