#include <stdio.h>

#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20   /* step size */

float fahrToCel(float fahr);

int main()
{
  printf("%3s %6s\n", "Fahr", "Celsius");

  for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  {
    printf("%3d %6.1f\n", fahr, fahrToCel(fahr));
  }
}

float fahrToCel(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}