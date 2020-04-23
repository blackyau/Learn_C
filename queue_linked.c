// 链式队列
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

// 初始化
static node tail_data = { 0, NULL };
static node head_data = { 0, &tail_data };
static node* head = &head_data;
static node* tail = &tail_data;

void enqueue(int data); // 入队
int dequeue(int *data); // 出队

void main() {
	for (int i = 1; i < 4; i++) {
		enqueue(i);
	}
	// i大于插入的数据量，模拟队列已空还出列的情况
	for (int i = 1; i < 7; i++) {
		int out;
		int result = dequeue(&out);
		printf("%d ", result?out:0);
	}
}

void enqueue(int data) {
	if (tail == NULL)return; // 尾指针丢失
	node* temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	tail->value = data; // 把数据存在当前节点
	tail->next = temp; // 将新节点连接上尾节点
	tail = temp; // 头节点移动至下一位
}

int dequeue(int *data) {
	if (head == NULL)return 0; // 头节点丢失
	if (head == tail)return 0; // 节点为空
	*data = head->value; // 把出列的值写入data
	node* rm_node = NULL; // 初始化删除节点
	rm_node = head; // 存好准备删除的节点
	head = head->next; // 头节点移动至下一位
	//free(rm_node); // 因为头节点是static所以无法free，懒得再写一遍局部变量了
	return 1;
}