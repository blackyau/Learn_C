// 双向链表
// TODO 任意位置插入 删除
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* prior;
	int value;
	struct Node* next;
}Node;


Node* InitNode(Node *L, int data); // 将以data为值的节点插入到L的下一节点
void show(Node* head); // 打印整个链表

void main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->value = 0;
	head->next = NULL;
	head->prior = NULL;
	Node* temp = head;
	for (int i = 1; i < 6; i++) {
		temp = InitNode(temp, i);
	}
	show(head);
}

Node* InitNode(Node *L, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = data;
	if (L) { // 如果L不为空
		L->next = temp; // 将要插入的节点连接到L后面
		temp->prior = L; // 将要插入节点的上一节点设为L
		temp->next = NULL; // 新节点都在尾部,所以next为NULL
	}
	return temp;
}

void show(Node* head) {
	Node* temp = head;
	int i = 0;
	// 对头节点打印的特殊处理，因为头节点的prior为NULL
	printf("Node[%d]->prior:NULL, Node[%d]->value:%d, Node[%d]->next:%4d\n", i, i, temp->value, i, temp->next->value);
	temp = temp->next;
	while (temp->next != NULL) {
		++i;
		printf("Node[%d]->prior:%4d, Node[%d]->value:%d, Node[%d]->next:%4d\n", i, temp->prior->value, i, temp->value, i, temp->next->value);
		temp = temp->next;
	}
	++i;
	// 对尾节点的特殊处理
	printf("Node[%d]->prior:%4d, Node[%d]->value:%d, Node[%d]->next:NULL\n", i, temp->prior->value, i, temp->value, i);
}