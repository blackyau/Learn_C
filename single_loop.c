// 单链表 循环链表
// TODO 删除 节点
#include<stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node* next;
};

void insert(struct node* head, int index, int in); // 在值为 index 的节点后面插入值为 in 的节点
void show(struct node* head); // 打印整个链表

// 头指针在各个函数都有特殊用途，全局变量方便操作
static struct node head_data = { 0, &head_data };  // 先初始化数据
static struct node* head = &head_data; // 再新建指针指向它

void main() {
	struct node* end = (struct node*)malloc(sizeof(struct node));
	end = head;
	for (int i = 1; i < 4; i++) {
		insert(head, i - 1, i);
	}
	show(head);
	printf("\ninsert -1 after node->value == 0\n");
	insert(head, 0, -1);
	show(head);
	printf("\ninsert -1 after node->value == 1\n");
	insert(head, 1, -1);
	show(head);
	printf("\ninsert -1 after node->value == 3\n");
	insert(head, 3, -1);
	show(head);
	printf("\ninsert -1 after node->value == 6\n");
	insert(head, 6, -1);
	show(head);
} 

void insert(struct node* head, int index, int in) {
	struct node* temp = head;
	struct node* in_node = (struct node*)malloc(sizeof(struct node));
	int count = 0;
	in_node->value = in; // 初始化被插入的节点
	in_node->next = head;
	while (temp->value != index && count<2) { // 没有查找到值就继续遍历，如果是第二次来到 head 说明链表中不存在该值
		if (temp == head)++count;
		temp = temp->next; // 遍历下一个节点
	}
	if (temp->value == index && temp->next == head) { // 在尾部插入,特殊处理
		temp->next = in_node;
		return;
	}
	if (temp->value == index) { // 在头部或中部插入
		in_node->next = temp->next;
		temp->next = in_node;
	}
}

void show(struct node* head) {
	int i = 1;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	// 对头节点特殊处理，先打印出来。方便后面的遍历
	printf("node[0]:%d, next:node[1]:%d\n", temp->value, temp->next->value);
	temp = head->next; // 直接从 head 的下一节点开始
	while (temp->next != head) { // 当前节点不为头节点，才会打印。因为循环链表最后一个节点的 next 是头
		printf("node[%d]:%d, next:node[%d]:%d\n", i, temp->value, i, temp->next->value);
		temp = temp->next;
		i++;
	}
	// 对尾部节点特殊处理
	printf("node[%d]:%d, next:node[%d]:%d\n", i, temp->value, 0, temp->next->value);
}