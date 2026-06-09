#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/helper_funs.h"
#include "../includes/repository.h"

// FUNCTIONS
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int readLine(char *buffer, int size)
{
  if (fgets(buffer, size, stdin) == NULL)
  {
    return 0;
  }

  buffer[strcspn(buffer, "\n")] = '\0';
  return 1;
}

int readInt(int *value)
{
  char temp[32];
  if (!readLine(temp, sizeof(temp)))
  {
    return 0;
  }

  char *endptr;
  long int number = strtol(temp, &endptr, 10);
  if (endptr == temp || *endptr != '\0')
  {
    return 0;
  }

  *value = (int)number;
  return 1;
}
