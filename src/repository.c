#include <stdio.h>
#include <string.h>
#include "../includes/repository.h"
#include "../includes/contact.h"

static CONTACT contacts[100];
static int contactCount = 0;

void addContact()
{
  char tempName[100], tempPhone[20], tempAddress[100], tempEmail[100];

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

  printf("\n%s %s %s %s\n", tempName, tempPhone, tempAddress, tempEmail);

  // STORING USER INPUT IN contacts ARRAY
  strncpy(contacts[contactCount].name, tempName, sizeof(contacts[contactCount].name - 1));
  contacts[contactCount].name[sizeof(contacts[contactCount].name - 1)] = '\0';

  strncpy(contacts[contactCount].phone, tempPhone, sizeof(contacts[contactCount].phone - 1));
  contacts[contactCount].phone[sizeof(contacts[contactCount].phone - 1)] = '\0';

  strncpy(contacts[contactCount].address, tempAddress, sizeof(contacts[contactCount].address - 1));
  contacts[contactCount].address[sizeof(contacts[contactCount].address - 1)] = '\0';

  strncpy(contacts[contactCount].email, tempEmail, sizeof(contacts[contactCount].email - 1));
  contacts[contactCount].email[sizeof(contacts[contactCount].email - 1)] = '\0';

  contactCount++;
}