#include <stdio.h>
#include <stdlib.h>
#include "def.h"

int GetMenu();
// 현재 내용을 출력
//void Add(User s[], int *count);
// 현재 파일 내용을 읽어 옴

//void Save(char* file, User s[], int count);

void Make_Userinf(char* file, List * plist)
{

	FILE* pFile;
	char str[40];
	int ch = 0;

	fopen_s(&pFile, FILENAME, "rt");
	//파일 오픈
	if (pFile == NULL)
	{
		perror("Error opening file");
		return;
	}

	while (!feof(pFile)){	//LD 포인터 생성.

		LData * newdata = (LData*)malloc(sizeof(LData));
		
		newdata->color = 0;
		newdata->parent = -1;
		for (int i = 0; i < 100; i++)
		{
			{
				strcpy_s(newdata->word[i], sizeof(newdata->word[i]), "(none)");
			}
		}		
		fgets(newdata->id, sizeof(newdata->id), pFile);		
		fgets(newdata->date, sizeof(newdata->date), pFile);
		fgets(newdata->name, sizeof(newdata->name), pFile);	
		FInsert(plist, *newdata);// 노드에 집어 넣었음.	
		fgets(str, sizeof(str), pFile);
		
	}
	VertexRemove(plist);


	fclose(pFile);
}

int WordInput(char* file, List * plist)
{

	FILE* pFile;
	char str[40];
	int ch = 0;
	LData data;
	int wordcount = 0;
	
	int i = 0;
	fopen_s(&pFile, file, "rt");
	//파일 오픈
	if (pFile == NULL)
	{
		perror("Error opening file");
		return -1;
	}

	while (!feof(pFile)) {	//LD 포인터 생성.

		LData * newdata = (LData*)malloc(sizeof(LData));

		fgets(newdata->id, sizeof(newdata->id), pFile);
		fgets(str, sizeof(str), pFile);//날짜 삭제
		fgets(newdata->word[i++], sizeof(newdata->word[i++]), pFile);
		printf("%d", i);

		if (LFirst(plist, &data))
		{
			if (data.id == newdata->id)
			{
				FInsert(plist, *newdata);
				wordcount++;
		
			}
			while (LNext(plist, &data))
			{
				if (data.id == newdata->id)
				{
					FInsert(plist, *newdata);
					wordcount++;
				}
			}

		}
	
	}
	fclose(pFile);
	return wordcount;
}


int main(void)
{
	List list;
	ListInit(&list);
	LData data;
	int menu = 0;
	char file2[100] = "/Users/SuGyeong/Desktop/test/wordsample.txt";
	char file3[100] = "friend";

	while (menu != 99)
	{
		menu = GetMenu();
		switch (menu)
		{
		case 0:
			Make_Userinf(FILENAME, &list);
			printf("Total user : %d\n", LCount(&list)-1);//쓰레기값이 하나 들어감.*해결해야함.
			printf("Total tweets : %d\n", WordInput(file2, &list));
			if (LFirst(&list, &data))
			{
				printf("%s %s %s \n", data.id, data.date, data.name);
				while (LNext(&list, &data))
				{
					printf("%s %s %s \n", data.id, data.date, data.name);
				}
			}			
			break;
		case 1:
			// Add(user, &count);
			break;
		case 2:
			//Add(user, &count);
			break;
		case 3:
			//Add(user, &count);
			break;
		case 4:
			//Add(user, &count);
			break;
		case 5:
			//Add(user, &count);
			break;
		case 6:
			//Add(user, &count);
			break;
		case 7:
			// Add(user, &count);
			break;
		case 8:
			// Add(user, &count);
			break;
		case 9:
			//  Add(user, &count);
			break;
		case 99:
		default:
			break;
		}
	}
	// 결과 저장
	//Save(FILENAME, users, count);

	getchar();

	return 0;
}
int GetMenu()
{
	int menu;
	do
	{
		printf("----------------------------------\n");
		printf("Select Menu:\n");
		printf("0. Read data files\n");
		printf("1. display statistics\n");
		printf("2. Top 5 most tweeted words\n");
		printf("3. Top 5 most tweeted users\n");
		printf("4. Find users who tweeted a word\n");
		printf("5. Find all people who are friends of the above users\n");
		printf("6. Delete all mentions of a word\n");
		printf("7. Delete all users who mentioned a word\n");
		printf("8. Find strongly connected components\n");
		printf("9. Find shortest path from a given user\n");
		printf("99. Quit\n");
		printf("----------------------------------\n");
		printf(">>> "); scanf_s("%d", &menu);
	} while ((menu < 0 || menu > 9) && (menu != 99));
	return menu;
}

/*
void display(Vertex vertices[], int count)
{
int i;
for (i = 0; i < count; i++) {

printf("%s ", vertices[i].id);
printf("%s ", vertices[i].date);
printf("%s ", vertices[i].name);
printf("\n\n");
}
}


*/
/*
//LData에 값넣어주는 과정. id랑
void UInsert(char* file)
{

FILE* pFile;
char str[40];
int ch = 0;

LData * newdata = (LData*)malloc(sizeof(LData));


fgets(vertex[*count].id, sizeof(vertex[*count].id), pFile);
fgets(vertex[*count].date, sizeof(vertex[*count].date), pFile);
fgets(vertex[*count].name, sizeof(vertex[*count].name), pFile);
fgets(str, sizeof(str), pFile);


newdata = Make_Userinf(char* id, char* date, char* name);


while (!feof(pFile)) {
++(*count);
fgets(vertex[*count].id, sizeof(vertex[*count].id), pFile);
fgets(vertex[*count].date, sizeof(vertex[*count].date), pFile);
fgets(vertex[*count].name, sizeof(vertex[*count].name), pFile);
fgets(str, sizeof(str), pFile);

}
fclose(pFile);

}
*/
/*
void ReadDataFile(User* user, int count)
{
//int i;
int total_user = count;

printf("Total user : %d\n", total_user);
}
void Add(User s[], int *count)
{
++(*count);
if ( *count >= COUNT)
{
printf("더 이상 추가할 수 없습니다.\n");
return;
}
printf("이름 : "); scanf("%s", s[*count-1].id);
printf("학교 : "); scanf("%s", s[*count-1].date);
printf("학과 : "); scanf("%s", s[*count-1].name);
}*/
/*void Read(char* file, User s[], int *count)
{
FILE* pFile;
char str[40];
int i;

pFile = fopen(FILENAME, "rt");


fgets(s[0].id, sizeof(s[0].id), pFile);
fgets(s[0].date, sizeof(s[0].date), pFile);
fgets(s[0].name, sizeof(s[0].name), pFile);
fgets(str, sizeof(str), pFile);


for (i = 1; i<8; i++) {

fgets(s[i].id, sizeof(s[i].id), pFile);
fgets(s[i].date, sizeof(s[i].date), pFile);
fgets(s[i].name, sizeof(s[i].name), pFile);
fgets(str, sizeof(str), pFile);
}
fclose(pFile);


}
void Save(char* file, User s[], int count)
{
FILE* pFile;
int i;
pFile = fopen(file, "wt");
for (i = 0; i < 8; ++i)
fprintf(pFile, "%10s%10s%10s\n", s[i].id, s[i].date, s[i].name);
fclose(pFile);
}
*/

