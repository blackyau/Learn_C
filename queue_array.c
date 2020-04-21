// 顺序队列
#include<stdio.h>

static int items[6];
static int n=6; // 队列长度
static int head = 0;
static int tail = 0;

int enqueue(int data); // 入队
int dequeue(); // 出队
void show(); // 打印整个数组,用来观察内部数据变化

void main() {
	for (int i = 0; i < n; i++) {
		enqueue(i);
	}
	show();
	printf("dequeue num:");
	for (int i = 0; i < n-3; i++) {
		printf("%d ", dequeue());
	}
	printf("\n");
		for (int i = 6; i < 9; i++) {
		enqueue(i);
	}
		for (int i = 0; i < n; i++)
			printf("%d ", dequeue());
}

int enqueue(int data) {
	if (tail >= n) { // 尾部没有空位了
		if (head == 0)return 0; // 完全满了
		for (int i = head; i < tail; i++) { // 数据搬移
			items[i - head] = items[i]; // 都向前搬移数据
		}
		tail -= head; // 数据搬移后更新tail下标
		head = 0; // 数据都搬到头部了head也要刷新
	}
	items[tail] = data; // 把新数据写在尾部下标
	++tail; // 尾部下标向前,等待下一次加入
	return 1;
}

int dequeue() {
	if (tail == head)return 0; // 空了
	int result;
	result = items[head]; // 把出列的数据准备好
	++head; // 头下标向前
	return result;
}

void show() {
	for (int i = 0; i < n; i++) {
		printf("%d ", items[i]);
	}
	printf("\n");
}