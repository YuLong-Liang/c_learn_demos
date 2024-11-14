
# 第三步 新增库的使用要求

## 练习1 新增库的使用要求。
> 更通用的使用模式，意味着每个 CMakeLists.txt 中包含头文件的目录，只包含当前所在目录。
> `target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})`
> INTERFACE 关键字，表示可见范围为MathFunctions目标不可见，而其他被链接的目标可见。

目标参数的使用要求允许更好地控制库或可执行文件的链接和包含行
同时也可以更好地控制CMake中目标的传递属性。利用使用要求主要命令是：

- target_compile_definitions()
- target_compile_options()
- target_include_directories()
- target_link_directories()
- target_link_options()
- target_precompile_headers()
- target_sources()

### 目标

新增库的使用要求

### 有用资源

CMAKE_CURRENT_SOURCE_DIR

### 编辑文件

- MathFunctions/CMakeLists.txt
- CMakeLists.txt

### 开始

我们将让我们的库定义自己的使用要求，以便在必要时将其传递给其他目标。

在这种情况下，MathFunctions将自己指定任何需要的包含目录。
目标 Tutorial 简单需要链接到 MathFunctions 库，无需担心任何的包含目录。

完成步骤1-3。

新增一个命令 target_include_directories() 到 MathFunctions/CMakeLists.txt 文件中。
CMAKE_CURRENT_SOURCE_DIR 是一个CMake变量，它包含当前处理的CMakeLists.txt文件的目录。

更新 target_include_directories() 命令，在顶层 CMakeLists.txt 文件。

### 编译构建

```bash
rm -rf Step3_build
mkdir Step3_build
cd Step3_build
cmake ..
cmake --build .
```

```bash
cd Step3_build
./Tutorial
```

```bash
cd Step3_build
./Tutorial 121
```

## 练习2 设置C++标准，使用接口库
> 可以不用在每个 CMakeLists.txt 文件中设置 C++ 标准，
> `#set(CMAKE_CXX_STANDARD 11) #set(CMAKE_CXX_STANDARD_REQUIRED True)`
>  只需要在顶层 CMakeLists.txt 文件中设置一次，然后使用 INTERFACE 库来传递这个设置。
> `target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)`
设置属性去支持多个目标。

使用 INTERFACE 库重构现有的代码。
证明 generator expressions 的通用使用。

### 目标

新增一个 INETRFACE 库，去设置需要的 C++ 标准。

### 有用资源

- add_library()
- target_compile_features()
- target_link_libraries()

### 编辑文件

- CMakeLists.txt
- MathFunctions/CMakeLists.

### 开始

完成步骤 4 -7。

从编辑顶层 CMakeLists.txt 文件开始，新增一个 INTERFACE 库，
使用 tutorial_compiler_flags 目标，去指定 cxx_std_11 作为目标编译器特点。

修改 CMakeLists.txt 文件和 MathFunctions/CMakeLists.txt 文件，
所有的目标都有一个 target_link_libraries() 命令链接到 tutorial_compiler_flags。

### 编译构建

```bash
rm -rf Step3_build
mkdir Step3_build
cd Step3_build
cmake ..
cmake --build .
```

```bash
cd Step3_build
./Tutorial
```

```bash
cd Step3_build
./Tutorial 121
```