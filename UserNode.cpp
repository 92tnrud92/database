#include <stdio.h>
#include <stdlib.h>
#include "DLikedList.h"
#include <string.h>

#define FILENAME "input.txt"//변경해줄것.


void Adj_init(Adj* self)
{
	self->n = 0;
	self->next = NULL;
}



void UserInit(User * puser)
{
	strcpy_s(puser->id, NULL);
	strcpy_s(puser->date, NULL);
	strcpy_s(puser->name, NULL);
	puser->n = 0;
	puser->first = NULL;
}

//User Structure에 값이 들어가는 것.
void UIsert(char* file, List * plist)
{
	User * newuser = (User*)malloc(sizeof(User));

	FILE* pFile;
	char str[40];
	int i;

	fopen_s(&pFile, FILENAME, "rt");


	fgets(newuser->id, sizeof(newuser->id), pFile);
	fgets(newuser->date, sizeof(newuser->date), pFile);
	fgets(newuser->name, sizeof(newuser->name), pFile);
	fgets(str, sizeof(str), pFile);
	
	LFirst(plist, newuser);

	while(!feof(pFile)){

		UIsert(file, plist);
	
	}
	fclose(pFile);


}


