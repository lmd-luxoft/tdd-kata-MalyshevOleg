#pragma once
#include <string>
/// <summary>
/// Class Under test
/// </summary>
class Calculator
{
	const char* spec_delim_start = "//";
	const char* spec_delim_end = "\n";

public:
	enum {stateNormal=0,stateSpecDelim};
	enum {errEmpty=-1,errNotDigitArgs=-3,errIncorrectDelim=-4,errEnclosedDelim=-5};
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(char* expression);
	char* ParseSpecialDelimeters(char** cur_token);
};

