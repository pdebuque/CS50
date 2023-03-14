#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  int height;
  do
  {
    height = get_int("height: ");
  } while (height < 1 || height>8);

  // each row
  for (int i = 0; i < height; i++)
  {
    // construct the pattern of lines and spaces. two for loops run consecutively

    // first loop creates left side
    for (int j = 0; j < height; j++)
    {
      if (i + j < height - 1)
      {
        printf(" ");
      }
      else
      {
        printf("#");
      }
    }
    printf(" ");

    // second loop creates right side
    for (int j = 0; j < height; j++)
    {
      if (j<=i)
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }

    printf("\n");
  }
}