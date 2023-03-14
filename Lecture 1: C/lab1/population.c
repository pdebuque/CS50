#include <stdio.h>
#include <cs50.h>

/* 
Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away. At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.

To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas. We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born. 1000 / 4 = 250 llamas will pass away, so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.
 */

int calc_years(int start, int end);
int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("start size? ");
    } while (start<9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("end size? ");
    } while (end<start);

    // TODO: Calculate number of years until we reach threshold
    int years = calc_years(start,end);

    // TODO: Print number of years
    printf("years: %i\n", years);
}

int calc_years(int start, int end)
{
    int current = start;
    int years = 0;
    while (current<end)
    {
        current = current+ current/3 - current/4;
        years++;
    }
    return years;
}