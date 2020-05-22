#include<stdio.h>

// 快速排序
// 取任意一位数（本程序中为最后一位）将比它小的数放在左边，比它大的数放在右边
void sort_quick(int a[], int n); // 快速排序入口函数
void sort_quick_c(int a[], int p, int r); // 递归函数
int partition(int a[], int p, int r); // 分区函数
void show(int a[], int n); // 打印整个数组
void swap(int* a, int* b); // 交换两个指针的值

main() {
	int list[7] = { 8, 10, 2, 3, 6, 1, 5 };
	show(list, 7); 
	sort_quick(list, 7);
	show(list, 7);
}

void sort_quick(int a[], int size) {// 入口
	sort_quick_c(a, 0, size - 1);
}

void sort_quick_c(int a[], int p, int r) {// p为首位元素下标，r为尾部元素下标
	int q;
	if (p >= r) return; // 数组为空
	q = partition(a, p, r); // 确认分区点（核心函数）
	sort_quick_c(a, p, q - 1); // 遍历分区点左边的数
	sort_quick_c(a, q + 1, r); // 遍历分区点右边的数
}

int partition(int list[], int p, int r) {
	int* a = list;
	int pivot = a[r]; // 取最后一位数为分区点
	int i = p; // 比分区点小的数下标（左边的）也可以说成已排序区域
	for (int j = p; j < r; j++) { // 遍历所有数
		if (a[j] < pivot) { // 如果当前数比分区点小
			// 下面的交换位置，把这个小于分区点的数移动到已排序区域中去
			// 之所以要交换，也是让空间复杂度保持0，不开辟新的空间
			// 原本在「虚假的已排序区域」中的那个数，就会被交换到未排序区域中去
			swap(a + j, a + i);
			++i;
		}
	}
	swap(a + r, a + i); // 最后一位数放在末尾,分区点之前的位置。把分区点移动到中间
	return i;
}

void show(int a[], int n) { // 打印整个数组
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}