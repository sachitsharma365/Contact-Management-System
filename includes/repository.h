#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"

int findContactIndexById(int id);
void addContact(CONTACT tempContact);
void createContactFromInput(void);
void viewContact(void);
int searchContactById(int searchMenuUserId);

#endif