// 希尔排序
#include<stdio.h>

void sort_shell(int list[], int n);

void main() {
	int list[16] = { 10, 14, 73, 25, 23, 13, 27, 94, 33, 39, 25, 59, 94, 65, 82, 45 };
	for (int i = 0; i < 16; i++) printf("%d ", list[i]);
	sort_shell(list, 16);
	printf("\n");
	for (int i = 0; i < 16; i++) printf("%d ", list[i]);
}

// 插入排序的优化版，逐一对比时，使用指定步进(插入排序进行对比时，每次都对比旁边一位)
// 希尔排序，传入数组和长度
void sort_shell(int list[], int n) {
	int *a = list;
	int step_list[3] = {5, 3, 1}; // 每次进行排序的步长
	for (int step_index = 0; step_index < 3; step_index++) {
		int step_size = step_list[step_index]; // 使用指定步长进行排序
		for (int i = step_size; i < n; i=i+step_size) {
			int value = a[i]; // 进行对比的值
			int j = i - step_size; // 已排序区域的最后一个数
			for (; j >= 0; j -= step_size) { // 从后向前进行对比
				if (value < a[j]) { // 当前下标值大于匹配值（在已排序区域中，寻找合适的位置）
					a[j + step_size] = a[j]; // 向前搬移数据
				}
				else { // 匹配数找到了合适的位置
					break;
				}
			}
			a[j += step_size] = value; // 在已排序区域中的合适位置，插入数
		}
	}
}