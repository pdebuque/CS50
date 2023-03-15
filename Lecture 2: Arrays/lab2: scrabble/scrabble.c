// goal: determine the point value of two scrabble words and find the winner

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calc_score(string word);

int main(void)
{
  // get words from client
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // calculate each word's respective score
  int score1 = calc_score(word1);
  int score2 = calc_score(word2);

  // compare and print accordingly
  if (score1 > score2)
  {
    printf("Player 1 wins!\n");
  }
  else if (score2 > score1)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("It's a tie!\n");
  }
}

int score_letter(char letter)
{
  if (!isalpha(letter))
  {
    return 0;
  }

  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string scores = "1332142418513113t11114484t";

  char letter_low = tolower(letter);
  int ind;

  for (int i = 0; i < 26; i++)
  {
    if (letter_low == alphabet[i])
    {
      ind = i;
    }
  }
  return scores[ind];
}

int calc_score(string word)
{
  int sum = 0;

  // loop through string

  for (int i = 0, length = strlen(word); i < length; i++)
  {
    sum += score_letter(word[i]);
  }
  return sum;
}
