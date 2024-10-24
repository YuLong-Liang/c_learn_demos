#include <stdio.h>
#include <limits.h>
#include "metric.h"

static Metric metric; // 静态实例化 Metric 结构体

static void initFunctionMetric(FunctionMetric* functionMetric) {
    functionMetric->startTime = 0;
    functionMetric->endTime = 0;
    functionMetric->maxTime = 0.0;
    functionMetric->minTime = 0.0;
    functionMetric->totalTime = 0.0;
    functionMetric->callCount = 0;
    functionMetric->functionName = calloc(MAX_FUNCTION_NAME_LENGTH, sizeof(char));
}

static void initMetric(Metric* metric) {
    for (int i = 0; i < MAX_FUNCTIONS; i++) {
        initFunctionMetric(&metric->metrics[i]);
    }
}

void init() {
    initMetric(&metric); // 初始化静态 Metric 结构体
}

void startTimer(int functionIndex, char* functionName) {
    metric.metrics[functionIndex].startTime = clock();
//    metric.metrics[functionIndex].functionName = functionName;
    // 带长度限制的字符串拷贝
    strncpy(metric.metrics[functionIndex].functionName, functionName, MAX_FUNCTION_NAME_LENGTH);
}

void stopTimer(int functionIndex) {
    metric.metrics[functionIndex].endTime = clock();

    double elapsedTime = (double)(metric.metrics[functionIndex].endTime - metric.metrics[functionIndex].startTime) / CLOCKS_PER_SEC;

    if (metric.metrics[functionIndex].callCount == 0) {
        metric.metrics[functionIndex].maxTime = elapsedTime;
        metric.metrics[functionIndex].minTime = elapsedTime;
    } else {
        if (elapsedTime > metric.metrics[functionIndex].maxTime) {
            metric.metrics[functionIndex].maxTime = elapsedTime;
        }
        if (elapsedTime < metric.metrics[functionIndex].minTime) {
            metric.metrics[functionIndex].minTime = elapsedTime;
        }
    }

    metric.metrics[functionIndex].totalTime += elapsedTime;
    metric.metrics[functionIndex].callCount++;
}

void logMetrics() {
    for (int i = 0; i < MAX_FUNCTIONS; i++) {
        FunctionMetric* fm = &metric.metrics[i];
        if (fm->callCount > 0) {
            double averageTime = fm->totalTime / fm->callCount;
            printf("Function %d:\t", i);
            printf("FunctionName: %s\t", fm->functionName);
            printf("  Call Count: %d\n", fm->callCount);
            printf("  Max Time: %f seconds\t", fm->maxTime);
            printf("  Min Time: %f seconds\t", fm->minTime);
            printf("  Average Time: %f seconds\t", averageTime);
        } else {
            printf("Function %d: No calls made.\n", i);
        }
    }
}

// 新增的函数实现
void printFunctionMetrics(int index) {
    if (index < 0 || index >= MAX_FUNCTIONS) {
        printf("Error: Invalid function index %d\n", index);
        return;
    }

    FunctionMetric* fm = &metric.metrics[index];
    if (fm->callCount > 0) {
        double averageTime = fm->totalTime / fm->callCount;
        printf("Function %d:\t", index);
        printf("FunctionName: %s\t", fm->functionName);
        printf("  Call Count: %d\n", fm->callCount);
        printf("  Max Time: %f seconds\t", fm->maxTime);
        printf("  Min Time: %f seconds\t", fm->minTime);
        printf("  Average Time: %f seconds\n", averageTime);
    } else {
        printf("Function %d: No calls made.\n", index);
    }
}
