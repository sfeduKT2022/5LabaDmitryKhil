/*
а) Дополнение существующего массива структур новыми структурами;
б) Поиск структуры с заданным значением выбранного элемента;
в) Вывод на экран содержимого массива структур;
г) Упорядочение массива структур по заданному полю (элементу),
например государство по численности.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
const int N = 40;
const int strLen = 1000;
struct Students {
	char surname[strLen];//Фамилия
	char name[strLen];//Имя
	char patronymic[strLen];//Отчество
	char faculty[strLen];//Факультет
	char department[strLen];//Кафедра
	char group[strLen];//Группа
	char progress[strLen];//Успеваемость
	char country[strLen];//Страна
	char region[strLen];//Область
	char town[strLen];//Город
	char street[strLen];//Улица
	int day;//День рождения
	int month;//Месяц рождения
	int year;//Год рождения
	int numHouse;//Номер дома
};
typedef Students* StudentsPtr; //Новый тип данных

//фун. ввода и вывода
void entryInfo(StudentsPtr p[], int cntUser, int cnt) {
	for (int i = cntUser; i < cntUser + cnt; i++)
	{
		printf_s("User number:%d\n", i + 1);
		printf_s("Input surname:");
		scanf_s("%s", p[i]->surname, strLen);
		printf_s("Input name:");
		scanf_s("%s", p[i]->name, strLen);
		printf_s("Input patronymic:");
		scanf_s("%s", p[i]->patronymic, strLen);
		printf_s("Input faculty:");
		scanf_s("%s", p[i]->faculty, strLen);
		printf_s("Input department:");
		scanf_s("%s", p[i]->department, strLen);
		printf_s("Input group:");
		scanf_s("%s", p[i]->group, strLen);
		printf_s("Input progress (bad, fair, good, excellent):");
		scanf_s("%s", p[i]->progress, strLen);
		printf_s("Input birthday (date,month,year):");
		scanf_s("%d%*1[.]%d%*1[.]%d", &p[i]->day, &p[i]->month, &p[i]->year, strLen);
		printf_s("Input your location (country,region,town,street,numHouse):");
		scanf_s("%s", p[i]->country, strLen);
		scanf_s("%s", p[i]->region, strLen);
		scanf_s("%s", p[i]->town, strLen);
		scanf_s("%s", p[i]->street, strLen);
		scanf_s("%d", &p[i]->numHouse);
		printf("\n");
	}
}
void outfileInfo(StudentsPtr y[], int cntUser, int cnt) {
	FILE* out;
	out = fopen("test.txt", "wb");
	printf("%d %d", cntUser, cnt);
	printf("\n");
	for (int j = 0; j < cntUser; j++)
	{
		fprintf(out, "User number:%d\n", j + 1);
		fprintf_s(out, "Input surname:");
		fprintf(out, y[j]->surname);
		fprintf(out, "\n");
		fprintf_s(out, "Input name:");
		fprintf(out, y[j]->name);
		fprintf(out, "\n");
		printf_s("Input patronymic:");
		fprintf(out, y[j]->patronymic);
		fprintf(out, "\n");
		printf_s("Input faculty:");
		fprintf(out, y[j]->faculty);
		fprintf(out, "\n");
		printf_s("Input department:");
		fprintf(out, y[j]->department);
		fprintf(out, "\n");
		printf_s("Input group:");
		fprintf(out, y[j]->group);
		fprintf(out, "\n");
		printf_s("Input progress (bad, fair, good, excellent):");
		fprintf(out, y[j]->progress);
		fprintf(out, "\n");
		fprintf_s(out, "Input birthday:");
		fprintf(out, "%02d.%02d.%04d", y[j]->day, y[j]->month, y[j]->year);
		fprintf(out, "\n");
		fprintf_s(out, "Input your location (country,region,town,street,numHouse):");
		fprintf(out, y[j]->country);
		fprintf(out, "\t");
		fprintf(out, y[j]->region);
		fprintf(out, "\t");
		fprintf(out, y[j]->town);
		fprintf(out, "\t");
		fprintf(out, y[j]->street);
		fprintf(out, "\t");
		fprintf(out, "%d", y[j]->numHouse);
		fprintf(out, "\n-----------------------------------------------------------------------\n");
	}
	fclose(out);
}
void outInfo(StudentsPtr w[], int cntUser, int cnt) {
	printf("%d %d", cntUser, cnt);
	for (int u = 0; u < cntUser; u++)
	{
		printf("User number:%d\n", u + 1);
		printf_s("Input surname:");
		printf(w[u]->surname);
		printf("\n");
		printf_s("Input name:");
		printf(w[u]->name);
		printf("\n");
		printf_s("Input patronymic:");
		printf(w[u]->patronymic);
		printf("\n");
		printf_s("Input faculty:");
		printf(w[u]->faculty);
		printf("\n");
		printf_s("Input department:");
		printf(w[u]->department);
		printf("\n");
		printf_s("Input group:");
		printf(w[u]->group);
		printf("\n");
		printf_s("Input progress (bad, fair, good, excellent):");
		printf(w[u]->progress);
		printf("\n");
		printf_s("Input birthday:");
		printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
		printf("\n");
		printf_s("Input your location (country,region,town,street,numHouse):");
		printf(w[u]->country);
		printf("\t");
		printf(w[u]->region);
		printf("\t");
		printf(w[u]->town);
		printf("\t");
		printf(w[u]->street);
		printf("\t");
		printf("%d", w[u]->numHouse);
		printf("\n-----------------------------------------------------------------------\n");
	}
}

//Процедуры сортировки от меньшего к большему значению
//Сортировка пузырьком
void sortname(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->name, k[j + 1]->name) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortsname(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->surname, k[j + 1]->surname) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortpatronymic(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->patronymic, k[j + 1]->patronymic) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortfaculty(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->faculty, k[j + 1]->faculty) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortdepartment(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->department, k[j + 1]->department) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortgroup(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->group, k[j + 1]->group) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortprogress(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->progress, k[j + 1]->progress) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortcountry(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->country, k[j + 1]->country) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortregion(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->region, k[j + 1]->region) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sorttown(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->town, k[j + 1]->town) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortstreet(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (strcmp(k[j]->street, k[j + 1]->street) > 0) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}
void sortdate(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (k[j + 1]->year < k[j]->year) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
			if (k[j + 1]->year == k[j]->year) {
				if (k[j + 1]->month < k[j]->month) {
					temp = k[j];
					k[j] = k[j + 1];
					k[j + 1] = temp;
				}
				if (k[j + 1]->month == k[j]->month) {
					if (k[j + 1]->day < k[j]->day) {
						temp = k[j];
						k[j] = k[j + 1];
						k[j + 1] = temp;
					}
				}
			}
		}
	}
}
void sortnumhouse(StudentsPtr k[], int cntUser, int cnt) {
	int i, j;
	StudentsPtr temp;
	for (int i = 0; i < cntUser - 1; i++) {
		for (int j = cntUser - 2; j >= i; j--)
		{
			if (k[j + 1]->numHouse < k[j]->numHouse) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
	}
}


//Процедуры поиска по структуре
void searchbysname(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input surname:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->surname, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbyname(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input name:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->name, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbypatronymic(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input patronymic:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->patronymic, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbyfaculty(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input faculty:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->faculty, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbydepartment(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input department:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->department, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbygroup(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input group:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->group, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbyprogress(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input progress(bad, fair, good, excellent):");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->progress, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbycountry(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input country:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->country, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbyregion(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input region:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->region, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbytown(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input town:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->town, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
void searchbystreet(StudentsPtr w[], int cntUser, int cnt) {
	char fstr[100];
	printf("Please input street:");
	scanf(" %s", fstr);
	for (int u = 0; u < cntUser; u++) {
		if (strcmp(w[u]->street, fstr) == 0) {
			printf("User number:%d\n", u + 1);
			printf_s("Input surname:");
			printf(w[u]->surname);
			printf("\n");
			printf_s("Input name:");
			printf(w[u]->name);
			printf("\n");
			printf_s("Input patronymic:");
			printf(w[u]->patronymic);
			printf("\n");
			printf_s("Input faculty:");
			printf(w[u]->faculty);
			printf("\n");
			printf_s("Input department:");
			printf(w[u]->department);
			printf("\n");
			printf_s("Input group:");
			printf(w[u]->group);
			printf("\n");
			printf_s("Input progress (bad, fair, good, excellent):");
			printf(w[u]->progress);
			printf("\n");
			printf_s("Input birthday:");
			printf("%02d.%02d.%04d", w[u]->day, w[u]->month, w[u]->year);
			printf("\n");
			printf_s("Input your location (country,region,town,street,numHouse):");
			printf(w[u]->country);
			printf("\t");
			printf(w[u]->region);
			printf("\t");
			printf(w[u]->town);
			printf("\t");
			printf(w[u]->street);
			printf("\t");
			printf("%d", w[u]->numHouse);
			printf("\n-------------------------------------------------------------------\n");
		}
	}
}
int main() {
	Students B[N];
	StudentsPtr p[N];
	char m, f, command[100], search[100];
	char date[100] = { "date" };
	char surname[100] = { "surname" }, name[100] = { "name" }, patronymic[100] = { "patronymic" };
	char faculty[100] = { "faculty" }, department[100] = { "department" }, group[100] = { "group" }, progress[100] = { "progress" };
	char country[100] = { "country" }, region[100] = { "region" }, town[100] = { "town" }, street[100] = { "street" }, numh[100] = { "numh" };
	int count = 0, countUser = 0;
	bool flag = true, flags = true;
	//Заполнение указ.
	for (int i = 0; i < N; i++) {
		//отдел.струк
		p[i] = &B[i];
	}

	while (flag) {
		printf_s("Do you want to add other users?[y/n/e]");
		scanf_s(" %c", &m);
		if (m == 'y') {
			printf("Input amount users:");
			scanf_s("%d", &count);
			entryInfo(p, countUser, count);
			countUser += count;
			flags = true;
		}
		if (m == 'n' && flags) {
			printf_s("Do you need sort? click - [s]\n");
			printf_s("Do you need search? click - [q]\n");
			scanf_s(" %c", &f);
			if (f == 's') {
				printf_s("Choose the sort you want [name sort - command]\n");
				printf_s("Sort by name - name\n");
				printf_s("Sort by surname - surname\n");
				printf_s("Sort by patronymic - patronymic\n");
				printf_s("Sort by faculty - faculty\n");
				printf_s("Sort by department - department\n");
				printf_s("Sort by group - group\n");
				printf_s("Sort by progress - progress\n");
				printf_s("Sort by country - country\n");
				printf_s("Sort by region - region\n");
				printf_s("Sort by town - town\n");
				printf_s("Sort by street - street\n");
				printf_s("Sort by number house - numh\n");
				printf_s("Sort by birthday - date\n");
				scanf(" %s", command);
				if (strcmp(command, name) == 0) {
					sortname(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, surname) == 0) {
					sortsname(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, patronymic) == 0) {
					sortpatronymic(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, faculty) == 0) {
					sortfaculty(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, department) == 0) {
					sortdepartment(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, group) == 0) {
					sortgroup(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, progress) == 0) {
					sortprogress(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, country) == 0) {
					sortcountry(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, region) == 0) {
					sortregion(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, town) == 0) {
					sorttown(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, street) == 0) {
					sortstreet(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, numh) == 0) {
					sortnumhouse(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
				if (strcmp(command, date) == 0) {
					sortdate(p, countUser, count);
					outInfo(p, countUser, count);
					printf_s("Sort completed\n");
				}
			}
			if (f == 'q') {
				printf("What element to look for:\n");
				printf_s("Sort by name - name\n");
				printf_s("Sort by surname - surname\n");
				printf_s("Sort by patronymic - patronymic\n");
				printf_s("Sort by faculty - faculty\n");
				printf_s("Sort by department - department\n");
				printf_s("Sort by group - group\n");
				printf_s("Sort by progress - progress\n");
				printf_s("Sort by country - country\n");
				printf_s("Sort by region - region\n");
				printf_s("Sort by town - town\n");
				printf_s("Sort by street - street\n");
				scanf(" %s", search);
				if (strcmp(search, surname) == 0) {
					searchbysname(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, name) == 0) {
					searchbyname(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, patronymic) == 0) {
					searchbypatronymic(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, faculty) == 0) {
					searchbyfaculty(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, patronymic) == 0) {
					searchbypatronymic(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, group) == 0) {
					searchbygroup(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, progress) == 0) {
					searchbyprogress(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, country) == 0) {
					searchbycountry(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, region) == 0) {
					searchbyregion(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, town) == 0) {
					searchbytown(p, countUser, count);
					printf_s("Search completed\n");
				}
				if (strcmp(search, street) == 0) {
					searchbystreet(p, countUser, count);
					printf_s("Search completed\n");
				}
			}
			if (f == 'e') {
				flags = false;
			}
		}
		if (m == 'e') {
			flag = false;
		}
	}
	outfileInfo(p, countUser, count);
	return 0;
}