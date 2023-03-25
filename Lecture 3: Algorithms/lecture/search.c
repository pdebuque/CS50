#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // static array
  // int numbers[] = {20, 500, 10, 5, 100, 1, 50};

  // int n = get_int("Number: ");
  // // linear search
  // for (int i = 0; i < 7; i++)
  // {
  //   if (numbers[i] == n)
  //   {
  //     printf("found \n");
  //     return 0;
  //   }
  // }
  // printf("not found\n");
  // return 1;

  // note: == does not work for string comparison

  string strings[] = {"battleship", "boot", "cannon"};
  string s = get_string("String: ");
  for (int i = 0; i < 3; i++)
  {
    // strcmp is a method from string.h. if the two argument strings are the same, it returns 0. otherwise, returns a positive or negative number, depending on alphabetical comparison
    if (strcmp(strings[i], s) == 0)
    {
      printf("found\n");
      return 0;
    }
  }
  printf("not found\n");
  return 1;

  // segmentation fault: means you tried to access memory you don't have access to
}