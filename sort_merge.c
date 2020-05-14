// 归并排序
#include<stdio.h>

void sort_merge(int list[], int n);
void sort_merge_c(int a[], int p, int r);

void main() {
	int list[6] = { 1, 5, 6, 2, 3, 4 };
	for (int i = 0; i < 6; i++) printf("%d ", list[i]);
	sort_merge(list, 6);
	printf("\n");
	for (int i = 0; i < 6; i++) printf("%d ", list[i]);
}

// 把数组分为两半，然后再继续分两半，一直分到只有2个元素，再对比其大小，小的在前大的在后
// 归并排序，传入数组和长度
void sort_merge(int list[], int n) {
	sort_merge_c(list, 0, n-1);
}

// 归并排序递归调用函数，传入数组、首元素下标、尾元素下标
void sort_merge_c(int a[], int p, int r) {
	if (p >= r)return; // 递归出口
	int q = (p + r) / 2; // 取 p 和 r 的中间值
	sort_merge_c(a, p, q);
	sort_merge_c(a, q + 1, r);
}