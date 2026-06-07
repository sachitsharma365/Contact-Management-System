#include <stdio.h>
#include "../includes/repository.h"


// HELPER FUNCTIONS
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}


// COLOR MACROS
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_RESET   "\033[0m"


// DEFINING ENUMERATORS
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

typedef enum
{
  SEARCH_BY_ID = 1,
  SEARCH_BY_NAME,
  SEARCH_BY_PHONE,
  SEARCH_BY_ADDRESS,
  SEARCH_BY_E_MAIL,
} SEARCH_MENU_OPTIONS;


// MENU FUNCTIONS
int menu()
{
  int userInput;

  printf(ANSI_COLOR_BLUE"\nWelcome to the Contact Management System.\nChoose any option from below and enter the respective number.\n");
  printf("1. Add Contact\n"
         "2. View Contacts\n"
         "3. Delete Contact\n"
         "4. Update Contact\n"
         "5. Search Contact\n"
         "6. Export Contacts\n"
         "7. Import Contacts\n"
         "8. Exit Application\n" ANSI_COLOR_RESET);

  printf("> ");
  scanf("%d", &userInput);

  clearInputBuffer();

  return userInput;
}

void searchMenu()
{
  int searchMenuUserChoice;

  printf(ANSI_COLOR_BLUE"\nSelect one option by which you want to search the contact:-\n");
  printf("1. Search By Id\n"
         "2. Search By Name\n"
         "3. Search By Phone No.\n"
         "4. Search By Address\n"
         "5. Search By E-mail\n" ANSI_COLOR_RESET);

  printf("> ");
  scanf("%d", &searchMenuUserChoice);
  clearInputBuffer();

  switch (searchMenuUserChoice)
  {
  case SEARCH_BY_ID:
    int searchMenuUserId;
    printf("Enter the User Id you want to search for: ");
    scanf("%d", &searchMenuUserId);
    clearInputBuffer();
    int searchByIdReturnValue = searchContactById(searchMenuUserId);
    if (searchByIdReturnValue != 1)
    {
      printf(ANSI_COLOR_RED"\nNo Contact found by such Id :(\n"ANSI_COLOR_RESET);
    }

    break;
  case SEARCH_BY_NAME:
    printf("Calling Search By Name...\n");
    break;
  case SEARCH_BY_PHONE:
    printf("Calling Search By Phone No....\n");
    break;
  case SEARCH_BY_ADDRESS:
    printf("Calling Search By Address...\n");
    break;
  case SEARCH_BY_E_MAIL:
    printf("Calling Search By E-mail...\n");
    break;
  default:
    printf("Invalid Input :(");
    break;
  }
}


// MAIN FUNCTION
int main()
{

  while (1)
  {
    int userChoice = menu();

    switch (userChoice)
    {
    case ADD_CONTACT:
      createContactFromInput();
      break;
    case VIEW_CONTACTS:
      viewContact();
      break;
    case DELETE_CONTACT:
      printf("Calling Delete Contact...\n");
      break;
    case UPDATE_CONTACT:
      printf("Calling Update Contact...\n");
      break;
    case SEARCH_CONTACT:
      searchMenu();
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