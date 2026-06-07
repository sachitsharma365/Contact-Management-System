#include <stdio.h>
#include <string.h>
#include "../includes/repository.h"
#include "../includes/contact.h"
#include "../includes/helper_funs.h"

// STATIC GLOBAL VARIABLES
static CONTACT contacts[MAX_CONTACTS];
static int contactCount = 0;

// HELPER FUNCTIONS
int findContactIndexById(int id)
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

// FUNCTIONS
void createContactFromInput()
{
  char tempName[100], tempPhone[20], tempAddress[100], tempEmail[100];
  CONTACT tempContact;

  // TAKING USER INPUT
  printf(ANSI_COLOR_GREEN"Enter the contact name: "ANSI_COLOR_RESET);
  fgets(tempName, sizeof(tempName), stdin);
  tempName[strcspn(tempName, "\n")] = '\0';

  printf(ANSI_COLOR_GREEN"Enter the contact phone no: "ANSI_COLOR_RESET);
  fgets(tempPhone, sizeof(tempPhone), stdin);
  tempPhone[strcspn(tempPhone, "\n")] = '\0';

  printf(ANSI_COLOR_GREEN"Enter the contact address: "ANSI_COLOR_RESET);
  fgets(tempAddress, sizeof(tempAddress), stdin);
  tempAddress[strcspn(tempAddress, "\n")] = '\0';

  printf(ANSI_COLOR_GREEN"Enter the contact e-mail: "ANSI_COLOR_RESET);
  fgets(tempEmail, sizeof(tempEmail), stdin);
  tempEmail[strcspn(tempEmail, "\n")] = '\0';

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
    printf(ANSI_COLOR_RED"Contact list is full.\n"ANSI_COLOR_RESET);
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
    printf("{\nId: %d\nName: %s\nPhone No: %s\nAddress: %s\nE-mail: %s\n}\n\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
  }
}

int searchContactById(int searchMenuUserId)
{
  int contactIndex = findContactIndexById(searchMenuUserId);

  if (contactIndex != -1)
  {
    printf("{\nId: %d\nName: %s\nPhone No: %s\nAddress: %s\nE-mail: %s\n}\n\n", contacts[contactIndex].id, contacts[contactIndex].name, contacts[contactIndex].phone, contacts[contactIndex].address, contacts[contactIndex].email);
    return 1;
  }
  else
  {
    return 0;
  }
}
