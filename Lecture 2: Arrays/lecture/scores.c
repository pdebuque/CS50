#include <stdio.h>
#include <cs50.h>

const int N = 3;

float average(int length, int scores[]);

int main(void)
{
  //   int score1 = 72;
  //   int score2 = 73;
  //   int score3 = 33;

  //   // printf("Average: %i\n", (score1+score2+score3)/3);

  //   // to see as a float:

  //   // printf("Average: %f\n", (score1+score2+score3)/3.0);

  //   // OR
  //   printf("Average: %f\n", (score1+score2+score3)/(float)3);

  //* using an array

  int scores[N];

  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("score #%i: ", i+1);
  }

  printf("Average: %f\n", average(N, scores));
}

float average(int length, int scores[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += scores[i];
  }
  return sum / (float)length;
}