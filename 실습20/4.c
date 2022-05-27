#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
	int accNum;
	char name[30];
	double balance;
}account;


void printAcc(account a) {
	printf("%d %s %.2lf\n", a.accNum, a.name, a.balance);
}

void load(account acc[], int* cnt, FILE* file) {
	(*cnt) = -1;
	while (fread(&acc[++(*cnt)], sizeof(account), 1, file));
}

void add(account acc[], int* cnt, FILE* file) {
	fseek(file, 0, SEEK_END);
	while (1) {
		scanf("%d", &acc[*cnt].accNum);
		if (acc[*cnt].accNum == -1)
			break;
		scanf("%s %lf", acc[*cnt].name, &acc[*cnt].balance);
		fwrite(&acc[*cnt], sizeof(account), 1, file);
		(*cnt)++;
	}
}

int findIndexFromName(account acc[], int cnt, char* name) {
	int index = -1;
	while (++index<cnt&&strcmp(acc[index].name, name));

	return index<cnt?index:-1;
}

void search(account acc[], int* cnt, FILE* file) {
	char name[50];
	scanf("%s", name);
	if (findIndexFromName(acc, *cnt, name) != -1)
		printAcc(acc[findIndexFromName(acc,*cnt,name)]);
}

void deposit(account acc[], int* cnt, FILE* file) {
	char name[50];
	double m;
	scanf("%s %lf", name,&m);
	int index = findIndexFromName(acc, *cnt, name);
	acc[index].balance += m;
	printAcc(acc[index]);
	fseek(file, sizeof(account)*index, SEEK_SET);
	fwrite(&acc[index], sizeof(account), 1, file);
}

void withdraw(account acc[], int* cnt, FILE* file) {
	char name[50];
	double m;
	scanf("%s %lf", name, &m);
	int index = findIndexFromName(acc, *cnt, name);
	acc[index].balance -= m;
	printAcc(acc[index]);
	fseek(file, sizeof(account) * index, SEEK_SET);
	fwrite(&acc[index], sizeof(account), 1, file);
}

void printAll(account acc[], int* cnt, FILE* file) {
	double sum = 0;
	for (int i = 0; i < *cnt; i++)
		sum += acc[i].balance;
	printf("Total=%.2lf\n", sum);
	for (int i = 0; i < *cnt; i++)
		printAcc(acc[i]);
}

void (*menu[5])(account*, int*, FILE*) = { add,search, deposit,withdraw,printAll };

void main() {
	account acc[100] = { 0 };
	int n, cnt;
	FILE* file = fopen("bank.bin", "rb+");
	if(!file)
		file = fopen("bank.bin", "w");
	load(&acc, &cnt, file);
	while (scanf("%d", &n)&&n>0&&n<6)
		menu[n-1](&acc, &cnt, file);

	fclose(file);
}
