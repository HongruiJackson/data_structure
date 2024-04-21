# 栈抽象类型定义
```C
ADT Stack {
	数据对象：D = {a_i | a_i 属于 ElemSet， i=1,2,…,n,n≥O)
	数据关系：R1=(<a_i-1，a_i>|a_i-1，a_i属于D，i=2,…,n)
			约定a_n端为栈顶，a_i端为栈底。
	基本操作：
		InitStack(&S)
			操作结果：构造一个空栈S。
		DestroyStack(&S)
			初始条件：栈S已存在。
			操作结果：栈S被销毁。
		ClearStack(&S)
			初始条件：栈S已存在。
			操作结果：将S清为空栈。
		StackEmpty(S)
			初始条件：栈S已存在。
			操作结果：若栈S为空栈，则返回 TRUE，否则FALSE。
		StackLength(S)
			初始条件：栈S已存在。
			操作结果：返回S的元素个数，即栈的长度。
		GetTop(s, &e)
			初始条件；栈S已存在且非空。
			操作结果：用e返回S的栈顶元素。
		Push(&S, e)
			初始条件：栈S已存在。
			操作结果：插入元素e为新的栈顶元素。
		Pop(&S,&e)
			初始条件：栈S已存在且非空。
			操作结果；删除S的栈顶元素，并用e返回其值。
		StackTraverse(S,visit())
		初始条件；栈S已存在且非空。
			操作结果：从栈底到栈顶依次对S的每个数据元素调用函数visit()。一旦visit()失败，则操作失效。
}ADT Stack
```