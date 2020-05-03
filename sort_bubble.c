// 冒泡排序
#include<stdio.h>
#define LEN 7

void sortBubble(int array[], int len);

void main() {
	int array[LEN] = {4, 5, 6, 3, 2, 1};
	for (int i = 0; i < LEN; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	sortBubble(array, LEN);
	for (int i = 0; i < LEN; i++) {
		printf("%d ", array[i]);
	}
}

void sortBubble(int array[], int len) {
	int* p = array;
	for (int i = 0; i < len; i++) { // 前置位
		int flag = 0; // 此次是否交换数据
		for (int j = 0; j < len - i - 1; j++) { // 后置位
			if (p[j] > p[j + 1]) { // 前面比后边大
				int temp = p[j]; // 储存前者
				p[j] = p[j + 1]; // 后覆盖前
				p[j + 1] = temp; // 后给前
				flag = 1; // 有数据交换
			}
		}
		if (flag == 0)break; // 没有数据交换
	}
}