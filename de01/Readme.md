### 动态链接库
de01 这是一个简单的动态链接库的例子


生成 libA 链接库
```bash
cd libA
gcc -fPIC -shared -o libA.so libA.c metric.c -I../inc/ 
```

生成 libB 链接库
```bash
cd libB
gcc -fPIC -shared -o libB.so libB.c -I../inc/
```

编译主程序
```bash
gcc -o main main.c -I./inc/ -L./libA -lA -L./libB -lB
```

运行主程序
```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
./main
```