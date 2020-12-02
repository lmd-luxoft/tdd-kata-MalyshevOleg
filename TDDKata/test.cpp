#include "pch.h"
#include "TestFixture.h"

// correction test
TEST_F(TestFixture, AddEmpyString) {
	// Arrange
		char * empty = "";
	
		int res;
	// Act
		res=calc->Add(empty);
	// ASSERT
		ASSERT_EQ(res, (int)Calculator::errEmpty);
	}

// correction tests
TEST_F(TestFixture, AddNotDigitArgs) {
		// Arrange
		char* string = "aaa";
	
		int res;
		// Act
		res = calc->Add(string);
		// ASSERT
		ASSERT_EQ(res, (int)Calculator::errNotDigitArgs);
		//		ASSERT_FALSE(true);
	}

// correction tests
TEST_F(TestFixture, AddIncorrectDelim) {
	// Arrange
	char* string = "4;2";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
	//		ASSERT_FALSE(true);
}


// correction tests
TEST_F(TestFixture, AddUnclosedDelim) {
	// Arrange
	char* string = "4,";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}


// work normal tests

TEST_F(TestFixture, AddCorrectOne) {
	// Arrange
	char* string = "1";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)1);
	//		ASSERT_FALSE(true);
}

// work normal tests
TEST_F(TestFixture, AddCorrectTwo) {
	// Arrange
	char* string = "2,2";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)4);
	//		ASSERT_FALSE(true);
}

// work normal test
TEST_F(TestFixture, AddCorrect3) {
	// Arrange
	char* string = "1,2,3";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)6);
	//		ASSERT_FALSE(true);
}

// work normal test
TEST_F(TestFixture, AddCorrect4) {
	// Arrange
	char* string = "1,2,3,4";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)10);
	//		ASSERT_FALSE(true);
}


// correction tests

TEST_F(TestFixture, AddDelimNL) {
	// Arrange
	char* string = "1\n";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}

// correction tests

TEST_F(TestFixture, AddDelimNL2) {
	// Arrange
	char* string = "1\n2\n";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}

// work normal test

TEST_F(TestFixture, AddCorrectDelimNL) {
	// Arrange
	char* string = "1\n2\n3";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)6);
	//		ASSERT_FALSE(true);
}

// correction tests
TEST_F(TestFixture, AddDelimNL3) {
	// Arrange
	char* string = "//;\n1-2//|\n3|5,6-7";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// correction tests
TEST_F(TestFixture, AddCorrectSpecitalDelim) {
	// Arrange
	char* string = "//need_end";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// correction tests
TEST_F(TestFixture, AddCorrectSpecitalDelim2) {
	// Arrange
	char* string = "//\n";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// working tests
TEST_F(TestFixture, AddDelimNL4) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//[;]\n1;2//[|]\n3|5,6|7;9";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 33);
}

// Correction tests
TEST_F(TestFixture, ParseSpecialDelimetersTest1) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = NULL;

	std::vector<char*> cd;
	int res;
	// Act
	res = calc->ParseSpecialDelimeters(&string,cd);
	// ASSERT
	ASSERT_EQ(res, Calculator::errUnclosedDelim);
	ASSERT_EQ(cd.size(), 0);
}

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
	ASSERT_EQ(res, Calculator::errIncorrectDelim);
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


// correction tests Non digit arg '-' inside numer
TEST_F(TestFixture, AddNegatives) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "-1-0,-20,-30,5,-4";

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, Calculator::errNotDigitArgs);
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


// Working test 6
TEST_F(TestFixture, AddBigger1000) {
	// Arrange
	char* string = "1001,1003,2,1000,999";
	// 999+1000+2 == 2001

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 2001);
}

// Working test 7
TEST_F(TestFixture, AddBiggerDelim) {
	// Arrange
	char* string = "//[***]\n1***2***3";
	// 6

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Correction test 8
TEST_F(TestFixture, AddBiggerDelim2) {
	// Arrange
	char* string = "//[***][##\n1***2***3";
	// 6

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, Calculator::errUnclosedDelim);
}


// Working 7
TEST_F(TestFixture, AddBiggerDelim3) {
	// Arrange
	char* string = "//[***][##]\n1***2##3";
	// 6

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Working 8
TEST_F(TestFixture, AddBiggerDelim4) {
	// Arrange
	char* string = "//[*][%]\n1*2%3";
	// 6

	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Working 9
TEST_F(TestFixture, AddBiggerDelim9) {
	// Arrange
	char* string = "//[****][%%%]\n1****2%%%3";
	// 6
	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

TEST_F(TestFixture, MyFirstTextFixt1)
{
	char* string = "//[****][%%%]\n1****2%%%3";
	// 6
	int expect = 6;
	int res;
	// Act
	res = calc->Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);

}