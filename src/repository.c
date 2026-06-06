#include <stdio.h>
#include <string.h>
#include "../includes/repository.h"
#include "../includes/contact.h"

static CONTACT contacts[100];
static int contactCount = 0;

void createContactFromInput()
{
  char tempName[100], tempPhone[20], tempAddress[100], tempEmail[100];
  CONTACT tempContact;

  // TAKING USER INPUT
  printf("Enter the contact name: ");
  fgets(tempName, sizeof(tempName), stdin);
  tempName[strcspn(tempName, "\n")] = '\0';

  printf("Enter the contact phone no: ");
  fgets(tempPhone, sizeof(tempPhone), stdin);
  tempPhone[strcspn(tempPhone, "\n")] = '\0';

  printf("Enter the contact address: ");
  fgets(tempAddress, sizeof(tempAddress), stdin);
  tempAddress[strcspn(tempAddress, "\n")] = '\0';

  printf("Enter the contact e-mail: ");
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
  if (contactCount >= 100)
  {
    printf("Contact list is full.\n");
    return;
  }

  // STORING USER INPUT IN contacts ARRAY
  contacts[contactCount] = tempContact;
  contacts[contactCount].id = contactCount + 1;

  contactCount++;
}

void viewContact(){
  for (int i = 0; i < contactCount; i++)
  {
    printf("{\nId: %d\nName: %s\nPhone No: %s\nAddress: %s\nE-mail: %s\n}\n\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
  }
}