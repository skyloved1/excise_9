#include <stdio.h>
#define N 3
struct Student
{
	int num; char name[20]; float score[3]; float aver;
};
int main() {
	struct Student stu[N], * p = stu;
	void input(struct Student* p);
	struct Student* max(struct Student* p);

	void print(struct Student* p);
	input(p);
	print(max(p));
}

void input(struct Student* p) {
	printf("请输入各学生的信息：学号，姓名，三门课程成绩\n");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %s %f %f %f", &(p + i)->num, &(p + i)->name, 15, (p + i)->score, ((p + i)->score) + 1, ((p + i)->score) + 2);
		//p->aver=(*(*p).score) + (*(*p).score + 1) + (*(*p).score + 2) / 3.0;
		(p + i)->aver = (*((p + i)->score) + *((p + i)->score + 1) + *((p + i)->score + 2)) / 3.0;//(p+i)->score是 结构体数组的第i个元素的score成员的地址
	}
}
struct Student* max(struct Student* p) {
	//返回平均分最高的学生
	struct Student* max = p;
	for (int i = 0; i < 3; i++)
	{
		if ((p + i)->aver > max->aver)
		{
			max = p + i;
		}
	}
	return max;
}
void print(struct Student* p) {
	// 输出平均值最大的学生信息

	printf("平均值最大的学生的学号：%d\n姓名：%s\n三门课程成绩：%f %f %f\n平均分：%f\n", p->num, p->name, *((*p).score), *((*p).score + 1), *((*p).score + 2), p->aver);
}