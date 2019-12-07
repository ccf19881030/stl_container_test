# stl_container_test
《C++ STL与泛型编程高级-侯捷》视频中关于各种容器的测试代码
## 一、项目对应的Bilibili视频的地址为：[C++ STL与泛型编程高级-侯捷](https://www.bilibili.com/video/av48068999)
P3~P5讲解了容器之分类与各种测试，本项目是对应的源代码，在Windows下使用VS2013以及在CentOS7.6下测试过，在Linux下可以直接使用make和cmake进行编译。
## git获取项目源代码
git克隆源代码
```shell
[root@localhost STLDemo_houjie_leasson]# git clone https://github.com/ccf19881030/stl_container_test.git
```

## 二、在Linux下的编译测试如下：
### 1、使用makefile编译生成可执行文件
```shell
cd src
[root@localhost src]# ls
build  CMakeLists.txt  main.cpp  makefile  pub.h  test_array.hpp  test_deque.hpp  test_forwardlist.hpp  test_list.hpp  test_queue.hpp  test_slist.hpp  test_stack.hpp  test_vector.hpp
[root@localhost src]# make
g++ -o stl_container_test main.cpp -std=c++11
[root@localhost src]# ls
build  CMakeLists.txt  main.cpp  makefile  pub.h  stl_container_test  test_array.hpp  test_deque.hpp  test_forwardlist.hpp  test_list.hpp  test_queue.hpp  test_slist.hpp  test_stack.hpp  test_vector.hpp
[root@localhost src]# 
```
### 2、使用cmake编译生成可执行程序
```shell
[root@localhost stl_container_test]# cd src/
[root@localhost src]# ls
build  CMakeLists.txt  main.cpp  makefile  pub.h  stl_container_test  test_array.hpp  test_deque.hpp  test_forwardlist.hpp  test_list.hpp  test_queue.hpp  test_slist.hpp  test_stack.hpp  test_vector.hpp
[root@localhost src]# cd build/
[root@localhost build]# ls

[root@localhost build]# cmake ..
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /bin/cc
-- Check for working C compiler: /bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /bin/c++
-- Check for working CXX compiler: /bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test COMPILER_SUPPORTS_CXX11
-- Performing Test COMPILER_SUPPORTS_CXX11 - Success
-- Performing Test COMPILER_SUPPORTS_CXX0X
-- Performing Test COMPILER_SUPPORTS_CXX0X - Success
-- Configuring done
-- Generating done
-- Build files have been written to: /home/havealex/projects/Cpp_Demos/STLDemo_houjie_leasson/stl_container_test/src/build
[root@localhost build]# make
Scanning dependencies of target stl_container_test
[ 50%] Building CXX object CMakeFiles/stl_container_test.dir/main.cpp.o
[100%] Linking CXX executable stl_container_test
[100%] Built target stl_container_test
[root@localhost build]# ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  stl_container_test
[root@localhost build]# 
```

## 三、运行可执行程序
### 1、测试array
```shell
[root@localhost build]# ./stl_container_test 
select: 1
how many elements:1000000

test_array()......... 
milli-seconds:20000
array.size()= 1000000
array.front()= 52576
array.back()= 37040
array.data()= 0x7ffdba97f7a0
target (0~2147483647): 23456
-------------------before qsort: --------------
qsort(), milli-seconds: 200000
---------------------after qsort:------------------ 
array.size()= 1000000
array.front()= 0
array.back()= 65534
array.data()= 0x7ffdba97f7a0
bsearch(), milli-seconds: 0
found, 23456
[root@localhost build]# 
```

### 2、测试vector
```shell
[root@localhost build]# ./stl_container_test 
select: 2
how many elements:1000000

test_vector()......... 
milli-seconds:280000
vector.size()= 1000000
vector.front()= 43786
vector.back()= 45289
vector.data()= 0x7fd63c9e3010
vector.capacity()= 1048576
target (0~2147483647): 23456
::find(), mill-seconds: 0
found, 23456
sort()+bsearch(), milli-seconds: 1350000
found, 23456
[root@localhost build]# 
```
### 3、测试list
```shell
[root@localhost build]# ./stl_container_test 
select: 3
how many elements:1000000

test_list()......... 
milli-seconds:380000
list.size()= 1000000
list.max_size()= 768614336404564650
list.front()= 52776
list.back()= 15445
target (0~2147483647): 23456
::find(), mill-seconds: 10000
found, 23456
c.sort(), milli-seconds: 1730000
[root@localhost build]# 
```
### 4、测试forward_list
```shell
[root@localhost build]# ./stl_container_test 
select: 4
how many elements:1000000

test_forward_list()......... 
milli-seconds:400000
forward_list.max_size()= 1152921504606846975
forward_list.front()= 58416
target (0~2147483647): 23456
::find(), mill-seconds: 10000
found, 23456
c.sort(), milli-seconds: 2360000
[root@localhost build]# 
```

### 5、测试deque
```shell
[root@localhost build]# ./stl_container_test 
select: 5
how many elements:1000000

test_deque()......... 
milli-seconds:220000
deque.size()= 1000000
deque.max_size()= 2305843009213693951
deque.front()= 39552
deque.back()= 61479
target (0~2147483647): 23456
::find(), mill-seconds: 0
found, 23456
::sort(), milli-seconds: 1680000
[root@localhost build]# 
```
