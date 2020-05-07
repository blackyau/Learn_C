// 插入排序
#include<stdio.h>

void sort_insert(int list[], int n); // n为长度

void main() {
	int n = 6;
	int list[6] = { 4, 5, 6, 1, 3, 2 };
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	sort_insert(list, n);
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
}

// 将数组分为两部分：已排序区域、未排序区域。
// 将已排序区域中的元素与已排序区域的元素作比较，放在比它大的元素前面(小在前,大在后,升序)
// 插入排序,传入排序的数组和数组的长度
void sort_insert(int list[], int n) {
	int* a = list;
	if (n < 1)return; // 传入数组长度小于1，无需排序

	for (int i = 1; i < n; i++) { // 遍历未排序区域
		int value = a[i]; // 默认已排序区域，为数组的第一个元素
		int j = i - 1;
		for (; j >= 0; j--) { // 从后面，向前搬移数据
			if (a[j] > value) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j+1] = value;
	}
}