# stl_container_test
《C++ STL与泛型编程高级-侯捷》视频中关于各种容器的测试代码
## 一、项目对应的Bilibili视频的地址为：[C++ STL与泛型编程高级-侯捷](https://www.bilibili.com/video/av48068999)
P3~P5讲解了容器之分类与各种测试，本项目是对应的源代码，在Windows下使用VS2013以及在CentOS7.6下使用g++编译器测试过，在Linux下可以直接使用make和cmake进行编译生成相应的可执行程序。
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
STL标准库主要分为两种类型的容器：顺序容器和关联容器,常见的顺序容器有array、vector、list、forward_list、deque、stack、queue，关联容器有map、set、unordered_map等，使用100万个元素进行测试，通过将放入100万元素到各种容器，排序、查找并输出所消耗的时间，来测试容器的性能。
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

### 6、测试multiset
```shell
[root@192 src]# ./stl_container_test 
select: 6
how many elements:1000000

test_multiset()......... 
milli-seconds:2690000
multiset.size()= 1000000
multiset.max_size()= 461168601842738790
target (0~2147483647): 23456
::find(), mill-seconds: 50000
found, 23456
c.find(), mill-seconds: 0
found, 23456
[root@192 src]# 
```

### 7、测试multimap
```shell
[root@192 src]# ./stl_container_test 
select: 7
how many elements:1000000

test_multimap()......... 
milli-seconds:890000
multimap.size()= 1000000
multimap.max_size()= 384307168202282325
target (0~2147483647): 23456
c.find(), mill-seconds: 0
found, 65155
[root@192 src]# 
```

### 8、测试unordered_multiset
```shell
[root@192 src]# ./stl_container_test 
select: 8
how many elements:1000000

test_unordered_multiset()......... 
milli-seconds:1210000
unordered_multiset.size()= 1000000
unordered_multiset.max_size()= 768614336404564650
unordered_multiset.bucket_count()= 1056323
unordered_multiset.load_factor()= 0.94668
unordered_multiset.max_load_factor()= 1
unordered_multiset.max_bucket_count()= 768614336404564650
bucket #0 has 0 elements.
bucket #1 has 0 elements.
bucket #2 has 0 elements.
bucket #3 has 0 elements.
bucket #4 has 13 elements.
bucket #5 has 0 elements.
bucket #6 has 0 elements.
bucket #7 has 0 elements.
bucket #8 has 0 elements.
bucket #9 has 9 elements.
bucket #10 has 0 elements.
bucket #11 has 0 elements.
bucket #12 has 0 elements.
bucket #13 has 0 elements.
bucket #14 has 0 elements.
bucket #15 has 0 elements.
bucket #16 has 0 elements.
bucket #17 has 0 elements.
bucket #18 has 0 elements.
bucket #19 has 0 elements.
target (0~2147483647): 23456
::find(), mill-seconds: 50000
found, 23456
c.find(), mill-seconds: 0
found, 23456
[root@192 src]# 
```

### 9、测试unordered_multimap
```shell
[root@192 src]# ./stl_container_test 
select: 9
how many elements:1000000

test_unordered_multimap()......... 
milli-seconds:540000
unordered_multimap.size()= 1000000
unordered_multimap.max_size()= 768614336404564650
target (0~2147483647): 23456
c.find(), mill-seconds: 0
found, 52657
[root@192 src]# 
```

### 10、测试slist
```shell
[root@localhost src]# ./stl_container_test 
select: 10
how many elements:1000000

test_slist()......... 
milli-seconds:320000
slist.size()= 1000000
slist.front()= 20326
target (0~2147483647): 23456
::find(), mill-seconds: 0
found, 23456
c.sort(), milli-seconds: 1300000
[root@localhost src]# 
```
### 13、测试set
```shell
[root@192 src]# ./stl_container_test 
select: 13
how many elements:1000000

test_set()......... 
milli-seconds:1570000
set.size()= 65535
set.max_size()= 461168601842738790
target (0~2147483647): 23456
::find(), mill-seconds: 0
found, 23456
c.find(), mill-seconds: 0
found, 23456
[root@192 src]# 
```

### 14、测试map
```shell
[root@192 src]# ./stl_container_test 
select: 14
how many elements:1000000

test_map()......... 
milli-seconds:1180000
map.size()= 1000000
map.max_size()= 384307168202282325
target (0~2147483647): 23456
c.find(), mill-seconds: 0
found, 5333
[root@192 src]# 
```

### 15、测试unordered_set
```shell
[root@192 src]# ./stl_container_test 
select: 15
how many elements:1000000

test_unordered_set()......... 
milli-seconds:740000
unordered_set.size()= 65535
unordered_set.max_size()= 768614336404564650
target (0~2147483647): 23456
::find(), mill-seconds: 0
found, 23456
c.find(), mill-seconds: 0
found, 23456
[root@192 src]# 
```

### 16、测试unordered_map
```shell
[root@192 src]# ./stl_container_test 
select: 16
how many elements:1000000

test_unordered_map()......... 
milli-seconds:630000
unordered_map.size()= 1000000
unordered_map.max_size()= 768614336404564650
target (0~2147483647): 23456
c.find(), mill-seconds: 0
found, 13602
[root@192 src]# 
```

### 17、测试stack
```shell
[root@localhost src]# ./stl_container_test 
select: 17
how many elements:1000000

test_stack()......... 
milli-seconds:250000
stack.size()= 1000000
stack.top()= 53045
stack.size()= 999999
stack.top()= 9409
[root@localhost src]# 
```

### 18、测试queue
```shell
[root@localhost src]# ./stl_container_test 
select: 18
how many elements:1000000

test_stack()......... 
milli-seconds:260000
queue.size()= 1000000
queue.front()= 60351
queue.back()= 41216
queue.size()= 999999
queue.front()= 65064
queue.back()= 41216
[root@localhost src]# 
```
