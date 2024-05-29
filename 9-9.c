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
	struct Student* temp_ptr = NULL; // 修改这里，将temp_ptr初始化为NULL
	for (int i = 0; i < length; i++)
	{
		p2 = (struct Student*)malloc(sizeof(struct Student));
		if (p2 == NULL)
		{
			printf("内存不足，停止申请.\n");
			break;
		}
		// temp_ptr 记录上一个节点的next_ptr
		temp_ptr = p1;
		p1->next_ptr = p2;
		//初始化数据
		scanf_s("%d %s %f", &(p1->num), &(p1->name), 15, &(p1->score));
		//指针下移
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
	//默认往后面插入
	struct Student* p1 = head_ptr;
	printf("请输入要插入的数据");
	struct Student* inserted_ptr = (struct Student*)malloc(sizeof(struct Student));
	if (inserted_ptr == NULL)
	{
		printf("内存不足，无法插入.\n");
		return head_ptr;
	}
	scanf_s("%d %s %f", &inserted_ptr->num, &inserted_ptr->name, 15, &inserted_ptr->score);
	printf("请输入要插入的位置（学号处）.\n");
	int num;
	scanf_s("%d", &num);
	//临时存储 存储上一个节点的位置
	struct Student* temp_ptr = NULL;
	while (p1 != NULL)
	{
		temp_ptr = p1;
		//寻找被插入的地址
		if (num == p1->num)
		{
			break;
		}
		p1 = p1->next_ptr;
	}
	//如果是第一个节点
	if (p1 == head_ptr)
	{
		inserted_ptr->next_ptr = head_ptr;
		head_ptr = inserted_ptr;
		return head_ptr;
	}
	//如果是中间的节点
	struct Student* next_node = p1->next_ptr;
	inserted_ptr->next_ptr = next_node;
	temp_ptr->next_ptr = inserted_ptr;

	return head_ptr;
}

struct Student* delete_linked_list(struct Student* head_ptr) {
	struct Student* p1 = head_ptr;
	printf("请输入要删除的学号\n");
	int num;
	scanf_s("%d", &num);
	//临时存储 存储上一个节点的位置
	struct Student* temp_ptr = NULL;
	while (p1 != NULL)
	{
		//寻找被删除的节点
		if (num == p1->num)
		{
			break;
		}
		temp_ptr = p1;
		p1 = p1->next_ptr;
	}
	//如果找到了要删除的节点
	if (p1 != NULL)
	{
		//如果要删除的节点是第一个节点
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
	printf("请输入链表长度");
	int length;
	scanf_s("%d", &length);
	struct Student* head_ptr;
	head_ptr = creat_linked_list(length);
	print_linked_list(head_ptr);

	head_ptr = insert_linked_list(head_ptr);
	//插入之后在的输出
	print_linked_list(head_ptr);

	//删除
	head_ptr = delete_linked_list(head_ptr);
	print_linked_list(head_ptr);

	//释放链表
	struct Student* p1 = head_ptr;
	while (p1 != NULL)
	{
		struct Student* temp = p1;
		p1 = p1->next_ptr;
		free(temp);
	}
	return 0;
}