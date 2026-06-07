#include <stdio.h>
#include "../includes/helper_funs.h"

// FUNCTIONS
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}