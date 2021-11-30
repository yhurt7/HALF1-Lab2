#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 

int main()
{
  setlocale(LC_ALL, "Russian");

  int i = 0, n = 0, min = 0, max = 0;
  unsigned char* mas;

  printf("������� ���������� ����� ");
  scanf("%d", &n);
  printf("������� ����������� ����� ���������(�� 1 �� 255) ");
  scanf("%d", &min);
  printf("������� ������������ ����� ���������(�� 1 �� 255) ");
  scanf("%d", &max);
  printf("\n");

  if ((max <= min) || (max > 255) || (min > 255) || (min <= 0) || (n <= 0) || (max <= 0))
  {
    printf("������: ������������ ������\n");
    return 0;
  }

  mas = (unsigned char*)malloc(n * sizeof(unsigned char));

  for (i = 0; i < n; i++)
  {
    mas[i] = (((((double)rand()) / RAND_MAX) * (max - min)) + min);
  }


  FILE* file;
  file = fopen("numbers.txt", "w+");

  fprintf(file, "%d\n", n);

  for (i = 0; i < n; i++)
  {
    fprintf(file, "%d\n", mas[i]);
  }

  printf("����� ������� �������������!\n ");

  free(mas);
  fclose(file);
  return 0;
}