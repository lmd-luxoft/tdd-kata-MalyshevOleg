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

TEST(TDDKata, AddNotCorrectOne) {
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
TEST(TDDKata, AddNotCorrectTwo) {
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
TEST(TDDKata, AddNotCorrect3) {
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
TEST(TDDKata, AddNotCorrect4) {
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

