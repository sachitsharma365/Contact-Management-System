#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"

int selectContact(int userChoiceForSelection);

void createContactFromInput(void);
void addContact(CONTACT tempContact);
void viewContact(void);

void showSelectedContact(int contactIndex);


#endif