# 线性表抽象类型定义
```C
ADT List { 
	数据对象：D = { a_i | a_i 属于 Elemset, i=1,2,3,...,n,n >= 0}
	数据关系：R_1 = { <a_{i-1},a_i> | a_{i-1},a_i \in D, i=2,3,...,n }
	基本操作：
		InitList(&L)
			初始条件：无
			操作结果：构造一个空的线性表
		DestroyList(&L)
			初始条件：线性表L已经存在
			操作结果：构造一个空的线性表
		ClearList(&L)
			初始条件：线性表L已经存在
			操作结果：将L重置为空表
		ListEmpty(L)
			初始条件：线性表L已经存在
			操作结果：为空返回true，否则返回false
		ListLength(L)
			初始条件：线性表L已经存在
			操作结果：返回L中数据元素个数
		GetElem(L,i,&e)
			初始条件：线性表L已经存在,1 <= i <= ListLength(L)
			操作结果：用e返回L中第i个数据元素的值
		LocateElem(L,e,compare())
			初始条件：线性表L已经存在,compare()是数据元素判定函数
			操作结果：返回第一个满足关系的compare的数据元素的位序，不存在返回0
		PriorElem(L,cur_e,&pre_e)
			初始条件：线性表L已经存在
			操作结果：cur_e是L的数据元素，且不是第一个，则用pre_e返回前驱，操作失败
			无定义
		NextElem( L, cur_e, &next_e)
			初始条件：线性表L已存在。
			操作结果：若cur_e是L的数据元素，且不是最后一个，则用 next_e返回它的后继，
			否则操作失败，next_e无定义。
		ListInsert( &L, i, e)
			初始条件：线性表L已存在，1≤i≤ListLength(L)+1。
			操作结果:在L中第i个位置之前插入新的数据元素e,L的长度加1。
		ListDelete(&L, i, &e)
			初始条件：线性表L已存在且非空，1≤i≤ListLength(L)。
			操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。
}ADT List
```