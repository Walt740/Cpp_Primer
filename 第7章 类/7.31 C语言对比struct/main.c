#include <stdio.h>
#include <stdlib.h>

struct B;
struct A
{
  struct  B b;
};
struct B
{
  struct  A a;
};


int main()
{
    printf("Hello world!\n");
    return 0;
}
