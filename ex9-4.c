#include <stdio.h>
struct Student
{
	int num;
	char name[20];
	float score;
};
int main() {
	struct Student stu[3] = { {101,"zhang",78},{102,"Wang",98.5},{103,"Ling",86} };
	struct Student temp;
	const int n = 3;
	int i, j, k;
	printf("The order is :\n");
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].score > stu[k].score)
			{
				k = j;
			}
		}
		temp = stu[k]; stu[k] = stu[i]; stu[i] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%.2f\n", stu[i].num, stu[i].name, stu[i].score);
	}

	return 0;
}