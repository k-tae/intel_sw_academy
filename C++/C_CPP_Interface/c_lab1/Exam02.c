#include "driver.h"

extern int cpp_sqr(int a);

int c_add_sqr(int a, int b)
{
	return cpp_sqr(a) + cpp_sqr(b);
}
