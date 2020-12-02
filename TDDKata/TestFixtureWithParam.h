#pragma once
#include "TextFixture.h"


struct Param
{
    char* param;
    int result;
    Param(char* op, int expe) {
        param = op;
        result = exp;
    }

};

class TestFixtureWithParam :
    public TestFixture
{

};

