// 单链表 循环链表
// TODO 插入/删除 节点
#include<stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node* next;
};

struct node* insert(struct node* now, int in); // 在给予的节点后面插入值，并返回插入后的节点指针
void show(struct node* head); // 打印整个链表

static struct node head_data = { 0, NULL };
static struct node* head = &head_data;

void main() {
	struct node* end = (struct node*)malloc(sizeof(struct node));
	end = head;
	for (int i = 1; i < 6; i++) {
		end = insert(end, i);
	}
	show(head);
}

struct node* insert(struct node* now, int in) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->value = in;
	temp->next = head;
	now->next = temp;
	return now->next;
}

void show(struct node* head) {
	int i = 1;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	printf("node[0]:%d, next:node[1]:%d\n", temp->value, temp->next->value);
	temp = head->next;
	while (temp != head) {
		printf("node[%d]:%d, next:node[i]:%d\n", i, temp->value, temp->next->value);
		temp = temp->next;
		i++;
	}
}