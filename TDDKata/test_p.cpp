#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"
#include "TestFixtureWithParam.h"


TEST_P(TestFixtureWithParam, Sample)
{
	const char * op = GetParam().param;
	int expected = GetParam().expected;
	int actual = calc->Add((char *)op);
	if (calc->message) calc->FreeMessages();
	ASSERT_EQ(expected, actual);

}

