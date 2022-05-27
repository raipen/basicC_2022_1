#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int std_id;
	char name[30];
	double score[3];
	double total;
}student;

void printStudent(student s) {
	printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", s.std_id, s.name, s.score[0], s.score[1], s.score[2], s.total);
}

void main() {

	FILE* fp1, * fp2;
	student st[10] = { 0 };
	char f1[50], f2[50], name[50];

	//인풋파일이름 입력, 아웃풋파일이름 입력
	scanf("%s %s", f1, f2);

	fp1 = fopen(f1, "rb");
	fp2 = fopen(f2, "wb");
	
	//인풋파일로부터 fread로 struct student[]에 값들 입력받고
	int size = -1;
	while (fread(&st[++size], sizeof(student), 1, fp1));

	// 그 값들을 바로 아웃풋에 fwrite 하기
	fwrite(st, sizeof(student), size, fp2);


	//변경할 데이터의 이름 입력받기
	scanf("%s", name);
	//변경할 데이터 위치 찾기
	int find = -1;
	while (strcmp(st[++find].name, name)&&find<size);
	if (find >= size)
		exit(0);
	printStudent(st[find]);

	//점수 새로 입력 받기
	st[find].total = 0;
	for (int i = 0; i < 3 && scanf("%lf", &st[find].score[i]); st[find].total += st[find].score[i], i++);

	//덮어씌울 곳 찾기
	fseek(fp2, sizeof(student) * find, SEEK_SET);
  //
	fwrite(&st[find], sizeof(student), 1, fp2);

	//전체 출력
	for (int i = 0; i < size; i++)
		printStudent(st[i]);

	fclose(fp1);
	fclose(fp2);

}
