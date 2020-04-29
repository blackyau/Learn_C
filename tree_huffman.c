// Huffman 树
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char key; // 字符
	int weight; // 权重
	struct node* father; // 父节点
	struct node* left; // 左节点
	struct node* right; // 右节点
}node;

// 创建 Huffman 树，返回头节点。传入参数依次为：节点指针数组、字符数组、权重数组、数组长度
node* create(node* node_list[], int key_list[], int weight_list[], int list_len);
// 在节点指针中，查找最小的两个节点。并通过 min1 和 min2 返回(把节点地址写入)节点指针。
void select(node* node_list[], int list_len, int* min1, int* main2);
// 打印树结构
void showTree(node* head);
// 打印编码结果
void showCode(node* head);

void main() {

}