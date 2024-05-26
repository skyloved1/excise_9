#include <stdio.h>
int main() {
	struct student
	{
		long long int mun; char name[20];
		char sex;
		char addr[20];
	};
	struct student student1, student2;
	printf("fist student:\n");
	scanf_s("%lld %s %c", &student1.mun, student1.name, 19, &student1.sex);
	printf("second student:\n");
	scanf_s("%lld %s %c", &student2.mun, student2.name, 19, &student2.sex);

	if (student1.mun > student2.mun)
	{
		printf("第一个学生大.\n");
	}
	sexd
	else
	{
		printf("第二个学生大.\n");
	}
}