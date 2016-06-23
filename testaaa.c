#include <stdio.h>
#define FILENAME "user.txt"  // 정확한 파일 이름을 적어 줍니다. 현재는 실행되는 프로그램 폴더에 있는 것으로 가정

typedef struct
{
    int n;
    struct Adj* next;

}Adj;

void Adj_init(Adj* self)
{
    self->n=0;
    self->next = NULL;
}


typedef struct
{
   char id[20];
   char date[40];
   char name[40];
   int n;
   Adj* first;
} User;

void Use_init(User* self)
{
    strcpy(self->id,"(none)");
    strcpy(self->date,"(none)");
    strcpy(self->name,"(none)");
    self->first = NULL;

}

void User_add(User* self, User* u)
{
    Adj* a = (Adj*)malloc(sizeof(Adj));
    a->n = u->n;
    a->next = self->first;
    self->first = a;
}


 // 최대 20 명 까지 저장
int GetMenu();
// 현재 내용을 출력
void Display(User s[], int count);
// 학생 추가
void Add(User s[], int *count);
// 현재 파일 내용을 읽어 옴
void Read(char* file, User s[], int *count);
// 현재 내용을 저장
void Save(char* file, User s[], int count);
int main()
{
   //User user[20];
   User* user =(User*)malloc(sizeof(User));
   int count = 0;
   int menu = 0;
   int i;
   // 파일에 저장되어 있는 내용을 먼저 읽어 옵니다
   Read(FILENAME, user, &count);
   while ( menu != 99 )
   {
      menu = GetMenu();
      switch ( menu )
      {
         case 0:
         Read(FILENAME, user, &count);
         ReadDataFile(user, count);
         Display(user, count);
         break;
         case 1:
         Add(user, &count);
         break;
         case 2:
         Add(user, &count);
         break;
         case 3:
         Add(user, &count);
         break;
         case 4:
         Add(user, &count);
         break;
         case 5:
         Add(user, &count);
         break;
         case 6:
         Add(user, &count);
         break;
         case 7:
         Add(user, &count);
         break;
         case 8:
         Add(user, &count);
         break;
         case 9:
         Add(user, &count);
         break;
         case 99:
         default:
         break;
      }
   }
   // 결과 저장
   Save(FILENAME, user, count);
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
      printf(">>> "); scanf("%d", &menu);
   } while ( (menu < 0 || menu > 9)&&(menu!=99));
   return menu;
}
void Display(User* user, int count)
{
   int i;

   printf("\n\n");
   for ( i = 0; i < count; ++i )
   printf("%10s%10s%10s",user->id, user->date, user->name);
   printf("\n\n");
}

void ReadDataFile(User* user, int count)
{
    int i;
    int total_user=count;

    printf("Total user : %d\n", total_user);
}
/*void Add(User s[], int *count)
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
void Read(char* file, User * user, int *count)
{
   FILE* pFile;
   char str[40];

   pFile = fopen(FILENAME, "rt");


   fgets(s[*count].id, sizeof(s[*count].id), pFile);
   fgets(s[*count].date, sizeof(s[*count].date), pFile);
   fgets(s[*count].name, sizeof(s[*count].name), pFile);


   while ( !feof(pFile) )
   {
      ++(*count);
      fgets(s[*count].id, sizeof(s[*count].id), pFile);
      fgets(s[*count].date, sizeof(s[*count].date), pFile);
      fgets(s[*count].name, sizeof(s[*count].name), pFile);
   }
   fclose(pFile);


}
void Save(char* file, User s[], int count)
{
   FILE* pFile;
   int i;
   pFile = fopen(file, "wt");
   for ( i = 0; i < count; ++i )
   fprintf(pFile, "%10s%10s%10s\n", s[i].id, s[i].date, s[i].name);
   fclose(pFile);
}


