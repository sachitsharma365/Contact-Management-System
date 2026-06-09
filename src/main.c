#include <stdio.h>
#include "../includes/repository.h"
#include "../includes/contact.h"
#include "../includes/helper_funs.h"

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

// MENU FUNCTIONS
int menu()
{
  int userInput;

  printf(ANSI_COLOR_BLUE "\nWelcome to the Contact Management System.\nChoose any option from below and enter the respective number.\n");
  printf("1. Add Contact\n"
         "2. View Contacts\n"
         "3. Delete Contact\n"
         "4. Update Contact\n"
         "5. Search Contact\n"
         "6. Export Contacts\n"
         "7. Import Contacts\n"
         "8. Exit Application\n" ANSI_COLOR_RESET);

  printf("> ");
  if (!readInt(&userInput))
  {
    return 0;
  }

  return userInput;
}

void searchMenu()
{
  // MAIN SEARCH MENU
  int searchMenuUserChoice;

  printf(ANSI_COLOR_BLUE "\nSelect one option by which you want to search the contact:-\n");
  printf("1. Search By Id\n"
         "2. Search By Name\n"
         "3. Search By Phone No.\n"
         "4. Search By Address\n"
         "5. Search By E-mail\n" ANSI_COLOR_RESET);

  printf("> ");
  if (!readInt(&searchMenuUserChoice))
  {
    searchMenuUserChoice = 0;
  }

  int selectedContactIndex = selectContact(searchMenuUserChoice);

  searchContact(selectedContactIndex);
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
      // deleteMenu();
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