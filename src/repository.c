#include <stdio.h>
#include <string.h>
#include "../includes/repository.h"
#include "../includes/contact.h"
#include "../includes/helper_funs.h"


// ENUMERATORS
typedef enum
{
  SELECT_BY_ID = 1,
  SELECT_BY_NAME,
  SELECT_BY_PHONE,
  SELECT_BY_ADDRESS,
  SELECT_BY_E_MAIL,
} SELECT_MENU_OPTIONS;


// STATIC GLOBAL VARIABLES
static CONTACT contacts[MAX_CONTACTS];
static int contactCount = 0;


// STATICHELPER FUNCTIONS
static int findContactIndexById(int id)
{
  for (int i = 0; i < contactCount; i++)
  {
    if (contacts[i].id == id)
    {
      return i;
    }
  }

  return -1;
}

static int findContactIndexByName(char name[CONTACT_NAME_LEN])
{
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].name, name) == 0)
    {
      return i;
    }
  }
  return -1;
}

static int findContactIndexByPhone(char phone[CONTACT_PHONE_LEN])
{
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].phone, phone) == 0)
    {
      return i;
    }
  }
  return -1;
}

static int findContactIndexByAddress(char address[CONTACT_ADDRESS_LEN])
{
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].address, address) == 0)
    {
      return i;
    }
  }
  return -1;
}

static int findContactIndexByEmail(char email[CONTACT_EMAIL_LEN])
{
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].email, email) == 0)
    {
      return i;
    }
  }
  return -1;
}


// FUNCTIONS
void createContactFromInput()
{
  char tempName[100], tempPhone[20], tempAddress[100], tempEmail[100];
  CONTACT tempContact;

  // TAKING USER INPUT
  printf(ANSI_COLOR_GREEN "Enter the contact name: " ANSI_COLOR_RESET);
  readLine(tempName, sizeof(tempName));

  printf(ANSI_COLOR_GREEN "Enter the contact phone no: " ANSI_COLOR_RESET);
  readLine(tempPhone, sizeof(tempPhone));

  printf(ANSI_COLOR_GREEN "Enter the contact address: " ANSI_COLOR_RESET);
  readLine(tempAddress, sizeof(tempAddress));

  printf(ANSI_COLOR_GREEN "Enter the contact e-mail: " ANSI_COLOR_RESET);
  readLine(tempEmail, sizeof(tempEmail));

  // CREATING TEMPORARY CONTACT
  strncpy(tempContact.name, tempName, sizeof(tempContact.name) - 1);
  tempContact.name[sizeof(tempContact.name) - 1] = '\0';

  strncpy(tempContact.phone, tempPhone, sizeof(tempContact.phone) - 1);
  tempContact.phone[sizeof(tempContact.phone) - 1] = '\0';

  strncpy(tempContact.address, tempAddress, sizeof(tempContact.address) - 1);
  tempContact.address[sizeof(tempContact.address) - 1] = '\0';

  strncpy(tempContact.email, tempEmail, sizeof(tempContact.email) - 1);
  tempContact.email[sizeof(tempContact.email) - 1] = '\0';

  addContact(tempContact);
}

void addContact(CONTACT tempContact)
{
  if (contactCount >= MAX_CONTACTS)
  {
    printf(ANSI_COLOR_RED "Contact list is full.\n" ANSI_COLOR_RESET);
    return;
  }

  // STORING USER INPUT IN contacts ARRAY
  contacts[contactCount] = tempContact;
  contacts[contactCount].id = contactCount + 1;

  contactCount++;
}

void viewContact()
{
  for (int i = 0; i < contactCount; i++)
  {
    showContact(i);
  }
}

int selectContact(int userChoiceForSelection)
{
  int selectedContactIndex;
  switch (userChoiceForSelection)
  {
  case SELECT_BY_ID:
  {
    int selectMenuUserId;
    printf(ANSI_COLOR_GREEN "Enter the User Id: " ANSI_COLOR_RESET);
    if (!readInt(&selectMenuUserId))
    {
      selectMenuUserId = -1;
    }

    selectedContactIndex = findContactIndexById(selectMenuUserId);
    return selectedContactIndex;
  }

  break;
  case SELECT_BY_NAME:
  {
    char selectMenuUserName[CONTACT_NAME_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Name: " ANSI_COLOR_RESET);
    readLine(selectMenuUserName, sizeof(selectMenuUserName));

    selectedContactIndex = findContactIndexByName(selectMenuUserName);
    return selectedContactIndex;
  }

  break;
  case SELECT_BY_PHONE:
  {
    char selectMenuUserPhone[CONTACT_PHONE_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Phone Number: " ANSI_COLOR_RESET);
    readLine(selectMenuUserPhone, sizeof(selectMenuUserPhone));

    selectedContactIndex = findContactIndexByPhone(selectMenuUserPhone);
    return selectedContactIndex;
  }

  break;
  case SELECT_BY_ADDRESS:
  {
    char selectMenuUserAddress[CONTACT_ADDRESS_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Address: " ANSI_COLOR_RESET);
    readLine(selectMenuUserAddress, sizeof(selectMenuUserAddress));

    selectedContactIndex = findContactIndexByAddress(selectMenuUserAddress);
    return selectedContactIndex;
  }

  break;
  case SELECT_BY_E_MAIL:
  {
    char selectMenuUserEmail[CONTACT_EMAIL_LEN];
    printf(ANSI_COLOR_GREEN "Enter the User Email: " ANSI_COLOR_RESET);
    readLine(selectMenuUserEmail, sizeof(selectMenuUserEmail));

    selectedContactIndex = findContactIndexByEmail(selectMenuUserEmail);
    return selectedContactIndex;
  }

  break;
  default:
    printf(ANSI_COLOR_RED "No Contact Found :(" ANSI_COLOR_RESET);
    return -1;
    break;
  }
}

void showContact(int index)
{
  printf("{\nId: %d\nName: %s\nPhone No: %s\nAddress: %s\nE-mail: %s\n}\n\n", contacts[index].id, contacts[index].name, contacts[index].phone, contacts[index].address, contacts[index].email);
}

int deleteContact(int index){
  for (int i = index; i < contactCount; i++)
  {
    if (i == (contactCount-1))
    {
      contactCount--;
      return 1;
    }
    contacts[i] = contacts[i+1];
    contacts[i].id = (contacts[i].id)-1;
  }
  return 0;
}
