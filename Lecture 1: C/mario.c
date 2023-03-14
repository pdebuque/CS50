#include <stdio.h>
#include <cs50.h>

int get_size(void); // tells compiler that the functions exist later
void print_grid(int size);

int main(void)
{
  // const protects the variable from changing
  // const int j = get_int("how many ?s ");
  // for (int i = 0; i < j; i++)
  // {
  //   printf("?");
  // }
  // printf("\n");

  // const int k = get_int("how tall? ");
  // for (int i = 0; i < k; i++)
  // {
  //   printf("#\n");
  // }

  // do while loop
  // get size of grid
  // int n;
  // do
  // {
  //   n = get_int("size: ");
  //   /* code */
  // } while (n < 1);

  // // print grid of bricks
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     printf("# ");
  //   }
  //   printf("\n");
  // }

//* ABSTRACTION

  // get size of grid
  int n = get_size();

  // print grid
  print_grid(n);
}

int get_size(void) // returns an int, takes no inputs
{
  int n;
  do
  {
    n = get_int("Size: ");
  } while (n < 1);
  return n;
}

void print_grid(int size)
{
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      printf("# ");
    }
    printf("\n");
  }
}