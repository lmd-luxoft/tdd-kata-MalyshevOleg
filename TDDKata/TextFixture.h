#include "pch.h"

class TestFixture : public testing::Test
{
protected:
	Calculator* calc;
	void SetUp() override
	{
		calc = new Calculator();
	}
	void TearDown() override
	{
		delete calc;
	}
};