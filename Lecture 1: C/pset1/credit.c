#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <math.h>

int get_digit(long num, int digit);

int main(void)
{
  long num;

  do
  {
    num = get_long("number: ");
  } while (num > 9999999999999999 || num < 1000000000000);

  int digit_ind;

  do
  {
    digit_ind = get_int("digit: ");
  } while (digit_ind>16);

  int digit = get_digit(num, digit_ind);

  printf("digit is %i\n", digit);
}

int get_last(long num)
{
  return num % 10;
}
// digit = 1 => 1s; 2=> 10s, etc.
int get_digit(long num, int digit)
{
  long num_rec = num;
  int index = 1;
  // recursive formula: here is for the 1s
  while (index < digit)
  {
    int last = get_last(num_rec);
    num_rec = (num_rec - last) / 10;
    index++;
  }
  return num_rec % 10;
}

// bool checksum(long card)
// {
// }