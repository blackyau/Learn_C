//单链表 查找数值 删除指定值的节点
//struct 的自定义函返回值还不明白
#include<stdio.h>
#include<stdlib.h>
//先写函数原型,后面再写函数定义（主体）

struct node{
	int value;
	struct node* next;
};

struct node find_index(struct node* head, int index); // 传入头节点指针和要查找的值,返回匹配的节点指针

void main() {
	struct node* head = (struct node*)malloc(sizeof(struct node*));
	struct node* a = head;
	for (int i = 1; i < 5; i++) { // 初始化链表,装填数据
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->value = i;
		temp->next = NULL;
		a->next = temp;
		a = a->next; //将新插入的节点设为链尾,方便下一次插入
	}
	struct node find_result = find_index(head, 3);
	printf("now:%d\n", find_result.value);
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp = find_result.next;
	printf("next:%d\n", temp->value);
}

struct node find_index(struct node* head, int index) {
	struct node* temp = head;
	// 当前链表没有到尾部，同时与要查找的值不匹配，就跳到下一节点
	while (temp != NULL && temp->value != index) {
		temp = temp->next;
	}
	return *temp; // 保持返回值一致,无论是否找到都要返回,需要检查返回值是不是头指针
}
