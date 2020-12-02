#include "pch.h"
#include "TextFixture.h"


void TextFixture::SetUp()
{
		calc = new Calculator();
}
void TextFixture::TearDown()
{
		delete calc;
}