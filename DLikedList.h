#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0


typedef struct
{
	char id[20];
	char date[40];
	char name[40];
	int n;
	//Adj* first;
} User;

void UserInit(User * puser);
void UInsert(User * puser, );



typedef User LData;


typedef struct _node
{
	LData data;
	struct _node * next;

}Node;

typedef struct _likedlist
{
	Node * head;
	Node * cur;
	Node * before;
	int(*comp)(LData d1, LData d2);
	int numOfData;
	
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif // !__D_LINKED_LIST_H__#pragma once
