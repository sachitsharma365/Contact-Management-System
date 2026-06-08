#ifndef CONTACT_H
#define CONTACT_H

// MACROS
#define MAX_CONTACTS 100
#define CONTACT_NAME_LEN 100
#define CONTACT_PHONE_LEN 20
#define CONTACT_ADDRESS_LEN 100
#define CONTACT_EMAIL_LEN 100


typedef struct
{
  int id;
  char name[CONTACT_NAME_LEN];
  char phone[CONTACT_PHONE_LEN];
  char address[CONTACT_ADDRESS_LEN];
  char email[CONTACT_EMAIL_LEN];
}CONTACT;


#endif