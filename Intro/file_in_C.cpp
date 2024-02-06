// C Program to demonstrate fscanf
#include <stdio.h>

// Driver Code
int main()
{
  FILE* in = fopen("input.txt", "r");
  FILE* out = fopen("output.txt", "w");
  if (in == NULL) {
    printf("no such file.");
    return 0;
  }

  /* Assuming that abc.txt has content in below
  format
  NAME AGE CITY
  abc  12 hyderabad
  bef  25 delhi
  cce  65 bangalore */
  char name[100], age[100], city[100];
  int cnt = 0;
  while (fscanf(in, "%s %s %s", name, age, city) != EOF)
    fprintf(out, "%d %s %s %s\n", ++cnt, age, name, city);

  // while(fgets(name, 100, in) != NULL)
  //   fprintf(out, "%s", name);


  return 0;
}
