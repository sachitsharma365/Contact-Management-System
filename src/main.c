#include <stdio.h>
#include "../includes/repository.h"

typedef enum
{
  ADD_CONTACT = 1,
  VIEW_CONTACTS,
  DELETE_CONTACT,
  UPDATE_CONTACT,
  SEARCH_CONTACT,
  EXPORT_CONTACTS,
  IMPORT_CONTACTS,
  EXIT_APPLICATION
} MENU_OPTIONS;

int menu()
{
  int userInput;

  printf("Welcome to the Contact Management System.\nChoose any option from below and enter the respective number.\n");
  printf("1. Add Contact\n"
         "2. View Contacts\n"
         "3. Delete Contact\n"
         "4. Update Contact\n"
         "5. Search Contact\n"
         "6. Export Contacts\n"
         "7. Import Contacts\n"
         "8. Exit Application\n");

  printf("> ");
  scanf("%d", &userInput);

  return userInput;
}

int main()
{

  while (1)
  {
    int userChoice = menu();

    switch (userChoice)
    {
    case ADD_CONTACT:
      printf("Calling Add Contact...\n");
      break;
    case VIEW_CONTACTS:
      printf("Calling View Contacts...\n");
      break;
    case DELETE_CONTACT:
      printf("Calling Delete Contact...\n");
      break;
    case UPDATE_CONTACT:
      printf("Calling Update Contact...\n");
      break;
    case SEARCH_CONTACT:
      printf("Calling Seach Contact...\n");
      break;
    case EXPORT_CONTACTS:
      printf("Calling Export Contacts...\n");
      break;
    case IMPORT_CONTACTS:
      printf("Calling Import Contacts...\n");
      break;
    case EXIT_APPLICATION:
      break;
    default:
      printf("The function is not build yet :(\n");
      break;
    }

    if (userChoice == EXIT_APPLICATION)
    {
      break;
    }
  }

  return 0;
}