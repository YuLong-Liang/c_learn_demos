### cpp和c文件混合编译示例

####  undefined reference 报错

执行编译命令，提示报错 `undefined reference to`。

```bash
g++ -o de03  main.cpp esp861.c -I./inc
```

分步骤依次编译，把 .c 和 .cpp 文件分开编译成 .o，再链接。
会在 `g++ -o de02_undefined main_undefined.cpp.o esp861.c.o` 该步骤提示 undefined reference to 'initEsp861()' 错误。

```bash
g++ -std=c++11 -o main_undefined.cpp.o -c main_undefined.cpp -I./inc
gcc -o esp861.c.o -c esp861.c
g++ -o de03_undefined main_undefined.cpp.o esp861.c.o
de02_undefined.exe
```

将头文件中的函数声明，使用 `__cplusplus` 包裹以后，再编译，可以通过并执行。

```bash
g++ -std=c++11 -o main.cpp.o -c main.cpp -I./inc
gcc -o esp861.c.o -c esp861.c
g++ -o de03 main.cpp.o esp861.c.o
./de03
```

#### 纯 cpp 编译测试

纯 cpp 项目，不需要使用 `__cplusplus` 包裹，可以通过测试。

```bash
g++ -std=c++11 -o main_undefined.cpp.o -c main_undefined.cpp -I./inc
g++ -o esp861.cpp.o -c esp861.cpp
g++ -o de03_undefined main_undefined.cpp.o esp861.cpp.o
./de03_undefined
```