#ifndef CONTACT_H
#define CONTACT_H

// MACROS
#define MAX_CONTACTS 100

typedef struct
{
  int id;
  char name[100];
  char phone[20];
  char address[100];
  char email[100];
}CONTACT;


#endif