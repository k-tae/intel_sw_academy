// C++ 표준 console 출력

#include <iostream>
#include <cstdio>
#include "driver.h"
using namespace std;

extern "C" int c_add_sqr(int a, int b);

extern "C" int cpp_sqr(int a)
{
	return a * a;
}

int main()
{
	cout << c_add_sqr(3, 5) << endl;
	cout << driver_sub(3, 5) << endl;
}
