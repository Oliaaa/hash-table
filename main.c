#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "head.h"

int main()
{
	int k = 0;
	setlocale(LC_ALL, "Russian");

	table t[N], x;
	int pl = 0;

	for (int i = 0; i < N; i++)
	{
		t[i].code[0] = '\0';
		t[i].name[0] = '\0';
		t[i].numb = 0;
	}

	FILE *f = fopen("work.txt", "r");

	while (fscanf(f, "%s %s %d", x.code, x.name, &x.numb) != EOF && pl != -1)
		pl  = table_add(t, x);

	fclose(f);

	f = fopen("table.txt", "w");

	for (int i = 0; i < N && pl != -1; i++)
	{
		if (t[i].code[0] != '\0')
		{
			k = hash_znach(t, t[i].code);
			fprintf(f, "%d %d\t%s\t%s\t%i\n", i, k, t[i].code, t[i].name, t[i].numb);
		}
	}
	if (pl != -1)
		printf("The program is executed, the table is in the file 'table.txt'\n");
	else
		fprintf(f, "Table not built");

	return 0;
}
