// 链式栈
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

int push(node* stack, int data); // 向stack节点后面添加一个值为data的节点，返回0失败，非0成功
int pop(node* stack); // 弹出栈顶的值，如果为0则弹出失败，非零则成功

void main() {
	node* stack = (node*)malloc(sizeof(node));
	stack->next = NULL;
	for (int i = 1; i < 6; i++) {
		printf("%d ", push(stack, i));
	}
	printf("\n");
	for (int i = 1; i < 7; i++) { // i多1是为了检测溢出时程序运行是否正常
		printf("%d ", pop(stack));
	}
}

int push(node* stack, int data) {
	if (stack == NULL)return 0;
	node* temp = (node*)malloc(sizeof(node));
	temp->value = data;
	temp->next = NULL;
	// stack->next相当于整个链表
	// 把整个链表放在新节点的后面，就是链表的头插
	temp->next = stack->next; 
	stack->next = temp; // 把整个链表的头部，指向新插入的链表
	return 1;
}

int pop(node* stack) {
	if (stack->next == NULL)return 0;
	int result;
	node* rm_node = NULL;
	result = stack->next->value; // 取出来头节点的值
	rm_node = stack->next; // 将即将删除的节点储存起来
	stack->next = stack->next->next; // 在链表中删除节点
	free(rm_node);
	return result;
}
