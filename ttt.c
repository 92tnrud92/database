#include <stdio.h>
#define FILENAME "user.txt"  // ��Ȯ�� ���� �̸��� ���� �ݴϴ�. ����� ����Ǵ� ���α׷� ������ �ִ� ������ ����
typedef struct tag_STUDENT
{
   char name[20];
   char univ[40];
   char major[40];
} STUDENT;
#define COUNT 20 // �ִ� 20 �� ���� ����
int GetMenu();
// ���� ������ ���
void Display(STUDENT s[], int count);
// �л� �߰�
void Add(STUDENT s[], int *count);
// ���� ���� ������ �о� ��
void Read(char* file, STUDENT s[], int *count);
// ���� ������ ����
void Save(char* file, STUDENT s[], int count);
int main()
{
   STUDENT students[COUNT];
   int count = 0;
   int menu = 0;
   int i;
   // ���Ͽ� ����Ǿ� �ִ� ������ ���� �о� �ɴϴ�
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
   // ��� ����
   Save(FILENAME, students, count);
   return 0;
}
int GetMenu()
{
   int menu;
   do
   {
      printf("----------------------------------\n");
      printf("�޴��� �����ϼ���\n");
      printf("1. ���� ���� ���\n");
      printf("2. �л� �߰�\n");
      printf("3. ����\n");
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
      printf("�� �̻� �߰��� �� �����ϴ�.\n");
      return;
   }
   printf("�̸� : "); scanf("%s", s[*count-1].name);//name�ڿ��� \n�� ���Ե�.
   printf("�б� : "); scanf("%s", s[*count-1].univ);
   printf("�а� : "); scanf("%s", s[*count-1].major);
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


