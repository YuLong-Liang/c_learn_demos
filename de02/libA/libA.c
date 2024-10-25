//
// Created by xjgc on 2024/10/24.
//

#include <stdio.h>
#include "libB.h" // 引入库 B 的头文件
#include "metric.h"
#include <unistd.h>

void functionA() {
    init();
    printf("Function A called\n");
    startTimer(0, "functionA");
    sleep(1);
    functionB(); // 调用库 B 的函数
    sleep(2);
    stopTimer(0);
    printFunctionMetrics(0);
}

void functionC() {
    startTimer(2, "functionC");
    printf("Function C called\n");
    sleep(1);
    stopTimer(2);
    printFunctionMetrics(2);
}
