#include <stdio.h>

#define MAXLINE 1000 // Maximum number of characters in a line

// Function to read a line of input and return its length
int getLine(char line[], int maxLine)
{
  int c, i;

  // Read each character from input until EOF, newline, or array limit is reached
  for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxLine - 1; ++i)
  {
    line[i] = c; // Store the character in the array
  }

  // If a newline is encountered, store it in the array
  if (c == '\n')
  {
    line[i] = c; // Add the newline character to the array
    ++i;         // Move to the next index
  }

  line[i] = '\0'; // Terminate the string with the null character

  return i; // Return the length of the line
}

// Function to copy one string to another
void copyLine(char from[], char to[])
{
  int i = 0;

  // Copy each character from 'from[]' to 'to[]' until the null character is found
  while ((to[i] = from[i]) != '\0')
  {
    ++i; // Move to the next character
  }
}

int main(void)
{
  int len;               // Current line length
  int max = 0;           // Maximum length of lines encountered
  char line[MAXLINE];    // Array to store the current input line
  char longest[MAXLINE]; // Array to store the longest line

  // Continue reading lines until the end of the input (EOF)
  while ((len = getLine(line, MAXLINE)) > 0)
  {
    // If the current line is longer than the longest one encountered so far
    if (len > max)
    {
      max = len;               // Update the maximum length
      copyLine(line, longest); // Copy the current line to 'longest'
    }
  }

  // After all lines are processed, print the longest line
  printf("Longest line: %s", longest);

  return 0; // Exit the program
}
