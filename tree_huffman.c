// Huffman 树
#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

typedef struct node {
	char key; // 字符
	int weight; // 权重
	struct node* father; // 父节点
	struct node* left; // 左节点
	struct node* right; // 右节点
}node;

// 创建 Huffman 树，返回头节点。传入参数依次为：节点指针数组、字符数组、权重数组、数组长度
node* create(node* node_list[], char key_list[], int weight_list[], int list_len);
// 在节点指针中，查找最小的两个节点，并将他们两个连接为一个新节点，然后添加进 node_list 并把被合并的两个节点从中删除
void select(node* node_list[], int *list_len);
// 打印树结构
void showTree(node* head);
// 打印编码结果
void showCode(node* head);

void main() {
	node* node_list[SIZE]; // 节点指针,多开的空间是为了两个节点结合后形成的新节点所准备
	int wight_list[SIZE] = { 2, 3, 4, 4, 5, 7 }; // 权重，同理为新节点准备
	char key_list[SIZE] = {'F', 'O', 'R', 'G', 'E', 'T'}; // 需要编码的字符
	for (int i = 0; i < SIZE; i++) {
		node* temp = (node*)malloc(sizeof(node));
		node_list[i] = temp;
	}
	// 创建 Huffman 树，并获取它的头节点
	node* head = create(node_list, key_list, wight_list, SIZE); 
}

node* create(node* node_list[], char key_list[], int weight_list[], int list_len) {
	int* list_len_p = &list_len;
	int* min1 = (int*)malloc(sizeof(int));
	int* min2 = (int*)malloc(sizeof(int));
	// 初始化所有节点的信息
	for (int i = 0; i < list_len; i++) {
		node* temp = node_list[i];
		temp->key = key_list[i]; // 字符
		temp->weight = weight_list[i]; // 权重
		temp->father = NULL; // 父节点
		temp->left = NULL; // 左子树
		temp->right = NULL; // 右子树
	}
	select(node_list, list_len_p, min1, min2);
	printf("End");
}


void select(node* node_list[], int* list_len) {
	if (*list_len < 1) return; // 数组没内容了
	int min1_index = 0, min2_index = 1; // 结合起来后权重最小的两个节点的下标
	int index_plus = 0; // 结合后产生的新节点,的索引下标
	int sum=1000000000; // 两数结合起来后的和,初始化一个比较大的数
	for (int i = 0; i < *list_len; i++) { // 依次比较
		for (int j = i + 1; j < *list_len; j++) {
			// TODO 这里还需要添加父节点的判断
			if (node_list[i]->weight + node_list[j]->weight < sum) { // 当前两个节点的权重比上一个的小
				min1_index = i; // 记录第1个节点的下标
				min2_index = j; // 记录第2个节点的下标
				sum = node_list[min1_index]->weight + node_list[min2_index]->weight; // 更新目前的最小权重
			}
		}
	}
	node* new_node = (node*)malloc(sizeof(node)); // 创建新节点
	new_node->father = NULL; // 新节点无父节点
	new_node->left = node_list[min1_index]; // 初始化左节点
	new_node->right = node_list[min2_index]; // 初始化右节点
	new_node->weight = new_node->left->weight + new_node->right->weight; // 权重为两节点之和
	new_node->left->father = new_node; // 更新被合并节点的父节点
	new_node->right->father = new_node;
	node* new_node_list = (node*)malloc((*list_len - 1)*sizeof(node)); // 相当于 node* new_node_list[new_len]

	// 创建新的节点指针数组（删除被合并节点，添加新节点）
	int temp_j = 0;
	for (int i = 0; i < *list_len; i++) {
		// 如果碰到了被合并节点，就跳过
		if (node_list[i] == node_list[min1_index] || node_list[i] == node_list[min2_index]) {
			++temp_j; // 新数组的下标
			continue;
		}
		new_node_list[i-temp_j] = *node_list[i]; // 错位赋值，因为新数组要小些
	}
	new_node_list[*list_len] = *new_node; // 新节点放在数组的最后面
	node_list = new_node_list; // 把新数组传递到外部
	*list_len = *list_len -1; // 把新下标传递到外部
}