CMake官方教程，第二节，增加一个库。

# Step 2: Adding a Library

## Exercise 1 - Creating a Library
> 练习1的意思是创建一个库，然后在 tutorial.cxx 中使用这个库。

使用 add_library() 命令，创建一个库。
我们将为库创建一个新的子目录，以便我们可以将库的源代码和头文件分开。
在顶层 CMakeLists.txt 文件中，使用 add_subdirectory() 命令添加这个新的子目录。

一旦库完成创建，我们将使用 target_include_directories() 命令来指定库的头文件目录、使用 target_link_libraries()　来连接库文件。

### Goal

增加和使用一个库

### 有用资源

add_library(), add_subdirectory(), target_include_directories(), target_link_libraries()
PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR

### 开始

使用库完成平方根的计算，而不是使用编译器提供的内置函数。

把库放在子目录 MathFunctions 中，包含两个头文件：MathFunctions.h 和 mysqrt.h。
他们分别的源文件对应为 MathFunctions.cxx 和 mysqrt.cxx。

完成步骤 1-6。
分别编写子目录和顶层目录的 CMakeLists.txt 文件，在 tutorial.cxx 文件中使用新创建的 MathFunctions 库。

### 编译执行测试

```bash
rm Step2_build -rf
mkdir Step2_build
cd Step2_build
cmake ..
cmake --build .
```

```bash
cd Step2_build
./Tutorial 10
```

## Exercise 2 - Adding an Option
> 练习2的意思是 mysqrt.cxx 也作为一个 lib 库，并且基于一个变量 USE_MYMATH 来选择是否启用构建这个库。

新增一个 Option，在 MathFunctions 库中，允许用户选择使用自己的平方根函数还是使用编译器提供的内置函数。

CMake 实现该需求，需要使用 option() 命令。给用户一个变量，用户他们可以选择，当配置他们的Cmake 构建时。

### Goal

不使用 MathFunctions，新增一个选项去构建。

### 需要函数

if(), option(), target_compile_definitions()

### 需要文件

MathFunctions/CMakeLists.txt
MathFunctions/MathFunctions.cxx

### 开始

从 Exercise 1 开始，完成步骤 7-14。

使用 option() 命令创建 USE_MYMATH 变量在 MathFunctions/CMakeLists.txt 文件中。
使用选项去传递一个编译定义到 MathFunctions 库。

然后，更新 MathFunctions.cxx 去基于 USE_MYMATH 去重定向编译。
最终，当 USE_MYMATH 为 ON 时，通过在 MathFunctions/CMakeLists.txt 文件的 USE_MYMATH 块中创建自己的库
，阻止 mysqrt.cxx 文件的编译。

### 编译执行测试

```bash
rm Step2_build -rf
mkdir Step2_build
cd Step2_build
cmake ..
cmake --build .
```

```bash
cd Step2_build
./Tutorial 10
```