## Step 1: A Basic Starting Point

### Exercise 1 - Building a Basic Project

#### Getting Started

编辑 CMakeLists.txt 文件，完成步骤1-3，使用下面命令 ：
- add_executable()
- cmake_minimum_required()
- project()

#### Build and Run

```bash
rm Step1_build -rf
mkdir Step1_build
cd Step1_build
cmake ..
cmake --build .
./Tutorial 10
```

#### 完成步骤 4-6

#### 完成步骤 7-12

使用 configure_file()。
编译执行。
```bash
rm Step1_build -rf
mkdir Step1_build
cd Step1_build
cmake ..
cmake --build .
```
执行带了输入参数 10 ，输出其平方根计算结果。
```bash
cd Step1_build
./Tutorial 10
```
执行不带参数，打印版本号，提示输入参数。
```bash
cd Step1_build
./Tutorial
```
