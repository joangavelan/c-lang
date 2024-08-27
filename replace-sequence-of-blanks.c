#include <stdio.h>

#define BLANK ' '

int main(void)
{
  int current, prev;

  while ((current = getchar()) != EOF)
  {
    if (current != BLANK || current != prev)
      putchar(current);

    prev = current;
  }
}