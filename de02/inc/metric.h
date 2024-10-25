#ifndef METRIC_H
#define METRIC_H

#include <time.h>

#define MAX_FUNCTIONS 3 // 假设 N=3
#define MAX_FUNCTION_NAME_LENGTH 30 // 新增的宏定义

typedef struct {
    clock_t startTime;
    clock_t endTime;
    double maxTime;
    double minTime;
    double totalTime;
    int callCount;
    char *functionName; // 新增的成员变量
} FunctionMetric;

typedef struct {
    FunctionMetric metrics[MAX_FUNCTIONS];
} Metric;

void startTimer(int functionIndex, char* functionName); // 修改的函数声明
void stopTimer(int functionIndex);
void logMetrics();
void init(); // 声明 init 函数
void printFunctionMetrics(int index); // 新增的函数声明

#endif // METRIC_H
