#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"


void Adj_init(Adj* self) {
	strcpy_s(self->id, sizeof(self->id), "(none)");
	self->friendnext = NULL;
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
