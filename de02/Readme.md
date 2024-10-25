### 学习使用 gprof

de02 使用 gprof 对 demo01 继续性能测试的例子

初衷：测试动态链接库函数的性能。  
先说结论：gprof、valgrind、perf 本示例未成功实现对动态链接库函数的性能分析。  
现有成果：完成 gprof、valgrind 对主程序 main.c 的性能分析。

#### 主函数 gcc 添加 pg 参数

在函数中添加阻塞函数，模拟占用时间。

生成 libA 链接库
```bash
cd libA
gcc  -fPIC -shared -o libA.so libA.c metric.c -I../inc/ 
```

生成 libB 链接库
```bash
cd libB
gcc -fPIC -shared -o libB.so libB.c -I../inc/
```

添加 -pg 选项，在执行后，生成 gmon.out 文件
编译主程序
```bash
gcc -pg -o main main.c -I./inc/ -L./libA -lA -L./libB -lB
```

运行主程序
```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
./main
```

查看性能分析结果
```bash
gprof ./main gmon.out > profile.txt
```

查看调用图
```bash
gprof -q -b -p ./main gmon.out > callgraph.txt
```

无论是 profile.txt 还是 callgraph.txt 中均未发现 libA 和 libB 中函数的性能分析报告。

#### 针对 libA 和 libB 添加 pg 参数

```bash
cd libA
gcc -pg -fPIC -shared -o libA-pg.so libA.c metric.c -I../inc/
```

```bash
cd libB
gcc -pg -fPIC -shared -o libB-pg.so libB.c -I../inc/
```

```bash
gcc -pg -o main main.c -I./inc/ -L./libA -lA-pg -L./libB -lB-pg
```

```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
./main
```

```bash
gprof ./main gmon.out > profile.txt
```

没用，该方法生成的 profile.txt 还是没有 libA 和 libB 中函数的性能分析报告。

#### 备注
> 查看 so 文件的依赖库
```bash
cd libA
ldd libA.so
```

```bash
cd libB
ldd libB.so
```

#### valgrind 测试

```bash
cd libA
gcc -g -O0 -shared -o libA.so libA.c metric.c -fPIC -I ../inc/
```
```bash
cd libB
gcc -g -O0 -shared -o libB.so libB.c -fPIC -I ../inc/
```
```bash
gcc -g -o main main.c -L./libA -lA -L./libB -lB -I./inc/
```

使用 callgrind 工具进行性能分析，启动程序，收集数据
```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
#valgrind --tool=callgrind ./main
valgrind --tool=callgrind --instr-atstart=yes ./main
```

查看性能分析结果
`callgrind_annotate callgrind.out.<pid>`
```bash
callgrind_annotate callgrind.out.2299791
```

```bash
qcachegrind callgrind.out.2293170
```
未曾观察到针对动态链接库函数的分析报告，报告详细程度不如 gprof。

#### perf 使用教程
安装 perf，ubuntu
```bash
sudo apt-get install linux-tools-common linux-tools-generic
```

与　valgrind 类似，依次编译 libA 和 libB，主程序
```bash
cd libA
gcc -g -O0 -shared -o libA.so libA.c metric.c -fPIC -I ../inc/
```
```bash
cd libB
gcc -g -O0 -shared -o libB.so libB.c -fPIC -I ../inc/
```
```bash
gcc -g -o main main.c -L./libA -lA -L./libB -lB -I./inc/
```

使用 perf 收集数据
```bash
export LD_LIBRARY_PATH=./libA:./libB:$LD_LIBRARY_PATH
perf record -g ./main
```
执行失败，error，Error: Access to performance monitoring and observability operations is limited.

```bash
perf report
```

> 安装指定版本的 perf 
```bash
sudo apt-get install linux-tools-5.15.0-124-generic linux-cloud-tools-5.15.0-124-generic
```
验证
```bash
perf --version
```