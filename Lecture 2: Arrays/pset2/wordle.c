

#include <assert.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

  //* ======== check inputs =========

  if (argc != 2)
  {
    printf("Usage: ./words {wordsize}\n");
    return 1;
  }

  long word_size;
  char *remaining;
  word_size = strtol(argv[1], &remaining, 10);
  int guesses = word_size+1;

  if (word_size < 5 || word_size > 8)
  {
    printf("Error: wordsize must be 5, 6, 7, or 8\n");
    return 2;
  }

  //* ============= BEGIN GAME ===============
  printf("This is WORDLE50\n");
  printf("You have %i tries to guess the %ld-letter word I'm thinking of.\n", guesses, word_size);

  string guess;
  do
  {
    guess = get_string("Input a %ld-letter word: ", word_size);
  } while (strlen(guess) != word_size);

  printf("%s\n", guess);
}