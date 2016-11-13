#include "inline.h"

constexpr int new_sz()
{
	return 42;
}
constexpr size_t scale(size_t cnt)
{
	return new_sz() * cnt;
}
int app()
{
	int b = 2;
	int a[scale(2)];
	return b;
}