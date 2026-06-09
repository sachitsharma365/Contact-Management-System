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

  if (selectedContactIndex != -1)
  {
    showContact(selectedContactIndex);
  }
}

void deleteMenu()
{
  int deleteMenuUserChoice;

  printf(ANSI_COLOR_BLUE "\nSelect one option by which you want to delete the contact:-\n");
  printf("1. Search By Id\n"
         "2. Search By Name\n"
         "3. Search By Phone No.\n"
         "4. Search By Address\n"
         "5. Search By E-mail\n" ANSI_COLOR_RESET);

  printf("> ");
  if (!readInt(&deleteMenuUserChoice))
  {
    deleteMenuUserChoice = 0;
  }

  int selectedContactIndex = selectContact(deleteMenuUserChoice);

  if (selectedContactIndex != -1)
  {
    int deleteReturnValue = deleteContact(selectedContactIndex);

    if (deleteReturnValue == 1)
    {
      printf(ANSI_COLOR_GREEN "Contact Deleted Sucessfully" ANSI_COLOR_RESET);
    }
    else if (deleteReturnValue == 0)
    {
      printf(ANSI_COLOR_RED "Contact Cannot Be Deleted" ANSI_COLOR_RESET);
    }
  }
}

void updateMenu()
{
  int updateMenuUserChoice;

  printf(ANSI_COLOR_BLUE "\nSelect one option to select the contact you want to update:-\n");
  printf("1. Select By Id\n"
         "2. Select By Name\n"
         "3. Select By Phone No.\n"
         "4. Select By Address\n"
         "5. Select By E-mail\n" ANSI_COLOR_RESET);

  printf("> ");
  if (!readInt(&updateMenuUserChoice))
  {
    updateMenuUserChoice = 0;
  }

  int selectedContactIndex = selectContact(updateMenuUserChoice);

  int updateFunReturnValue = updateContact(selectedContactIndex);

  if (updateFunReturnValue == 1)
  {
    printf(ANSI_COLOR_GREEN "\nContact Update Successfully\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "This is the update Contact:-\n" ANSI_COLOR_RESET);
    showContact(selectedContactIndex);
  }
  else if (updateFunReturnValue == 0)
  {
    printf(ANSI_COLOR_RED "\nError Updating the Contact :(\n" ANSI_COLOR_RESET);
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
      CONTACT tempContact = createContactFromInput();
      addContact(tempContact);
      break;
    case VIEW_CONTACTS:
      viewContact();
      break;
    case DELETE_CONTACT:
      deleteMenu();
      break;
    case UPDATE_CONTACT:
      updateMenu();
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