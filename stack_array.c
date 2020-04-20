// 顺序栈 数组
#include<stdio.h>

static int items[6]; // 用来装数据
static int len = 6; // 数组的长度
static int count = 0; // 数组中有多少个数据

int push(int data); // 向栈内插入data，返回0则失败，非0则成功
int pop(); // 返回栈顶的数

void main() {
	// len+1是为了模拟溢出时的处理是否正常
	for (int i = 0; i < len+1; i++) {
		printf("%d ", push(i));
	}
	printf("\n");
	for (int i = 0; i < len+1; i++) {
		printf("%d ", pop());
	}
}

int push(int data) {
	if (count + 1 > len)return 0; // 空间不足，未能插入数据
	items[count] = data; // 存入数组
	++count; // 把元素内总数据量+1
	return 1;
}

int pop() {
	if (count - 1 < 0)return 0; // 栈里面已经没数据了，返回0
	--count; // 元素总数减一
	return items[count]; // 返回最后插入的数
}