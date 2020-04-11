//单链表 查找数值 删除指定值的节点
#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node* next;
};

//先写函数原型,后面再写函数定义（主体）
struct node* find_index(struct node* head, int index); // 传入头节点指针和要查找的值,返回匹配的节点指针
void rm(struct node* head, int value); // 传入头节点指针和要删除的值
void show(struct node* head); // 打印整个链表

int main() {
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* a = head;
	for (int i = 1; i < 5; i++) { // 初始化链表,装填数据
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->value = i;
		temp->next = NULL;
		a->next = temp;
		a = a->next; //将新插入的节点设为链尾,方便下一次插入
	}
	show(head); // 打印整个链表
	struct node* find_result = find_index(head, 3); // 查找数值为3的节点,返回节点指针
	if (find_result != NULL) { // 如果返回指针不为空
		printf("now:%d\n", find_result->value);
		if (find_result->next != NULL) {// 如果返回指针的下一个指针不为空
			printf("next:%d\n", find_result->next->value);
		}else { // 下一个指针为空
			printf("next:-1\n");
		}
	}else { // 返回指针为空
		printf("now:-1\n");
	}
	rm(head, 2); // 删除链表中，值为2的节点
	show(head); // 打印整个链表
	return 0;
}

struct node* find_index(struct node* head, int index) {
	struct node* temp = head;
	// 当前链表没有到尾部，同时与要查找的值不匹配，就跳到下一节点
	while (temp != NULL && temp->value != index) {
		temp = temp->next;
	}
	return temp; // 保持返回值一致,无论是否找到都要返回,需要检查返回值是不是头指针
}

void rm(struct node* head, int value) {
	struct node* temp = head;
	struct node* swap;
	// 当前节点为空（到尾部都没找到），当前节点就是要找节点的前一个(必须要提前停下来,因为无法通过当前节点访问到上一级节点)，就停止遍历
	while (temp != NULL && temp->value != value - 1) {
		temp = temp->next;
	}
	// 当前节点不为空，找到了要删除节点的前一个
	if (temp != NULL && temp->value == value-1) {
		swap = temp->next; // 把要删除的节点保存起来
		temp->next = temp->next->next; // 把要删除节点的下一节点，直接连接到要删除节点的上一个。
		// 相当于跳过了要删除的节点，画图很好理解
		free(swap); // 释放要删除节点
	}
}

void show(struct node* head){
	struct node* temp = head;
	int i = 0;
	while (temp != NULL) {
		printf("node[%d]:%d\n", i, temp->value);
		temp = temp->next;
		i++;
	}
}