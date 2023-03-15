#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // char c1 = 'H';
  // char c2 = 'I';
  // char c3 = '!';

  // printf("%i %i %i\n", c1, c2, c3);

  string s = "HI!";
  string t = "BYE!";

  string words[2];
  words[0] = s;
  words[1] = t;

  printf("%c%c%c\n", words[0][0], words[0][1], words[0]);
  printf("%s\n", words[1]);
}