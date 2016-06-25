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
void VertexRemove(List *plist)
{
	Vertex * rpos = plist->cur;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;


	free(rpos);
	(plist->numOfData)--;
	
}

int LCount(List * plist)
{
	return plist->numOfData;
}


void Adj_init(Adj* self) {
	strcpy_s(self->id, sizeof(self->id), "(none)");
	self->friendnext = NULL;
}

void LDataInit(LData * pdata) {

	pdata->color = 0;
	pdata->parent = -1;
	strcpy_s(pdata->id, sizeof(pdata->id), "(none)");
	strcpy_s(pdata->date, sizeof(pdata->date), "(none)");
	strcpy_s(pdata->name, sizeof(pdata->name), "(none)");
}


void Vertex_init(Vertex* self) {
	self->data.color = 0;
	self->data.parent = -1;
	strcpy_s(self->data.id, sizeof(self->data.id), "(none)");
	strcpy_s(self->data.date, sizeof(self->data.date), "(none)");
	strcpy_s(self->data.name, sizeof(self->data.name), "(none)");
	self->first = NULL;
	for (int i = 0; i<100; i++)
	{
		{
			strcpy_s(self->data.word[i], sizeof(self->data.word[i]), "(none)");
		}
	}
}

void Vertex_add(Vertex* self, Vertex* v) {
	Adj* a = (Adj *)malloc(sizeof(Adj));
	strcpy_s(a->id, sizeof(a->id), v->data.id);
	a->friendnext = self->first;
	self->first = a;
}
