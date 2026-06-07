#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"

void addContact(CONTACT tempContact);
void createContactFromInput();
void viewContact();
int searchContactById(int searchMenuUserId);

#endif