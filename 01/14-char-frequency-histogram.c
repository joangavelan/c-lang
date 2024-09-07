#include <stdio.h>

#define ASCII_LENGTH 128

/*
 * This program reads input characters and counts their frequency.
 * It then prints a histogram using '#' symbols for each character
 * that appears, based on its occurrence count. The program works
 * with the first 128 ASCII characters.
 */
int main(void)
{
  int input_char;
  int char_frequencies[ASCII_LENGTH];
  int ascii_code;

  // Initialize the frequency array to zero
  for (ascii_code = 0; ascii_code < ASCII_LENGTH; ++ascii_code)
    char_frequencies[ascii_code] = 0;

  while ((input_char = getchar()) != EOF)
  {
    if (input_char < ASCII_LENGTH) // Ensure within valid ASCII range
      ++char_frequencies[input_char];
  }

  // Print the histogram for characters that occurred at least once
  for (ascii_code = 0; ascii_code < ASCII_LENGTH; ++ascii_code)
  {
    if (char_frequencies[ascii_code] >= 1)
    {
      printf("%c: ", ascii_code);

      for (int count = 1; count <= char_frequencies[ascii_code]; ++count)
        putchar('#');

      putchar('\n');
    }
  }
}