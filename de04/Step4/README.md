# 添加生成器表达式

## 练习1 使用生成器表达式添加编译器警告标志

generator expressions 常见用法是有条件地添加编译器标志。
将该信息与 INTERFACE 接口库目标联系起来，允许信息在链接到目标时传递。

### 目标

在构建时，添加编译器警告标志，但不针对已安装的版本添加。

### 有用资源

- cmake-generator-expressions(7)
- cmake_minimum_required()
- set()
- target_compile_options()

### 编辑文件

- CMakeLists.txt

### 开始

完成步骤 1-4。
设置 cmake_minimum_required() 版本为 3.15。

使用 COMPILE_LANG_AND_ID 生成器表达式来控制在给定语言和一组编译器ID的情况下应用哪些标志。

### 编译构建

```bash
rm -rf Step4_build
mkdir Step4_build
cd Step4_build
cmake ..
cmake --build .
```

```bash
cd Step4_build
./Tutorial
```

```bash
cd Step4_build
./Tutorial 111
```