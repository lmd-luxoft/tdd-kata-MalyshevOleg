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
	ASSERT_EQ(res, (int)Calculator::errEnclosedDelim);
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
	ASSERT_EQ(res, (int)Calculator::errEnclosedDelim);
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
	ASSERT_EQ(res, (int)Calculator::errEnclosedDelim);
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
	ASSERT_EQ(res, (int)Calculator::errEnclosedDelim);
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
	ASSERT_EQ(res, (int)Calculator::errEnclosedDelim);
}


// working tests
TEST(TDDKata, AddDelimNL4) {
	// Arrange
	// res= 1+2+3+5+6+7+9 = 33
	char* string = "//;\n1;2//|\n3|5,6|7;9";
	Calculator calc;
	int res;
	// Act
	res = calc.Add(string);
	// ASSERT
	ASSERT_EQ(res, 33);
}
