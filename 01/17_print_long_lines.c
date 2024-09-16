#include <stdio.h>

// Define maximum line length and character limits
#define MAX_LINE_LENGTH 1000       // Maximum number of characters per input line
#define MIN_LINE_LENGTH 80         // Minimum line length to consider for storing
#define MAX_TOTAL_CHARACTERS 10000 // Maximum total characters to store in concatenated lines buffer

// Function prototypes
int getLine(char line[], int maxLineLength);
int appendLine(char from[], char to[], int currentLength);

int main(void)
{
  int currentLineLength;                  // Length of the current line being read
  int totalLinesLength = 0;               // Total length of all stored lines
  char line[MAX_LINE_LENGTH];             // Buffer for storing a single line of input
  char storedLines[MAX_TOTAL_CHARACTERS]; // Buffer for storing concatenated lines

  // Read input lines until EOF is encountered
  while ((currentLineLength = getLine(line, MAX_LINE_LENGTH)) > 0)
  {
    // Only store lines longer than the minimum length
    if (currentLineLength > MIN_LINE_LENGTH)
    {
      // Ensure we don't exceed the buffer for storing concatenated lines
      if ((totalLinesLength + currentLineLength) < MAX_TOTAL_CHARACTERS)
      {
        // Append the line to the storedLines buffer and update total length
        int appendedChars = appendLine(line, storedLines, totalLinesLength);
        totalLinesLength += appendedChars;
      }
      else
      {
        // If we exceed the buffer, print an error message and stop adding lines
        printf("Error: Exceeded buffer size. Cannot store more lines.\n");
        break;
      }
    }
  }

  // Output the result
  printf("Stored lines longer than %d characters:\n", MIN_LINE_LENGTH);
  for (int i = 0; i < totalLinesLength; ++i)
  {
    putchar(storedLines[i]);
  }
  putchar('\n');

  return 0;
}

/**
 * Reads a line from input and stores it in the line[] array.
 * Stops reading at EOF, newline, or when maxLineLength is reached.
 * Returns the length of the line read.
 */
int getLine(char line[], int maxLineLength)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxLineLength - 1; ++i)
  {
    line[i] = c;
  }

  // If a newline character is read, include it in the line
  if (c == '\n' && i < maxLineLength - 1)
  {
    line[i] = '\n';
    ++i;
  }

  // Null-terminate the string
  line[i] = '\0';

  return i; // Return the length of the line
}

/**
 * Appends a line from the `from[]` array to the `to[]` array starting at position toLength.
 * Returns the number of characters added.
 */
int appendLine(char from[], char to[], int currentLength)
{
  int i = 0;

  // Copy characters from 'from' to 'to', starting at currentLength in 'to'
  while (from[i] != '\0')
  {
    to[currentLength + i] = from[i];
    ++i;
  }

  return i; // Return the number of characters appended
}
