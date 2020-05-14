#include<stdio.h>

void sort_select(int list[], int n);

void main() {
	int list[6] = { 4, 5, 6, 1, 3, 2 };
	for (int i = 0; i < 6; i++) printf("%d ", list[i]);
	sort_select(list, 6);
	printf("\n");
	for (int i = 0; i < 6; i++) printf("%d ", list[i]);
}

// 在未排序区域中寻找一个最小的，放在排序区域的最后面
// 选择排序，传入数组和长度
void sort_select(int list[], int n) {
	int* a = list;
	for (int i = 0; i < n-1; i++) { // 不用对比最后一位，它肯定是最大的一个(只剩它一个了)
		int j = i;
		int min = 99999; // 用于储存未排序区域中,最小的数
		int min_index = -1; // 最小数的下标
		for (; j < n; j++) { // 遍历未排序区域
			if (a[j] < min) { // 寻找未排序区域中最小的数
				min = a[j];
				min_index = j;
			}
		}
		// 交换位置
		int temp = a[i];
		a[i] = a[min_index]; // 把未排序区域中最小的数,与已排序区域的尾部交换
		a[min_index] = temp;
	}
}