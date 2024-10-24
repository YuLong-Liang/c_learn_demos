#include <stdio.h>
#include "../libsoA/metric.h"

void function1() {
	// 模拟耗时操作
	for (volatile long i = 0; i < 100000000; i++);
}

void function2() {
	// 模拟耗时操作
	for (volatile long i = 0; i < 200000000; i++);
}

void function3() {
	// 模拟耗时操作
	for (volatile long i = 0; i < 150000000; i++);
}

int main() {
	init(); // 初始化 Metric 结构体

	for (int i = 0; i < 5; i++) {
		startTimer(0);
		function1();
		stopTimer(0);
		printFunctionMetrics(0);

		startTimer(1);
		function2();
		stopTimer(1);
		printFunctionMetrics(1);

		startTimer(2);
		function3();
		stopTimer(2);
		printFunctionMetrics(2);
	}

	// logMetrics(); // 打印所有函数的统计信息

	// 打印特定函数的性能信息
	// printFunctionMetrics(0); // 打印 function1 的性能数据
	// printFunctionMetrics(1); // 打印 function2 的性能数据
	// printFunctionMetrics(2); // 打印 function3 的性能数据

	return 0;
}
