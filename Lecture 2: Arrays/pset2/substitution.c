// substitution cipher

/*
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```
 */

// argv[1] is the key: in above, the plaintext letter A should become ciphertext J, etc.

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int check_key(string key);

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

  if (check_key(key)!=0)
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

  // if (!check_key(key))
  // {
  //   printf("invalid key");
  //   return 1;
  // }

  // string text = get_string("plaintext: ");
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