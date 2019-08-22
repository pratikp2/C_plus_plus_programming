#include "UseCases.h"

Test3::Test3()
{
	var1 = 10;
	var2 = "Hello";
	var3 = 20;
}

Nested_Case::Nested_Case()
{
	var1 = 30;
	var2 = "World";
	var3 = 40;
}

void Nested_Case::printData()
{
}

FunctionSpilt_Case::FunctionSpilt_Case()
{
	var1 = 50;
	var2 = "FunctionSpilt_Case";
	var3 = 60;
}

NonIntrusive_Case::NonIntrusive_Case()
{
	var1 = 70;
	var2 = "NonIntrusive_Case";
	var3 = 80;
}