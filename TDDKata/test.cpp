#include "pch.h"
#include "TestFixture.h"
#include "TestFixtureWithParam.h"

// Correction tests
TEST_F(TestFixture, ParseSpecialDelimetersTest2) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//---";

	std::vector<char*> cd;
	int res;
	// Act
	res = calc->ParseSpecialDelimeters(&string, cd);
	// ASSERT
	ASSERT_EQ(res, Calculator::errNonCorrectDelim);
	ASSERT_EQ(cd.size(), 0);
}

// Works normal
TEST_F(TestFixture, ParseSpecialDelimetersTest3) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//[;]\n";

	std::vector<char*> cd;
	int res;
	// Act
	res = calc->ParseSpecialDelimeters(&string, cd);
	int res1 = 1;
	if(cd.size()>0)
		res1 = strcmp(";", cd[0]);
	// ASSERT
	ASSERT_EQ(res, 0);
	ASSERT_EQ(cd.size(), 1);
	ASSERT_EQ(res1,0);
}



// Working test
TEST_F(TestFixture, AddNegatives2) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "-10,-20";

	int res;
	// Act
	res = calc->Add(string);
	int res1 = strcmp("Negatives not allowed:-10|-20|", calc->message);
	calc->FreeMessages();
	// ASSERT
	ASSERT_EQ(res, Calculator::errException);
	ASSERT_EQ(res1, 0);
}

