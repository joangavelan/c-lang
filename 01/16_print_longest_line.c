#include <stdio.h>

#define MAXLINE 6 // // Allow 5 characters + '\0' for null-terminated strings

// Function to read a line of input and return its length
int getLine(char line[], int maxLine)
{
  int c, i, strEnd;

  strEnd = 0;

  // Loop through each character until EOF or newline is encountered
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    // Store the character only if it fits in the array
    if (i < maxLine - 1)
    {
      line[i] = c;    // Store the character in the array
      strEnd = i + 1; // Keep track of the last position for terminating the string with '\0'
    }
  }

  // If a newline character is encountered, store it as part of the string
  if (c == '\n' && strEnd < maxLine - 1)
  {
    line[strEnd] = c; // Add the newline character to the array
    ++i;              // Move to the next index to continue the count of the line length
    ++strEnd;
  }

  line[strEnd] = '\0'; // Null-terminate the string to ensure it can be printed correctly

  return i; // Return the length of the line (could be longer than the array size)
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

  // After processing all lines, print the longest line found
  printf("Longest line: %s\n", longest);
  printf("Actual length: %d\n", max); // Print the actual length of the longest line (even if truncated)

  return 0; // Exit the program successfully
}
