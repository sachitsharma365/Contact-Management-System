#include <stdio.h>
#include <string.h>
#include "../includes/repository.h"
#include "../includes/contact.h"
#include "../includes/helper_funs.h"


// STATIC GLOBAL VARIABLES
static CONTACT contacts[MAX_CONTACTS];
static int contactCount = 0;


// HELPER FUNCTIONS
void showContact(int index)
{
  printf("{\nId: %d\nName: %s\nPhone No: %s\nAddress: %s\nE-mail: %s\n}\n\n", contacts[index].id, contacts[index].name, contacts[index].phone, contacts[index].address, contacts[index].email);
}

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

int findContactIndexByName(char name[CONTACT_NAME_LEN]){
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].name, name) == 0)
    {
      return i;
    }
    
  }
  return -1;
}

int findContactIndexByPhone(char phone[CONTACT_PHONE_LEN]){
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].phone, phone) == 0)
    {
      return i;
    }
    
  }
  return -1;
}

int findContactIndexByAddress(char address[CONTACT_ADDRESS_LEN]){
  for (int i = 0; i < contactCount; i++)
  {
    if (strcmp(contacts[i].address, address) == 0)
    {
      return i;
    }
    
  }
  return -1;
}

int findContactIndexByEmail(char email[CONTACT_EMAIL_LEN]){
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

// SEARCH FUNCTIONS
int searchContact(int contactIndex){
  if (contactIndex != -1)
  {
    showContact(contactIndex);
    return 1;
  }
  return 0;
}


// DELETE FUNCTIONS
