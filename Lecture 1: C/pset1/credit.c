#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <math.h>

int get_digit(long num, int digit);
int get_sum(long num);
char check_card(long num);

int main(void)
{
  // get credit card number
  long num;
  do
  {
    num = get_long("number: ");
  } while (num > 9999999999999999 || num < 1000000000000);

  // check for valid sum
  // bool sum = check_sum(num);

  printf("Luhn's sum: %i\n", get_sum(num));

  if (get_sum(num) % 10 == 0)
  {
    // check card type
    printf("card type: %c\n", check_card(num));
  }
  else
  {
    printf("INVALID");
  }
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

int get_length(long x)
{
  if (x >= 1000000000000000)
    return 16;
  if (x >= 100000000000000)
    return 15;
  if (x >= 10000000000000)
    return 14;
  if (x >= 1000000000000)
    return 13;
  if (x >= 100000000000)
    return 12;
  if (x >= 10000000000)
    return 11;
  if (x >= 1000000000)
    return 10;
  if (x >= 100000000)
    return 9;
  if (x >= 10000000)
    return 8;
  if (x >= 1000000)
    return 7;
  if (x >= 100000)
    return 6;
  if (x >= 10000)
    return 5;
  if (x >= 1000)
    return 4;
  if (x >= 100)
    return 3;
  if (x >= 10)
    return 2;
  return 1;
}

int get_sum(long num)
{
  long sum = 0;
  for (int i = 1; i <= get_length(num); i++)
  {
    if (i % 2 == 1)
    {
      sum += get_digit(num, i);
      // printf("odd digit: %i. sum: %ld\n", get_digit(num,i), sum);
    }
    else
    {
      long intermediate = 2 * (get_digit(num, i));
      int dig_sum = 0;
      for (int i = 1; i <= get_length(intermediate); i++)
      {
        dig_sum += get_digit(intermediate, i);
      }
      sum += dig_sum;
      // printf("even digit: %i. sum of digits: %i. sum: %ld\n", get_digit(num,i), dig_sum, sum);
    }
  }
  return sum;
}

char check_card(long num)
{
  int length = get_length(num);

  if (length == 16)
  { // visa 16 digit
    if (get_digit(num, length) == 4)
    {
      return 'v';
    }
    // mastercard
    if (get_digit(num, length) == 5 && get_digit(num, length - 1) == 1 | 2 | 3 | 4 | 5)
    {
      return 'm';
    }
    else
      return 'i';
  }
  // amex
  else if (length == 15)
  {
    if (get_digit(num, length) == 3 && (get_digit(num, length - 1) == 4 || get_digit(num, length - 1) == 7))
    {
      return 'a';
    }
    else
      return 'i';
  }
  // visa 13 digit
  else if (length == 13)
  {
    if (get_digit(num,length)==4)
    {
      return 'v';
    }
    else return 'i';
  }
  else return 'i';
}

// bool checksum(long card)
// {
// }