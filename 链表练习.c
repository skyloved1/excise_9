#include <stdio.h>
#include <malloc.h>
struct Student
{
	int num;
	char name[20];
	int score1, score2, score3;
	struct Student* next_ptr;
};
struct Student* creat_linked_list(int length) {
	printf("������������.\n");
	struct Student* head = (struct Student*)malloc(length * sizeof(struct Student));//�ȷ���ͷָ��
	struct Student* p1 = head, * p2 = NULL;
	for (int i = 0; i < length; i++)
	{
		struct Student* p2 = (struct Student*)malloc(length * sizeof(struct Student));
		p1->next_ptr = p2;
		p1 = p2;
	}
	//�����һ���ڵ��next_ptr����ΪNULL
	p1->next_ptr = NULL;
	return head;
}
void enter_data(struct Student* head) {
	struct Student* temp_ptr = head; int count = 1;
	while (temp_ptr->next_ptr != NULL)
	{
		printf("�������%d������ڵ������\n", count++);
		scanf_s("%d %s %d %d %d", &temp_ptr->num, &temp_ptr->name, 15, &temp_ptr->score1, &temp_ptr->score2, &temp_ptr->score3);
		temp_ptr = temp_ptr->next_ptr;
	}
}
void print_linked_list(struct Student* head) {
	struct Student* temp_ptr = head; int count = 1;
	while (temp_ptr->next_ptr != NULL)
	{
		printf("��%d������ڵ������\n", count++);
		printf("%d %s %d %d %d\n", temp_ptr->num, temp_ptr->name, temp_ptr->score1, temp_ptr->score2, temp_ptr->score3);
		temp_ptr = temp_ptr->next_ptr;
	}
}
void free_linked_list(struct Student* head) {
	struct Student* temp_ptr = head;
	struct Student* temp_ptr2 = NULL;
	while (temp_ptr->next_ptr != NULL) {
		temp_ptr2 = temp_ptr;
		temp_ptr = temp_ptr->next_ptr;
		free(temp_ptr2);
	}
}
int main() {
	int length = 0;
	printf("������������\n");
	scanf_s("%d", &length);
	struct Student* head = creat_linked_list(length);
	enter_data(head);
	print_linked_list(head);
	free_linked_list(head);
	return 0;
}