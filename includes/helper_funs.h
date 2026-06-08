#ifndef HELPER_FUNS_H
#define HELPER_FUNS_H

// COLOR MACROS
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_RESET   "\033[0m"

// FUNCTIONS
void clearInputBuffer();
int readLine(char *buffer, int size);
int readInt(int *value);

#endif