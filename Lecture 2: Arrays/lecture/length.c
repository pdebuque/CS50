// determine the length of a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string name = get_string("What's your name? ");

  int n = strlen(name); // using string.h library
  // int n=0;
  // while (name[n]!='\0')
  // {
  //   n++;
  // }
  printf("length: %i\n", n);
}