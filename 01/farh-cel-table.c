#include <stdio.h>

#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20   /* step size */

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
  printf("%3s %6s\n", "Fahr", "Celsius");

  for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }

  // float fahr, celsius;
  // int lower, upper, step;

  // lower = 0;   /* lower limit of temperature table*/
  // upper = 300; /* upper limit */
  // step = 20;   /* step size */

  // fahr = lower;

  // printf("%3s %6s\n", "Fahr", "Celsius");

  // while (fahr <= upper)
  // {
  //   celsius = (5.0 / 9.0) * (fahr - 32.0);
  //   printf("%3.0f %6.1f\n", fahr, celsius);
  //   fahr = fahr + step;
  // }
}

/* print Fahrenheit-Celcius table
for fahr = 0, 20, ..., 300 */
// int main()
// {
//   int fahr, celsius;
//   int lower, upper, step;

//   lower = 0;   /* lower limit of temperature table */
//   upper = 300; /* upper limit */
//   step = 20;   /* step size */

//   fahr = lower;

//   while (fahr <= upper)
//   {
//     celsius = 5 * (fahr - 32) / 9;
//     printf("%3d\t%6d\n", fahr, celsius);
//     fahr = fahr + step;
//   }
// }
