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
	printf("�������ѧ������Ϣ��ѧ�ţ����������ſγ̳ɼ�\n");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %s %f %f %f", &(p + i)->num, &(p + i)->name, 15, (p + i)->score, ((p + i)->score) + 1, ((p + i)->score) + 2);
		//p->aver=(*(*p).score) + (*(*p).score + 1) + (*(*p).score + 2) / 3.0;
		(p + i)->aver = (*((p + i)->score) + *((p + i)->score + 1) + *((p + i)->score + 2)) / 3.0;//(p+i)->score�� �ṹ������ĵ�i��Ԫ�ص�score��Ա�ĵ�ַ
	}
}
struct Student* max(struct Student* p) {
	//����ƽ������ߵ�ѧ��
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
	// ���ƽ��ֵ����ѧ����Ϣ

	printf("ƽ��ֵ����ѧ����ѧ�ţ�%d\n������%s\n���ſγ̳ɼ���%f %f %f\nƽ���֣�%f\n", p->num, p->name, *((*p).score), *((*p).score + 1), *((*p).score + 2), p->aver);
}