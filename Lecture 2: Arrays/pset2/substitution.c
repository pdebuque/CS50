// substitution cipher

/*
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```
 */

// argv[1] is the key: in above, the plaintext letter A should become ciphertext J, etc.

#include <assert.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string ALPHABET_L = "abcdefghijklmnopqrstuvwxyz";

int check_key(string key);
char convert_char(char letter, string key);
string toupper_string(string input);
string tolower_string(string input);

int main(int argc, string argv[])
{

  //* ======== check inputs =========
  if (argc < 2)
  {
    printf("no argument given\n");
    return 1;
  }

  char key[26];

  for (int i = 0, len = strlen(argv[1]); i < len; i++)
  {
    key[i] = toupper(argv[1][i]);
  }

  // printf("%i\n", check_key(key));

  if (check_key(key) != 0)
  {
    printf("invalid: ");
    switch (check_key(key))
    {
    case 1:
      printf("key must be 26 letters long\n");
    case 2:
      printf("key must be alphabetical\n");
    case 3:
      printf("key must contain all letters\n");
    }
    return 1;
  }

  //* ======== main functionality ==========

  // get text input from user
  string text = get_string("plaintext: ");

  // convert text by looping through input, converting each character, and pushing the correct letter into the output
  char output[strlen(text)];

  for (int i = 0, len = strlen(text); i < len; i++)
  {
    output[i] = convert_char(text[i], key);
  }

  // print output and return 0

  printf("ciphertext: %s\n", output);
  return 0;
}

// check the user-input key
int check_key(string key)
{
  // must be exactly 26 characters
  if (strlen(key) != 27)
    return 1;
  // return "key must be 26 letters long";

  for (int i = 0; i < 26; i++)
  {
    // check alphabetic
    if (!isalpha(key[i]))
      return 2;
    // return "key must be alphabetical";
    // check if any element of the alphabet is missing from the key
    if (!strchr(key, ALPHABET[i]))
      return 3;
    // return "key must contain all letters";
    // printf("%s\n", strchr(key, ALPHABET[i]));
  }
  // return "valid key";
  return 0;
  // can only have alphabetic characters
  // must have each letter only once
}

char convert_char(char letter, string key)
{
  string alpha;
  string case_key;
  int index;
  // determine type,
  if (isalpha(letter))
  {
    if (isupper(letter))
    {
      alpha = ALPHABET;
      case_key = toupper_string(key);
    }
    else
    {
      alpha = ALPHABET_L;
      case_key = tolower_string(key);
    }
  }
  else
    return letter;

  // find the position of the letter in the alphabet
  for (int i = 0; i < 26; i++)
  {
    if (alpha[i] == letter)
    {
      index = i;
    }
  }

  // return the key at that index

  return case_key[index];
}

string toupper_string(string input)
{
  int length = strlen(input);
  char output[length];
  for (int i = 0; i < length; i++)
  {
    output[i] = toupper(input[i]);
  }
  return output;
}

string tolower_string(string input)
{
  int length = strlen(input);
  char output[length];
  for (int i = 0; i < length; i++)
  {
    output[i] = tolower(input[i]);
  }
  return output;
}