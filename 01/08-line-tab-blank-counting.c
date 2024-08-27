#include <stdio.h>

#define NEW_LINE '\n'
#define TAB '\t'
#define BLANK ' '

int main(void)
{
  int c;
  int count = 0;

  while ((c = getchar()) != EOF)
    if (c == NEW_LINE || c == TAB || c == BLANK)
      ++count;

  printf("%d\n", count);
}