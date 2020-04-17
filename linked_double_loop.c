// 双向循环链表
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* prior;
	int value;
	struct node* next;
}node;

static node head_data;
static node* head = &head_data; // 定义head全局指针

// 在L链表中的index位置插入值为data的节点,now_index为传入节点的下标位置，如果不带则默认传入的是头节点
void insert(node* L, int index, int data, int now_index);
void show();

void main() {
	// 给头节点赋初值
	head->next = head;
	head->prior = head;
	head->value = 0;
	for (int i = 1; i < 5; i++) insert(head, i-1, i, 0);
	show(head);
	printf("\n\ninsert -1 after node->value == 0\n");
	insert(head, 0, -1, 0);
	show(head);
	printf("\n\ninsert -1 after node->value == 1\n");
	insert(head, 1, -1, 0);
	show(head);
	printf("\n\ninsert -1 after node->value == 3\n");
	insert(head, 3, -1, 0);
	show(head);
	printf("\n\ninsert -1 after node->value == 6\n");
	insert(head, 6, -1, 0);
	show(head);
}

void insert(node* L, int index, int data, int now_index) {
	node* temp = L;
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = data;
	if (now_index == 0) { // 传入节点为头节点
		while (index) { // 让他循环到要插入的位置
			temp = temp->next; 
			--index;
		}
	}
	else if (now_index < index) { // 要插入的下标在当前下标的后面（远离head）
		while (index != now_index) {
			temp = temp->next;
			++index;
		}
	}
	else if (now_index > index) { // 要插入的下标在当前下标的前面（靠近head）
		while (index != now_index) {
			temp = temp->prior;
			--index;
		}
	}
	if (now_index == index) { // 找到了对应的下标
		//if (temp->next == head) { // 在链表尾部插入
			new_node->next = temp->next; // 让新节点连接到插入节点的next（先连前面）
			temp->next = new_node; // 把新节点连接到插入节点的后面（后连后面）
			new_node->prior = temp; // 设置新节点的上一节点为插入节点
			new_node->next->prior = new_node; // 修改头节点的上一节点为新插入节点（逆向循环）
		//}
		//else {
		//	new_node->next = temp->next; // 让新节点连接到插入节点的next（先连前面）
		//	temp->next = new_node; // 把新节点连接到插入节点的后面（后连后面）
		//	new_node->prior = temp;
		//	new_node->next->prior = new_node;
		//}
	}
}

void show() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	int i = 0;
	// 头节点特殊处理，不知道头节点的上一节点的下标（链表总长度）是多少
	printf("+--------------------+-------------------+-------------------+\n");
	printf("|        prior       |        now        |        next       |\n");
	printf("|------------------------------------------------------------|\n");
	printf("| node[-1]->value:%2d | node[%d]->value:%2d | node[%d]->value:%2d |\n", temp->prior->value, i, temp->value, i+1, temp->next->value);
	temp = temp->next;
	for (i = 1; temp != head; temp = temp->next, i++) {
		printf("| node[%2d]->value:%2d | node[%d]->value:%2d | node[%d]->value:%2d |\n", i-1, temp->prior->value, i, temp->value, i+1, temp->next->value);
	}
	printf("+--------------------+-------------------+-------------------+");
}