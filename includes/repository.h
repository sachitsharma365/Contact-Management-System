#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"


CONTACT createContactFromInput(void);
void addContact(CONTACT tempContact);
void viewContact(void);
int selectContact(int userChoiceForSelection);
void showContact(int index);
int deleteContact(int index);
int updateContact(int index);


#endif