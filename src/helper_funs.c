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

int selectContact(int userChoiceForSelection)
{
  int selectedContactIndex;
  switch (userChoiceForSelection)
  {
  case SELECT_BY_ID:
    int selectMenuUserId;
    printf(ANSI_COLOR_GREEN "Enter the User Id: " ANSI_COLOR_RESET);
    if (!readInt(&selectMenuUserId))
    {
      selectMenuUserId = -1;
    }

    selectedContactIndex = findContactIndexById(selectMenuUserId);
    return selectedContactIndex;

    break;
  case SELECT_BY_NAME:
    char selectMenuUserName[CONTACT_NAME_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Name: " ANSI_COLOR_RESET);
    readLine(selectMenuUserName, sizeof(selectMenuUserName));

    selectedContactIndex = findContactIndexByName(selectMenuUserName);
    return selectedContactIndex;

    break;
  case SELECT_BY_PHONE:
    char selectMenuUserPhone[CONTACT_PHONE_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Phone Number: " ANSI_COLOR_RESET);
    readLine(selectMenuUserPhone, sizeof(selectMenuUserPhone));

    selectedContactIndex = findContactIndexByPhone(selectMenuUserPhone);
    return selectedContactIndex;

    break;
  case SELECT_BY_ADDRESS:
    char selectMenuUserAddress[CONTACT_ADDRESS_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Address: " ANSI_COLOR_RESET);
    readLine(selectMenuUserAddress, sizeof(selectMenuUserAddress));

    selectedContactIndex = findContactIndexByAddress(selectMenuUserAddress);
    return selectedContactIndex;

    break;
  case SELECT_BY_E_MAIL:
    char selectMenuUserEmail[CONTACT_EMAIL_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Email: " ANSI_COLOR_RESET);
    readLine(selectMenuUserEmail, sizeof(selectMenuUserEmail));

    selectedContactIndex = findContactIndexByEmail(selectMenuUserEmail);
    return selectedContactIndex;

    break;
  default:
    printf(ANSI_COLOR_RED"No Contact Found :("ANSI_COLOR_RESET);
    return -1;
    break;
  }
}
