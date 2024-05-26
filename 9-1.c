#include <stdio.h>
int main() {
	struct date
	{
		int year; int month; int day;
	}Today_date;
	printf("Please input the date(yyyy-mm-dd):\n");
	scanf_s("%d-%d-%d", &Today_date.year, &Today_date.month, &Today_date.day);
	int sum = 0;
	int  judge_is_leap(int year);
	for (int i = 1; i < Today_date.month; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			sum += 31;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11: {
			sum += 30;
			break;
		}

		case 2: {
			sum += judge_is_leap(Today_date.year);
			break;
		}
		}
	}

	printf("The day of the year is %d\n", sum + Today_date.day);
	return 0;
}

int  judge_is_leap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 29;
	}
	else
	{
		return 28;
	}
}