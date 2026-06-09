#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "contact.h"

int findContactIndexById(int id);
int findContactIndexByName(char name[CONTACT_NAME_LEN]);
int findContactIndexByPhone(char phone[CONTACT_PHONE_LEN]);
int findContactIndexByAddress(char address[CONTACT_ADDRESS_LEN]);
int findContactIndexByEmail(char email[CONTACT_EMAIL_LEN]);

void createContactFromInput(void);
void addContact(CONTACT tempContact);
void viewContact(void);

int searchContact(int contactIndex);

int delteContactById(int deleteMenuUserId);
int deleteContactByName(int deleteMenuUserChoice);


#endif