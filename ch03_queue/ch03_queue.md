# 队列抽象类型定义
```C
ADT Queue {
	数据对象：D = {a_i | a_i 属于 ElemSet， i=1,2,…,n,n≥O)
	数据关系：R=(<a_i-1，a_i>|a_i-1，a_i属于D，i=2,…,n)
			约定a_1端为队头，a_n端为队尾。
	基本操作：
		InitQueue(&Q)
			操作结果：构造一个空队列Q
		DestroyQueue(&Q)
			初始条件：队列Q已存在。
			操作结果：队列Q被销毁，不再存在
		ClearQueue(&Q)
			初始条件：队列Q已存在
			操作结果：将Q清为空队列
		QueueEmpty(Q)
			初始条件：队列Q已存在。
			操作结果：若Q为空队列，则返回 TRUE，否则 FALSE
		QueueLength(Q)
			初始条件：队列Q已存在。
			操作结果：返回Q的元素个数，即队列的长度
		GetHead(Q，&e）
			初始条件：Q为非空队列。
			操作结果：用e返回Q的队头元素
		EnQueue(&Q, e)
			初始条件：队列Q已存在。
			操作结果：插入元素e为Q的新的队尾元素
		DeQueue(&Q,&e)
			初始条件:Q为非空队列。
			操作结果；删除Q的队头元素，并用e返回其值。
}ADT Queue
```