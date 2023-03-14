#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int x = get_int("x: ");
  int y = get_int("y: ");

  printf("x + y = %i\n", x + y);
  // this will not work for large numbers bc of limitations of int data type
  // int is limited to approx +- 2 billion

  long a = get_long("a: ");
  long b = get_long("b: ");

  printf("a+b = %li\n", a + b);
  // long is limited to +- 9 quintillion

  // truncation
  long c = get_long("c: ");
  long d = get_long("d: ");

  // float z = c / d; // this doesn't work - need typecasting to change types

  double z = (double)c /(double)d;

  printf("c/d = %.20f\n", z); // %.20f: 20 digits after zero. this will expose floating point imprecision

  // double vs. float will have greater precision
}