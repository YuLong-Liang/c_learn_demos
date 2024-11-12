### 动态链接库
de01 这是一个简单的动态链接库的例子

libA 依赖 libB 和 metric.c。
main.c 依赖 libA。

生成 libA 链接库 libA.so，libA.so 实际上没有包含 libB.c 的函数实现。
但是 libA.c 通过 libB.h 的函数声明调用了未曾实现的函数。
这种情况在 ubuntu 下可以编辑通过，但是在 windows cygwin 下会报错，undefined reference to xxx。

```bash
cd libA
gcc -fPIC -shared -o libA.so libA.c metric.c -I../inc/ 
```

生成 libB 链接库
```bash
cd libB
gcc -fPIC -shared -o libB.so libB.c -I../inc/
```

编译主程序，在编译时使用 -lA 和 -lB 标志时，gcc 会在指定的库目录（使用 -L 指定的目录）中查找 libA.so 和 libB.so。
编译器不会将库的实际二进制代码包含在生成的可执行文件中。
相反，它将依赖信息写入可执行文件，这意味着在运行时需要这些库的存在。
```bash
gcc -o main main.c -I./inc/ -L./libA -lA -L./libB -lB
```

运行主程序，在执行时需要加载 .so 动态链接库。
疑问，main 可执行程序中是否包含 libA.so 和 libB.so ？
回答，不会包含。main 可执行程序中只包含了 libA.so 和 libB.so 的引用信息。
设置环境变量 LD_LIBRARY_PATH 来指定动态链接器搜索库的路径。
```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
./main
```
使用动态链接库的主要优点是减少程序的大小以及允许库的共享和更新，而不需要重新编译依赖这些库的程序。
