#include "pch.h"

// correction test
TEST(TDDKata, AddEmpyString) {
	// Arrange
		char * empty = "";
		Calculator calc;
		int res;
	// Act
		res=calc.Add(empty);
	// ASSERT
		ASSERT_EQ(res, (int)Calculator::errEmpty);
	}

// correction tests
TEST(TDDKata, AddNotDigitArgs) {
		// Arrange
		char* string = "aaa";
		Calculator calc;
		int res;
		// Act
		res = calc.Add(string);
		// ASSERT
		ASSERT_EQ(res, (int)Calculator::errNotDigitArgs);
		//		ASSERT_FALSE(true);
	}

// correction tests
TEST(TDDKata, AddIncorrectDelim) {
	// Arrange
	char* string = "4;2";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
	//		ASSERT_FALSE(true);
}


// correction tests
TEST(TDDKata, AddUnclosedDelim) {
	// Arrange
	char* string = "4,";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}


// work normal tests

TEST(TDDKata, AddCorrectOne) {
	// Arrange
	char* string = "1";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)1);
	//		ASSERT_FALSE(true);
}

// work normal tests
TEST(TDDKata, AddCorrectTwo) {
	// Arrange
	char* string = "2,2";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)4);
	//		ASSERT_FALSE(true);
}

// work normal test
TEST(TDDKata, AddCorrect3) {
	// Arrange
	char* string = "1,2,3";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)6);
	//		ASSERT_FALSE(true);
}

// work normal test
TEST(TDDKata, AddCorrect4) {
	// Arrange
	char* string = "1,2,3,4";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)10);
	//		ASSERT_FALSE(true);
}


// correction tests

TEST(TDDKata, AddDelimNL) {
	// Arrange
	char* string = "1\n";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}

// correction tests

TEST(TDDKata, AddDelimNL2) {
	// Arrange
	char* string = "1\n2\n";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errUnclosedDelim);
	//		ASSERT_FALSE(true);
}

// work normal test

TEST(TDDKata, AddCorrectDelimNL) {
	// Arrange
	char* string = "1\n2\n3";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)6);
	//		ASSERT_FALSE(true);
}

// correction tests
TEST(TDDKata, AddDelimNL3) {
	// Arrange
	char* string = "//;\n1-2//|\n3|5,6-7";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// correction tests
TEST(TDDKata, AddCorrectSpecitalDelim) {
	// Arrange
	char* string = "//need_end";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// correction tests
TEST(TDDKata, AddCorrectSpecitalDelim2) {
	// Arrange
	char* string = "//\n";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, (int)Calculator::errIncorrectDelim);
}


// working tests
TEST(TDDKata, AddDelimNL4) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//[;]\n1;2//[|]\n3|5,6|7;9";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 33);
}

// Correction tests
TEST(TDDKata, ParseSpecialDelimetersTest1) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = NULL;
	Calculator calc;
	std::vector<char*> cd;
	int res;
	// Act
	res = calc.ParseSpecialDelimeters(&string,cd);
	// ASSERT
	ASSERT_EQ(res, Calculator::errUnclosedDelim);
	ASSERT_EQ(cd.size(), 0);
}

// Correction tests
TEST(TDDKata, ParseSpecialDelimetersTest2) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//---";
	Calculator calc;
	std::vector<char*> cd;
	int res;
	// Act
	res = calc.ParseSpecialDelimeters(&string, cd);
	// ASSERT
	ASSERT_EQ(res, Calculator::errIncorrectDelim);
	ASSERT_EQ(cd.size(), 0);
}

// Works normal
TEST(TDDKata, ParseSpecialDelimetersTest3) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//[;]\n";
	Calculator calc;
	std::vector<char*> cd;
	int res;
	// Act
	res = calc.ParseSpecialDelimeters(&string, cd);
	int res1 = 1;
	if(cd.size()>0)
		res1 = strcmp(";", cd[0]);
	// ASSERT
	ASSERT_EQ(res, 0);
	ASSERT_EQ(cd.size(), 1);
	ASSERT_EQ(res1,0);
}


// correction tests Non digit arg '-' inside numer
TEST(TDDKata, AddNegatives) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "-1-0,-20,-30,5,-4";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, Calculator::errNotDigitArgs);
}

// Working test
TEST(TDDKata, AddNegatives2) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "-10,-20";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	int res1 = strcmp("Negatives not allowed:-10|-20|", calc.message);
	// ASSERT
	ASSERT_EQ(res, Calculator::errException);
	ASSERT_EQ(res1, 0);
}


// Working test 6
TEST(TDDKata, AddBigger1000) {
	// Arrange
	char* string = "1001,1003,2,1000,999";
	// 999+1000+2 == 2001
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 2001);
}

// Working test 7
TEST(TDDKata, AddBiggerDelim) {
	// Arrange
	char* string = "//[***]\n1***2***3";
	// 6
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Correction test 8
TEST(TDDKata, AddBiggerDelim2) {
	// Arrange
	char* string = "//[***][##\n1***2***3";
	// 6
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, Calculator::errUnclosedDelim);
}


// Working 7
TEST(TDDKata, AddBiggerDelim3) {
	// Arrange
	char* string = "//[***][##]\n1***2##3";
	// 6
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Working 8
TEST(TDDKata, AddBiggerDelim4) {
	// Arrange
	char* string = "//[*][%]\n1*2%3";
	// 6
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}

// Working 9
TEST(TDDKata, AddBiggerDelim9) {
	// Arrange
	char* string = "//[****][%%%]\n1****2%%%3";
	// 6
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 6);
}
