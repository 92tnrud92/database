#include <stdio.h>
#define FILENAME "user.txt"  // 정확한 파일 이름을 적어 줍니다. 현재는 실행되는 프로그램 폴더에 있는 것으로 가정
typedef struct tag_STUDENT
{
   char name[20];
   char univ[40];
   char major[40];
} STUDENT;
#define COUNT 20 // 최대 20 명 까지 저장
int GetMenu();
// 현재 내용을 출력
void Display(STUDENT s[], int count);
// 학생 추가
void Add(STUDENT s[], int *count);
// 현재 파일 내용을 읽어 옴
void Read(char* file, STUDENT s[], int *count);
// 현재 내용을 저장
void Save(char* file, STUDENT s[], int count);
int main()
{
   STUDENT students[COUNT];
   int count = 0;
   int menu = 0;
   int i;
   // 파일에 저장되어 있는 내용을 먼저 읽어 옵니다
   Read(FILENAME, students, &count);
   while ( menu != 3 )
   {
      menu = GetMenu();
      switch ( menu )
      {
         case 1:
         Display(students, count);
         break;
         case 2:
         Add(students, &count);
         break;
         case 3:
         default:
         break;
      }
   }
   // 결과 저장
   Save(FILENAME, students, count);
   return 0;
}
int GetMenu()
{
   int menu;
   do
   {
      printf("----------------------------------\n");
      printf("메뉴를 선택하세요\n");
      printf("1. 현재 내용 출력\n");
      printf("2. 학생 추가\n");
      printf("3. 종료\n");
      printf("----------------------------------\n");
      printf(">>> "); scanf("%d", &menu);
   } while ( menu < 1 || menu > 3 );
   return menu;
}
void Display(STUDENT s[], int count)
{
   int i;
   printf("\n\n");
   for ( i = 0; i < count; ++i )
   printf("%10s\n%10s\n%10s\n", s[i].name, s[i].univ, s[i].major);
   printf("\n\n");
}
void Add(STUDENT s[], int *count)
{
   ++(*count);
   if ( *count >= COUNT)
   {
      printf("더 이상 추가할 수 없습니다.\n");
      return;
   }
   printf("이름 : "); scanf("%s", s[*count-1].name);//name뒤에는 \n이 포함됨.
   printf("학교 : "); scanf("%s", s[*count-1].univ);
   printf("학과 : "); scanf("%s", s[*count-1].major);
}
void Read(char* file, STUDENT s[], int *count)
{
   FILE* pFile;
   char str[40];

   pFile = fopen(FILENAME, "rt");

fscanf(pFile, "%s %s %s", s[*count].name, s[*count].univ, s[*count].major);
   fgets(s[*count].name, sizeof(s[*count].name), pFile);
   fgets(s[*count].univ, sizeof(s[*count].univ), pFile);
   fgets(s[*count].major, sizeof(s[*count].major), pFile);

   /*fgets(str,sizeof(str),pFile);*/

   while ( !feof(pFile) )
   {
      ++(*count);
      fgets(s[*count].name, sizeof(s[*count].name), pFile);

      fgets(s[*count].univ, sizeof(s[*count].univ), pFile);

      fgets(s[*count].major, sizeof(s[*count].major), pFile);


     //fscanf(pFile, "%s %s %s", s[*count].name, s[*count].univ, s[*count].major);
   }
   fclose(pFile);
}
void Save(char* file, STUDENT s[], int count)
{
   FILE* pFile;
   int i;
   pFile = fopen(file, "wt");
   for ( i = 0; i < count; ++i )
   fprintf(pFile, "%10s%10s%10s\n", s[i].name, s[i].univ, s[i].major);
   fclose(pFile);
}


