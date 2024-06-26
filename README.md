# 数据结构练习(C语言)
***

本仓库用于记录个人对数据结构的复习

## 相关资料
- **教材** 《数据结构C语言版第二版》 清华大学出版社 严蔚敏 吴伟名 编著
- **教学视频** [数据结构与算法基础（青岛大学-王卓）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1nJ411V7bd/?vd_source=ce2c64e2380b23fc8a0d20d49c88b6aa)

## 目录

- ch01_linear_list 线性表
  - [p1_array_linear_list.c](ch01_linear_list/p1_array_linear_list.c) 线性表的顺序实现 
  - [p2_singly_linked_list_with_head.c](ch01_linear_list/p2_singly_linked_list_with_head.c) 线性表的带头单链表实现
  - [p3_circular_linked_list_with_head.c](ch01_linear_list/p3_circular_linked_list_with_head.c) 带头循环链表，尾指针
  - [p4_doubly_linked_list.c](ch01_linear_list/p4_doubly_linked_list.c) 双向链表

- ch02_stack 栈
  - [p1_array_stack.c](ch02_stack/p1_array_stack.c) 栈的顺序实现
  - [p2_linked_stack.c](ch02_stack/p2_linked_stack.c) 栈的链式实现

- ch03_queue 队列
  - [p1_array_queue.c](ch03_queue/p1_array_queue.c) 队列的顺序循环实现
  - [p2_linked_queue.c](ch03_queue/p2_linked_queue.c) 队列的单链表实现

- ch04_string 串
  - [p1_array_string.c](ch04_string/p1_array_string.c) 串的顺序实现，含KMP

- ch05_array
  - [p1_cross_linked_list.c](ch05_array/p1_cross_linked_list.c) 十字链表

- ch06_tree 树
  - [p1_binary_tree_array.c](ch06_tree/p1_binary_tree_array.c) 顺序存储表示二叉树
  - [p2_binary_tree_linked_list.c](ch06_tree/p2_binary_tree_linked_list.c) 单链表表示二叉树，先序、中序、后序遍历
  - [p3_huffman_tree.c](ch06_tree/p3_huffman_tree.c) 数组构建哈夫曼树

- ch07_graph 图
  - [p1_adjacency_matrix.c](ch07_graph/p1_adjacency_matrix.c) 邻接矩阵（数组表示法）
  - [p2_adjacency_list.c](ch07_graph/p2_adjacency_list.c) 邻接表

- ch08_search 查找
  - [p1_sequential_search.c](ch08_search/p1_sequential_search.c) 顺序查找
  - [p2_binary_search.c](ch08_search/p2_binary_search.c) 折半查找
  - [p3_binary_sort_tree.c](ch08_search/p3_binary_sort_tree.c) 二叉排序树
  - [p4_avl_tree.c](ch08_search/p4_avl_tree.c) 二叉平衡树（插入）

- ch09_sort 排序
  - [p1_insertion_sort.c](ch09_sort/p1_insertion_sort.c) 插入排序（直接插入排序，折半插入排序，2-路插入排序）
  - [p2_exchange_sort.c](ch09_sort/p2_exchange_sort.c) 交换排序（冒泡排序，快速排序）
  - [p3_selection_sort.c](ch09_sort/p3_selection_sort.c) 选择排序（简单选择排序，堆排序）