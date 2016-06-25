#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
#include <string.h>

#define FILENAME "/Users/SuGyeong/Desktop/test/usersample.txt"

#define TRUE 1
#define FALSE 0

#define WHITE 0
#define GRAY  1
#define BLACK 2

//#define RED 0
//#define BLACK 1


typedef struct Adj {
	char id[20];
	Adj* friendnext;
} Adj;

//초기화

void Adj_init(Adj* self);

typedef struct LData
{
	char id[20];
	char date[40];
	char name[40];
	char word[100][150];// word[100] char *로?
	int color;
	int parent;

}LData;

typedef struct Vertex
{
	LData data;
	Adj * first;
	Vertex * next;
}Vertex;

void Vertex_init(Vertex* self);
void Vertex_add(Vertex* self, Vertex* v);



typedef struct _likedlist
{
	Vertex * head;
	Vertex * cur;
	Vertex * before;
	int(*comp)(LData d1, LData d2);
	int numOfData;

} LinkedList;
//연결리스트

typedef LinkedList List;

//void LDataInit(LData * pdata);
//LData LDatavalue(char * str1, char *str2, char * str3);
//LData에 값 추가(id, data, name)

//파일 입력받아서 LData에 값 넣고 추가.
//세로 부분 - 

//void NodeInit(Node * puser);

//void Adj_init(Adj* self);
//void Friend_add(Node * self, Node * v);
void LDataInit(LData * pdata);

void FInsert(List * plist, LData data);
//더미노드 다음 노드에 추가.
void ListInit(List * plist);
//List 초기화
void LInsert(List * plist, LData data);
//List에 데이터 삽입. (정렬조건없으면 FInsert)

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

void VertexRemove(List *plist);
LData LRemove(List* plist);
int LCount(List* plist);

//void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

//LData Uservalue(char * str1, char *str2, char * str3);

#endif // !__D_LINKED_LIST_H__#pragma once
