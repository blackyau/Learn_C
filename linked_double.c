// 双向链表
// TODO 任意位置插入 删除
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* prior;
	int value;
	struct Node* next;
}Node;

static Node head_data;
static Node* head = &head_data; // 头节点全局变量
static int now = 0; // 从head开始数起，当前指针指向第几个节点
Node* InitNode(Node *L, int data); // 将以data为值的节点插入到L的下一节点
void insert(Node* L, int index, int data); // 在L链表中index下标节点的next插入一个value为data的节点
void rm(Node* L, int index); // 删除L链表中下标为index的节点
void show(Node* head); // 打印整个链表

void main() {
	head->value = 0;
	head->next = NULL;
	head->prior = NULL;
	Node* temp = head;
	for (int i = 1; i < 4; i++) {
		temp = InitNode(temp, i);
	}
	show(head);
	printf("\n\ninser -1 after node[1]\n");
	insert(temp, 1, -1);
	show(head);
	printf("\n\ninser -1 after node[4]\n");
	insert(temp, 4, -1);
	show(head);
	printf("\n\ninser -1 after node[3]\n");
	insert(temp, 3, -1);
	show(head);
	now = 0; // 后面删除都是传head，所以当前下标也都改为0。
	// 不能继续用temp进去删除，如果把temp本身删了那以后的代码都不能继续了
	printf("\n\nrm node[2]\n");
	rm(head, 2);
	show(head);
	printf("\n\nrm node[3]\n");
	rm(head, 3);
	show(head);
	printf("\n\nrm node[4]\n");
	rm(head, 4);
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
	printf("+----------------------+-------------------+---------------------+\n");
	printf("|         prior        |        now        |         next        |\n");
	printf("|----------------------------------------------------------------|\n");
	printf("| Node[%2d]->value:NULL | Node[%d]->value:%2d | Node[%d]->value:%4d |\n", -1, i, temp->value, i+1, temp->next->value);
	temp = temp->next;
	while (temp->next != NULL) {
		++i;
		printf("| Node[%2d]->value:%4d | Node[%d]->value:%2d | Node[%d]->value:%4d |\n", i-1, temp->prior->value, i, temp->value, i+1, temp->next->value);
		temp = temp->next;
	}
	++i;
	// 对尾节点的特殊处理
	printf("| Node[%2d]->value:%4d | Node[%d]->value:%2d | Node[%d]->value:NULL |\n", i-1, temp->prior->value, i, temp->value, i+1);
	printf("+----------------------+-------------------+---------------------+");
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

void rm(Node* L, int index) {
	int now_index = now;
	Node* rm_node = NULL;
	Node* temp = L;
	// 主循环，寻找正确下标位置的节点
	while (now_index != index && temp != NULL) { // 当前下标不是要删除的位置
		if (now_index < index) { // 需要删除的下标比当前下标大，在靠近head的方向
			temp = temp->next;
			++now_index;
		}
		if (index < now_index) { // 需要删除的下标比当前下标大，在远离head的地方
			temp = temp->prior;
			--now_index;
		}
	}
	// 删除节点
	if (now_index == index && temp != NULL) {
		rm_node = temp; // 将即将删除的节点储存起来,防止节点脱离链表后找不到地址
		if (temp->next != NULL && temp->prior != NULL) { // 被删节点的下一节点和上一节点不为空（中段节点）
			temp->prior->next = temp->next; // 把被删节点的next节点，连接到被删节点的上一节点的next
			temp->next->prior = temp->prior; // 把被删节点的上一节点，写入到被删节点的next的上一节点
			// 左右两边都跳过了被删节点
		}
		else if (temp->prior == NULL && temp->next != NULL) { // 被删节点的上一节点为空,下一节点不为空（头节点）
			temp->next->prior = NULL;
			head = temp->next;
		}
		else if (temp->prior != NULL && temp->next == NULL) { // 被删节点的上一节点不为空，下一节点为空（尾部节点）
			temp->prior->next = NULL;
		}
	}
	free(rm_node);
}