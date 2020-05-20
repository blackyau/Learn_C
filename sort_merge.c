// 归并排序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort_merge(int list[], int n); // 初始化入口
void sort_merge_c(int a[], int p, int r); // 递归调用函数
void merge(int arr[], int p, int q, int r); // 合并函数

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
	sort_merge_c(a, p, q); // 左边部分的数组
	sort_merge_c(a, q + 1, r); // 右边部分的数组
	merge(a, p, q, r); // 合并数组
}

// 合并数组
// 数组、首元素、中间元素、尾元素
void merge(int arr[], int p, int q, int r) {
	int* temp;
	int i, j, k;
	temp = (int*)malloc((r - p + 1) * sizeof(int)); // 创建一个长度和原数组一样的数组
	if (!temp)
		abort(); // exit(1) 程序异常终止

	// i为前一半元素的首地址，j为后一半元素首地址，k为临时数组的当前下标
	// 将i或j里面小的那一个放进临时数组
	for (i = p, j = q + 1, k = 0; i <= q && j <= r;) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	// 下面就是用来连接，数组中没有参加上面计算的元素，把arr中的其他元素也搬进temp，用于下一次递归

	// 哪一个数组有剩余元素
	int start = i, end = q; // 默认是左边
	if (j <= r) { // 如果右边的有剩余元素
		start = j; // 交换一下，把下标都换成右边的
		end = r;
	}

	// 把剩余元素拷贝进临时数组
	while (start <= end) {
		temp[k++] = arr[start++];
	}

	// 把整理好的数字返回给原始数组
	memcpy(arr + p, temp, (r - p + 1) * sizeof(int));
	free(temp);
}