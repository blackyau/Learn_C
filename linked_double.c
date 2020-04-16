// 双向链表
// TODO 任意位置插入 删除
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* prior;
	int value;
	struct Node* next;
}Node;

static int now = 0; // 从head开始数起，当前指针指向第几个节点
Node* InitNode(Node *L, int data); // 将以data为值的节点插入到L的下一节点
void insert(Node* L, int index, int data); // 为L链表中index下标的next插入一个value为data的节点
void show(Node* head); // 打印整个链表

void main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->value = 0;
	head->next = NULL;
	head->prior = NULL;
	Node* temp = head;
	for (int i = 1; i < 4; i++) {
		temp = InitNode(temp, i);
	}
	show(head);
	printf("\ninser -1 after node[1]\n");
	insert(temp, 1, -1);
	show(head);
	printf("\ninser -1 after node[4]\n");
	insert(temp, 4, -1);
	show(head);
	printf("\ninser -1 after node[3]\n");
	insert(temp, 3, -1);
	show(head);
}

Node* InitNode(Node *L, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = data;
	if (L) { // 如果L不为空
		L->next = temp; // 将要插入的节点连接到L后面
		temp->prior = L; // 将要插入节点的上一节点设为L
		temp->next = NULL; // 新节点都在尾部,所以next为NULL
		++now;
	}
	return temp;
}

void show(Node* head) {
	Node* temp = head;
	int i = 0;
	// 对头节点打印的特殊处理，因为头节点的prior为NULL
	printf("Node[%d]->prior:NULL, Node[%d]->value:%2d, Node[%d]->next:%4d\n", i, i, temp->value, i, temp->next->value);
	temp = temp->next;
	while (temp->next != NULL) {
		++i;
		printf("Node[%d]->prior:%4d, Node[%d]->value:%2d, Node[%d]->next:%4d\n", i, temp->prior->value, i, temp->value, i, temp->next->value);
		temp = temp->next;
	}
	++i;
	// 对尾节点的特殊处理
	printf("Node[%d]->prior:%4d, Node[%d]->value:%2d, Node[%d]->next:NULL\n", i, temp->prior->value, i, temp->value, i);
}

void insert(Node* L, int index, int data) {
	int now_index = now;
	Node* temp = L;
	Node* new = (Node*)malloc(sizeof(Node));
	new->value = data;
	new->next = NULL;
	new->prior = NULL;
	// 主循环，寻找正确下标位置的节点
	while (now_index != index && temp != NULL) { // 当前节点不是要插入的位置
		if (now_index < index) { // 需要操作的节点比当前节点大，在靠近head的方向
			temp = temp->next;
			++now_index;
		}
		if (index < now_index) { // 需要操作的节点比当前节点大，在远离head的地方
			temp = temp->prior;
			--now_index;
		}
	}
	// 插入操作
	if (now_index == index && temp != NULL) { // 确认正在操作的下标是正确的
		if (temp->next != NULL) { // 插入节点的下一节点不为空
			new->next = temp->next; // 将新节点连接到插入节点的下一节点
			temp->next = new; // 将新节点连接到上一节点
			new->prior = temp; // 在新节点写入前置节点
		}
		else { // 插入节点的下一节点为空
			temp->next = new; // 直接将节点连接到尾部
			new->prior = temp; // 在新节点写入前置节点
		}
	}
	if (now_index < now)++now; // 如果是在当前下标之前插入的节点，就需要将下标+1。防止下一次插入出问题。
}