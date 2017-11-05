/*题目：约瑟夫问题。输入n，s，m，设有n个人坐在圆桌周围，从第s个人开始报数，
	报到m的人出列，然后再从下一个人开始报数，数到m的人又出列，如此重复，直到所有的人都出列为止。
	要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。
算法思想：建立循环链表->找到元素->报数->获取编号->删除元素->报数->.....->输出最后一个元素编号*/

//源程序：
//顺序结构：

#include<stdio.h>
void main() {
	int n, s, m, i, j, k, w;
	printf("请输入n,s,m的值，中间以空格隔开\n");
	scanf("%d %d %d", &n, &s, &m);
	int p[100];
	for (i = 1;i <= n;i++) p[i] = i;
	k = s;
	for (i = n;i >= 2;i--) 
	{
		k = (k + m - 1) % i;
		if (k == 0) k = i;
		w = p[k];
		if (k<i)
			for (j = k;j<i;j++) p[j] = p[j + 1];
		p[i] = w;
	}
	for (i = n;i >= 2;i--)	printf("%d ", p[i]);
	printf("%d\n", p[1]);
	printf("\n");
}
//链式结构：

#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *pNext;
};

void main()
{
	int n, k, m, i;
	Node *p, *q, *head;
	cout << "输入n的值:";
	cin >> n;
	cout << "输入起始报数人号码k的值:";
	cin >> k;
	cout << "输入数到m出列的m值:";
	cin >> m;
	head = (Node*)new Node;           //确定头结点
	p = head;
	for (i = 1;i <= n - 1;i++)                         //赋初值
	{
		p->data = i;
		p->pNext = (Node*)new Node;   //为下一个新建内存
		p = p->pNext;
	}
	p->data = n;                              //最后一个单独处理
	p->pNext = head;                        //指向头，形成循环链表
	p = head;

	while (p->data != (p->pNext)->data)            //p->data==(p->pNext)->data表示只剩下一个结点的
	{
		while (p->data != k)         //寻找编号为k的结点
			p = p->pNext;
		if (m == 1)
		{
			for (i = 1;i <= n;i++)
			{
				cout << p->data << '\t';
				p = p->pNext;
			}
			cout << '\n';
			return;
		}
		else
			for (i = 1;i<m - 1;i++)         //开始报数
			{
				p = p->pNext;
			}       //找到报m-1的结点

		q = p->pNext;       //q为报m的结点
		cout << q->data << "\t";    //输出报m的结点的值
		k = (q->pNext)->data;     //k为下一个报数的起点
		p->pNext = q->pNext;     //删除报m的结点
	}
	cout << p->data << '\n';      //输出最后一个结点的值
}