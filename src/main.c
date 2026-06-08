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

  printf(ANSI_COLOR_BLUE"\nSelect one option by which you want to search the contact:-\n");
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


  // SUB-SEARCH MENU
  switch (searchMenuUserChoice)
  {
  case SEARCH_BY_ID:
    {
      int searchMenuUserId;
      printf(ANSI_COLOR_GREEN"Enter the User Id you want to search for: "ANSI_COLOR_RESET);
      if (!readInt(&searchMenuUserId))
      {
        searchMenuUserId = -1;
      }

      int searchByIdReturnValue = searchContactById(searchMenuUserId);
      if (searchByIdReturnValue != 1)
      {
        printf(ANSI_COLOR_RED"\nNo Contact found by such Id :(\n"ANSI_COLOR_RESET);
      }
    }
    break;
  case SEARCH_BY_NAME:
    {
      char searchMenuUserName[CONTACT_NAME_LEN];
      printf(ANSI_COLOR_GREEN"Enter the User Name you want to search for: "ANSI_COLOR_RESET);
      readLine(searchMenuUserName, sizeof(searchMenuUserName));

      int searchByNameReturnValue = searchContactByName(searchMenuUserName);
      if (searchByNameReturnValue != 1)
      {
        printf(ANSI_COLOR_RED"\nNo Contact found by such Name :(\n"ANSI_COLOR_RESET);
      }
    }
    break;
  case SEARCH_BY_PHONE:
    {
      char searchMenuUserPhone[CONTACT_PHONE_LEN];
      printf(ANSI_COLOR_GREEN"Enter the User Phone Number you want to search for: "ANSI_COLOR_RESET);
      readLine(searchMenuUserPhone, sizeof(searchMenuUserPhone));

      int searchByPhoneReturnValue = searchContactByPhone(searchMenuUserPhone);
      if (searchByPhoneReturnValue != 1)
      {
        printf(ANSI_COLOR_RED"\nNo Contact found by such Phone Number :(\n"ANSI_COLOR_RESET);
      }
    }
    break;
  case SEARCH_BY_ADDRESS:
    {
      char searchMenuUserAddress[CONTACT_ADDRESS_LEN];
      printf(ANSI_COLOR_GREEN"Enter the User Address you want to search for: "ANSI_COLOR_RESET);
      readLine(searchMenuUserAddress, sizeof(searchMenuUserAddress));

      int searchByAddressReturnValue = searchContactByAddress(searchMenuUserAddress);
      if (searchByAddressReturnValue != 1)
      {
        printf(ANSI_COLOR_RED"\nNo Contact found by such Address :(\n"ANSI_COLOR_RESET);
      }
    }
    break;
  case SEARCH_BY_E_MAIL:
    {
      char searchMenuUserEmail[CONTACT_EMAIL_LEN];
      printf(ANSI_COLOR_GREEN"Enter the User Email you want to search for: "ANSI_COLOR_RESET);
      readLine(searchMenuUserEmail, sizeof(searchMenuUserEmail));

      int searchByEmailReturnValue = searchContactByEmail(searchMenuUserEmail);
      if (searchByEmailReturnValue != 1)
      {
        printf(ANSI_COLOR_RED"\nNo Contact found by such Email :(\n"ANSI_COLOR_RESET);
      }
    }
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