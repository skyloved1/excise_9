#include <stdio.h>
#include <malloc.h>
struct Student
{
	int num;
	char name[20];
	float score;
	struct Student* next_ptr;
};
struct Student* creat_linked_list(int length) {
	struct Student* head_ptr = (struct Student*)malloc(sizeof(struct Student));
	struct Student* p1 = head_ptr, * p2 = head_ptr;
	struct Student* temp_ptr = NULL; // �޸������temp_ptr��ʼ��ΪNULL
	for (int i = 0; i < length; i++)
	{
		p2 = (struct Student*)malloc(sizeof(struct Student));
		if (p2 == NULL)
		{
			printf("�ڴ治�㣬ֹͣ����.\n");
			break;
		}
		// temp_ptr ��¼��һ���ڵ��next_ptr
		temp_ptr = p1;
		p1->next_ptr = p2;
		//��ʼ������
		scanf_s("%d %s %f", &(p1->num), &(p1->name), 15, &(p1->score));
		//ָ������
		p1 = p2;
	}
	temp_ptr->next_ptr = NULL;

	return head_ptr;
}

void print_linked_list(struct Student* head_ptr) {
	struct Student* p1 = head_ptr;
	while (p1 != NULL)
	{
		printf("%d\t %s\t %.2f\n", p1->num, p1->name, p1->score);
		struct Student* temp = p1;
		p1 = p1->next_ptr;
	}
}

struct Student* insert_linked_list(struct Student* head_ptr) {
	//Ĭ�����������
	struct Student* p1 = head_ptr;
	printf("������Ҫ���������");
	struct Student* inserted_ptr = (struct Student*)malloc(sizeof(struct Student));
	if (inserted_ptr == NULL)
	{
		printf("�ڴ治�㣬�޷�����.\n");
		return head_ptr;
	}
	scanf_s("%d %s %f", &inserted_ptr->num, &inserted_ptr->name, 15, &inserted_ptr->score);
	printf("������Ҫ�����λ�ã�ѧ�Ŵ���.\n");
	int num;
	scanf_s("%d", &num);
	//��ʱ�洢 �洢��һ���ڵ��λ��
	struct Student* temp_ptr = NULL;
	while (p1 != NULL)
	{
		temp_ptr = p1;
		//Ѱ�ұ�����ĵ�ַ
		if (num == p1->num)
		{
			break;
		}
		p1 = p1->next_ptr;
	}
	//����ǵ�һ���ڵ�
	if (p1 == head_ptr)
	{
		inserted_ptr->next_ptr = head_ptr;
		head_ptr = inserted_ptr;
		return head_ptr;
	}
	//������м�Ľڵ�
	struct Student* next_node = p1->next_ptr;
	inserted_ptr->next_ptr = next_node;
	temp_ptr->next_ptr = inserted_ptr;

	return head_ptr;
}

struct Student* delete_linked_list(struct Student* head_ptr) {
	struct Student* p1 = head_ptr;
	printf("������Ҫɾ����ѧ��\n");
	int num;
	scanf_s("%d", &num);
	//��ʱ�洢 �洢��һ���ڵ��λ��
	struct Student* temp_ptr = NULL;
	while (p1 != NULL)
	{
		//Ѱ�ұ�ɾ���Ľڵ�
		if (num == p1->num)
		{
			break;
		}
		temp_ptr = p1;
		p1 = p1->next_ptr;
	}
	//����ҵ���Ҫɾ���Ľڵ�
	if (p1 != NULL)
	{
		//���Ҫɾ���Ľڵ��ǵ�һ���ڵ�
		if (p1 == head_ptr)
		{
			head_ptr = head_ptr->next_ptr;
		}
		else
		{
			temp_ptr->next_ptr = p1->next_ptr;
		}
		free(p1);
	}
	return head_ptr;
}

int main() {
	printf("������������");
	int length;
	scanf_s("%d", &length);
	struct Student* head_ptr;
	head_ptr = creat_linked_list(length);
	print_linked_list(head_ptr);

	head_ptr = insert_linked_list(head_ptr);
	//����֮���ڵ����
	print_linked_list(head_ptr);

	//ɾ��
	head_ptr = delete_linked_list(head_ptr);
	print_linked_list(head_ptr);

	//�ͷ�����
	struct Student* p1 = head_ptr;
	while (p1 != NULL)
	{
		struct Student* temp = p1;
		p1 = p1->next_ptr;
		free(temp);
	}
	return 0;
}