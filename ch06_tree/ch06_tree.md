# 树抽象定义
```C
ADT BinaryTree{
	数据对象D：D是具有相同特性的数据元素的集合
	数据关系R：
		若D为空集，则R也是空集，称为空二叉树
		若D不为空集，则有R={H}，H是如下关系：
			（1）根的说明：若D中存在唯一的称为根的数据元素root，它在关系H下无前驱
			（2）子树不相较的说明：若D-{root}不等于空，D-{root} = {D1,Dr},且D1,Dr
			的交集为空
			（3）数据元素的说明：若D1不为空集，则D1中存在唯一的元素x1，<root,x1>属于
			H，且存在D1上的关系H1属于H；若DR不等于空，则DR中存在唯一的元素xr，
			<root,xr>属于H，且存在Dr上的关系Hr为H的子集
			（4）关于左右子树的说明(D1,{h1})是一棵符合本定义的二叉树，称为根的左子树，
			(Dr,{Hr})是一棵符合本定义的二叉树，称为根的右子树
	基本操作P：
		InitBiTree(&T);
			操作结果：构造空二叉树T
		DestroyBiTree(&T);
			初始条件：二叉树T存在。
			操作结果：销毁二叉树T。
		CreateBiTree(&T, definition);
			初始条件：definition给出二叉树T的定义，此处的定义是指按照深度或广度构建
			操作结果：按definition构造二叉树T。
		ClearBiTree(&T);
			初始条件；二叉树工存在。
			操作结果：将二叉树T清为空树。
		BiTreeEmpty(T);
			初始条件：二叉树T存在。
			操作结果：若为空二叉树，则返回TRUE，否则FALSE。
		BiTreeDepth(T);
			初始条件：二叉树T存在。
			操作结果：返回T的深度。
		Root(T);
			初始条件：二叉树T存在。
			操作结果：返回T的根。
		Value(T,e);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：返回e的值。
		Assign(T, &e, value);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：结点e赋值为value。
		Parent(T, e);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：若e是T的非根结点，则返回它的双亲，否则返回“空”。
		LeftChild(T,e);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：返回e的左孩子。若e无左孩子，则返回“空”。
		RightChild(T, e);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：返回e的右孩子。若e无右孩子，则返回“空”。
		LeftSibling(T, e);
			初始条件：二叉树存在，e是T中某个结点。
			操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空”。
		RightSibling(T,e);
			初始条件：二叉树T存在，e是T中某个结点。
			操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回“空”。
		InsertChild(T, p, LR, c);
			初始条件：二叉树工存在，P指向T中某个结点，LR为0或1，非空二叉树c与T不相交
			且右
			子树为空。
			操作结果：根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有
			左或右子树则成为c的右子树。
		DeleteChild(T, p, LR);
			初始条件：二叉树T存在，P指向T中某个结点，LR为0或1。
			操作结果：根据LR为0或1，删除T中p所指结点的左或右子树。
		PreOrderTraverse(T, Visit());
			初始条件：二叉树T存在，Visit是对结点操作的应用函数。
			操作结果：先序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit（）
			失败，则操作失败。
		InOrderTraverse(T, Visit());
			初始条件：二叉树T存在，Visit是对结点操作的应用函数。
			操作结果：中序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit（）
			失败，则操作失败。
		PostOrderTraverse(T, Visit());
			初始条件：二叉树T存在，Visit是对结点操作的应用函数。
			操作结果：后序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit(）失
			败，则操作失败。
		LevelOrderTraverse(T, Visit());
			初始条件：二叉树T存在，Visit是对结点操作的应用函数。
			操作结果：层序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit()失
			败，则操作失败。
}ADT BinaryTree
```