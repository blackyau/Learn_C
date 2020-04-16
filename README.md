# C语言 数据结构学习

## 单链表 初始化 头节点

[linked_single_init_head.c](https://github.com/blackyau/Learn_C/blob/master/linked_single_init_head.c)

仅初始化单节点，并保留头节点。下面是运行后打印的结果：

```
node[0]->value:-842150451
node[1]->value:1
node[2]->value:2
node[3]->value:3
node[4]->value:4
```

## 单链表 查询值 删除值

[linked_single_find_del.c](https://github.com/blackyau/Learn_C/blob/master/linked_single_find_del.c)

在单链表中查询指定值，并返回匹配节点的指针，打印值。找不到就打印-1，删除指定值的节点。运行后打印结果：

```
node[0]:-842150451
node[1]:1
node[2]:2
node[3]:3
node[4]:4
now:3
next:4
node[0]:-842150451
node[1]:1
node[2]:3
node[3]:4
```

## 单链表 循环链表

[linked_loop.c](https://github.com/blackyau/Learn_C/blob/master/linked_loop.c)

循环链表中插入节点，删除指定值的节点。运行后打印结果：

<details>
<summary>展开查看</summary>

```
node[0]: 0, next:node[1]: 1
node[1]: 1, next:node[1]: 2
node[2]: 2, next:node[2]: 3
node[3]: 3, next:node[0]: 0

insert -1 after node->value == 0
node[0]: 0, next:node[1]:-1
node[1]:-1, next:node[1]: 1
node[2]: 1, next:node[2]: 2
node[3]: 2, next:node[3]: 3
node[4]: 3, next:node[0]: 0

insert -1 after node->value == 1
node[0]: 0, next:node[1]:-1
node[1]:-1, next:node[1]: 1
node[2]: 1, next:node[2]:-1
node[3]:-1, next:node[3]: 2
node[4]: 2, next:node[4]: 3
node[5]: 3, next:node[0]: 0

insert -1 after node->value == 3
node[0]: 0, next:node[1]:-1
node[1]:-1, next:node[1]: 1
node[2]: 1, next:node[2]:-1
node[3]:-1, next:node[3]: 2
node[4]: 2, next:node[4]: 3
node[5]: 3, next:node[5]:-1
node[6]:-1, next:node[0]: 0

insert -1 after node->value == 6
node[0]: 0, next:node[1]:-1
node[1]:-1, next:node[1]: 1
node[2]: 1, next:node[2]:-1
node[3]:-1, next:node[3]: 2
node[4]: 2, next:node[4]: 3
node[5]: 3, next:node[5]:-1
node[6]:-1, next:node[0]: 0

rm node->value == -1
node[0]: 0, next:node[1]: 1
node[1]: 1, next:node[1]: 2
node[2]: 2, next:node[2]: 3
node[3]: 3, next:node[0]: 0
```
</details>

## 双向链表

[linked_double.c](https://github.com/blackyau/Learn_C/blob/master/linked_double.c)

在双向链表，任意下标位置后面插入节点。运行后打印结果：

<details>
<summary>展开查看</summary>

```
Node[0]->prior:NULL, Node[0]->value: 0, Node[0]->next:   1
Node[1]->prior:   0, Node[1]->value: 1, Node[1]->next:   2
Node[2]->prior:   1, Node[2]->value: 2, Node[2]->next:   3
Node[3]->prior:   2, Node[3]->value: 3, Node[3]->next:NULL

inser -1 after node[1]
Node[0]->prior:NULL, Node[0]->value: 0, Node[0]->next:   1
Node[1]->prior:   0, Node[1]->value: 1, Node[1]->next:  -1
Node[2]->prior:   1, Node[2]->value:-1, Node[2]->next:   2
Node[3]->prior:   1, Node[3]->value: 2, Node[3]->next:   3
Node[4]->prior:   2, Node[4]->value: 3, Node[4]->next:NULL

inser -1 after node[4]
Node[0]->prior:NULL, Node[0]->value: 0, Node[0]->next:   1
Node[1]->prior:   0, Node[1]->value: 1, Node[1]->next:  -1
Node[2]->prior:   1, Node[2]->value:-1, Node[2]->next:   2
Node[3]->prior:   1, Node[3]->value: 2, Node[3]->next:   3
Node[4]->prior:   2, Node[4]->value: 3, Node[4]->next:  -1
Node[5]->prior:   3, Node[5]->value:-1, Node[5]->next:NULL

inser -1 after node[3]
Node[0]->prior:NULL, Node[0]->value: 0, Node[0]->next:   1
Node[1]->prior:   0, Node[1]->value: 1, Node[1]->next:  -1
Node[2]->prior:   1, Node[2]->value:-1, Node[2]->next:   2
Node[3]->prior:   1, Node[3]->value: 2, Node[3]->next:  -1
Node[4]->prior:   2, Node[4]->value:-1, Node[4]->next:   3
Node[5]->prior:   2, Node[5]->value: 3, Node[5]->next:  -1
Node[6]->prior:   3, Node[6]->value:-1, Node[6]->next:NULL
```
</details>

# TODO

## 单链表

- [X] 循环链表
- [ ] 双向链表
- [ ] 双向循环链表

## 栈

...

# License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.