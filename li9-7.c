#include <stdio.h>
#define N 3
struct Student
{
	int num; char name[20]; float score[3]; float aver;
};
int main() {
	void input(struct Student stu[]);
	struct Student max(struct Student stu[]);
	void print(struct Student stu);

	struct Student stu[N], * p = stu;
	input(stu);
	print(max(stu));

	return 0;
}
void input(struct Student stu[]) {
	printf("请输入各学生的信息：学号，姓名，三门课程成绩\n");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %s %f %f %f", &stu[i].num, &stu[i].name, 15, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
	}
}
struct Student max(struct Student stu[]) {
	int i, m = 0;
	for (i = 0; i < N; i++)
	{
		if (stu[i].aver > stu[m].aver)
			m = i;
	}
	return stu[m];
}
void print(struct Student stu) {
	printf("成绩最好的学生学号：%d 姓名：%s \n三门课成绩:%5.1f,%5.1f,%5.1f\n三门课程平均分：%5.2f\n", stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2], stu.aver);
}