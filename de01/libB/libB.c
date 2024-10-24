//
// Created by xjgc on 2024/10/24.
//
#include <stdio.h>
#include "libA.h" // 引入库 A 的头文件
#include "metric.h"

void functionB() {
    printf("Function B called\n");
    startTimer(1, "functionB");
    functionC(); // 调用库 A 的函数
    stopTimer(1);
    printFunctionMetrics(1);
}
