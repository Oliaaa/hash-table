#pragma once
#include <string.h>
#include <locale.h>

const int  N = 20;

struct table
{
	char code[9];
	char name[20];
	int numb;
};

int hash_znach(table *t, char *code)
{
	int sym = 0, hash = 0;
	for (int i = 0; i < 9; i++)
		sym += code[i];
	hash = sym % N;

	return hash;
}

int search_key(table *t, table x, int hash)
{
	int k = hash, i = 0, b = 1;

	do
	{
		if (strlen(t[hash].code) == 0)
		{
			b = 0;
			return hash;
		}

		if (strcmp(x.code, t[hash].code) == 0)
		{
			b = 0;
			return -2;
		}

		else
		{
			i++;
			hash = (hash + i) % N;
		}
	} while (b && hash != k);

	return -1;
}



int table_add(table *t, table x)
{
	int sym = 0, hash = 0, place = 0;

	hash = hash_znach(t, x.code);

	place = search_key(t, x, hash);

	if (place != -1)
	{
		if (place == -2)
			t[hash].numb += x.numb;
		else
			{
				strcpy(t[place].code, x.code);
				strcpy(t[place].name, x.name);
				t[place].numb = x.numb;
			}
	}
	else
		return -1;

	return 0;
}
