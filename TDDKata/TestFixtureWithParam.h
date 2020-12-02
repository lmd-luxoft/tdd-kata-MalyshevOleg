#pragma once
#include "pch.h"
#include "TestFixture.h"


struct Param
{
    const char* param;
    int expected;
    Param(const char* op, int expe) :param(op), expected(expe) {}
};

class TestFixtureWithParam :   public TestFixture, public ::testing::WithParamInterface<Param>
{

};

