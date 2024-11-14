# 安装并测试

## 练习1 安装规则

使用 `install()` 命令安装项目的文件。
在 CMake 中支持构建的本地安装通常需要指定安装目录、安装目标和文件。

### 目标

安装　Tutorial 可执行程序和 MathFunctions 库。

### 有用资源

install()

### 编辑文件

- MathFunctions/CMakeLists.txt
- CMakeLists.txt

### 开始

完成步骤 1-4。

更新 MathFunctions/CMakeLists.txt 文件，以便安装 MathFunctions 和 tutorial_compiler_flags 库到指定目录 lib。
在同一个文件中，指定安装 MathFunctions.h 到目录 include 所需的安装规则。

更新顶层 CMakeLists.txt 文件，以便安装可执行文件 Tutorial 到指定目录 bin 。
应将任何头文件安装到目录中 include。
TutorialConfig.h 文件在 PROJECT_BINARY_DIR。

### 编译构建
编译、构建、安装
```bash
rm -rf Step5_build
mkdir Step5_build
cd Step5_build
cmake ..
cmake --build .
cmake --install . --prefix "/home/xjgc/dev/installdir/"
```

如果不加 --prefix 参数，安装到默认目录 /usr/local/ 下。

## 练习2 测试支持

CTest 提供一个简单的方式去测试项目。
CTest 和 GoogleTest 兼容。

### 目标

创建单元测试，使用CTest测试可执行文件。

### 有用资源

- enable_testing()
- add_test()
- function()
- set_tests_properties()
- ctest

### 编辑文件

- CMakeLists.txt

### 开始

完成步骤 5-9。

先启动测试。
使用 add_test 添加测试程序到项目。

### 编译构建

编译、构建、测试

```bash
rm -rf Step5_build
mkdir Step5_build
cd Step5_build
cmake ..
cmake --build .
```

-N 参数显示测试名称，不执行测试。
```bash
cd Step5_build
ctest -N
```

```bash
cd Step5_build
ctest
```
