#pragma once
#include <string>
/// <summary>
/// Class Under test
/// </summary>
class Calculator
{
public:
	enum {errEmpty=-1,errTooManyArgs=-2,errNotDigitArgs=-3,errIncorrectDelim=-4,errEnclosedDelim=-5};
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(char* expression);
};

