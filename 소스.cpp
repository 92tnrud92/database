#include <stdio.h>
#include <stdlib.h>
#include "def.h"

void ListInit(List * plist)
{
	plist->head = (Vertex*)malloc(sizeof(Vertex));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Vertex * vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->data = data;

	vertex->next = plist->head->next;
	plist->head->next = vertex;

	(plist->numOfData)++;
}//vertex¿¡ »ðÀÔ.


void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	/*	else
	SInsert(plist, data);*/

}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Vertex * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;


	free(rpos);
	(plist->numOfData)--;
	return rdata;


}

int LCount(List * plist)
{
	return plist->numOfData;
}
