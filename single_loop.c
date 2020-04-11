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

// 头指针在各个函数都有特殊用途，全局变量方便操作
static struct node head_data = { 0, NULL };  // 先初始化数据
static struct node* head = &head_data; // 再新建指针指向它

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
	temp->next = head; // 尾节点的 next 不是 NULL 而是头
	now->next = temp; // 将新建节点连接到传入节点的后面
	return now->next; // 返回最新的尾节点
}

void show(struct node* head) {
	int i = 1;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	// 对头节点特殊处理，先打印出来。方便后面的遍历
	printf("node[0]:%d, next:node[1]:%d\n", temp->value, temp->next->value);
	temp = head->next; // 直接从 head 的下一节点开始
	while (temp != head) { // 当前节点不为头节点，才会打印。因为循环链表最后一个节点的 next 是头
		printf("node[%d]:%d, next:node[i]:%d\n", i, temp->value, temp->next->value);
		temp = temp->next;
		i++;
	}
}