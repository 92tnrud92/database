#include <stdio.h>
#include <stdlib.h>
#include "DLikedList.h"
#include <string.h>



typedef struct
{
	char id[20];
	char date[40];
	char name[40];
	int n;
	//Adj* first;
} User;


void UserInit(User * puser)
{
	strcpy_s(puser->id, "(none)");s


}


void UInsert(User * puser, );