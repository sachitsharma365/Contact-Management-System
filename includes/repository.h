#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"

void createContactFromInput(void);
void addContact(CONTACT tempContact);
void viewContact(void);
int searchContactById(int searchMenuUserId);
int searchContactByName(char searchMenuUserName[CONTACT_NAME_LEN]);
int searchContactByPhone(char searchMenuUserPhone[CONTACT_PHONE_LEN]);
int searchContactByAddress(char searchMenuUserAddress[CONTACT_ADDRESS_LEN]);
int searchContactByEmail(char searchMenuUserEmail[CONTACT_EMAIL_LEN]);


#endif