#include <cs50.h>
#include <stdio.h>
#include <string.h>

//* better: instead of using arrays, create new data type

typedef struct
{
  string name;
  string number;
} person;

int main(void)
{
  //! this is a hacky approach: what happens if we need to add people and numbers?

  // // array of names for the phonebook
  // string names[] = {"Carter", "David"};
  // // to relate numbers to names, make an array with matching indices
  // string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
  // string name = get_string("Name: ");

  // for (int i = 0; i < 2; i++)
  // {
  //   if (strcmp(names[i], name) == 0)
  //   {
  //     printf("Found %s\n", numbers[i]);
  //     return 0;
  //   }
  // }
  // printf("Not found\n");
  // return 1;

  //* better
string name = get_string("Name: ");

  person people[2];
  people[0].name = "Carter";
  people[0].number = "+1-617-495-1000";

  people[1].name = "David";
  people[1].number = "+1-949-468-2750";

for (int i =0; i<2; i++)
{
  if (strcmp(name, people[i].name)==0)
  {
    printf("Found %s\n", people[i].number);
    return 0;
  }
}
printf("Not found\n");
return 1;

}