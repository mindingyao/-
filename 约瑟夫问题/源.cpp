/*��Ŀ��Լɪ�����⡣����n��s��m������n��������Բ����Χ���ӵ�s���˿�ʼ������
	����m���˳��У�Ȼ���ٴ���һ���˿�ʼ����������m�����ֳ��У�����ظ���ֱ�����е��˶�����Ϊֹ��
	Ҫ������ʽ�ṹ��˳��ṹʵ�֣������е��Ⱥ�˳�����ÿ���˵���Ϣ��
�㷨˼�룺����ѭ������->�ҵ�Ԫ��->����->��ȡ���->ɾ��Ԫ��->����->.....->������һ��Ԫ�ر��*/

//Դ����
//˳��ṹ��

#include<stdio.h>
void main() {
	int n, s, m, i, j, k, w;
	printf("������n,s,m��ֵ���м��Կո����\n");
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
//��ʽ�ṹ��

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
	cout << "����n��ֵ:";
	cin >> n;
	cout << "������ʼ�����˺���k��ֵ:";
	cin >> k;
	cout << "��������m���е�mֵ:";
	cin >> m;
	head = (Node*)new Node;           //ȷ��ͷ���
	p = head;
	for (i = 1;i <= n - 1;i++)                         //����ֵ
	{
		p->data = i;
		p->pNext = (Node*)new Node;   //Ϊ��һ���½��ڴ�
		p = p->pNext;
	}
	p->data = n;                              //���һ����������
	p->pNext = head;                        //ָ��ͷ���γ�ѭ������
	p = head;

	while (p->data != (p->pNext)->data)            //p->data==(p->pNext)->data��ʾֻʣ��һ������
	{
		while (p->data != k)         //Ѱ�ұ��Ϊk�Ľ��
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
			for (i = 1;i<m - 1;i++)         //��ʼ����
			{
				p = p->pNext;
			}       //�ҵ���m-1�Ľ��

		q = p->pNext;       //qΪ��m�Ľ��
		cout << q->data << "\t";    //�����m�Ľ���ֵ
		k = (q->pNext)->data;     //kΪ��һ�����������
		p->pNext = q->pNext;     //ɾ����m�Ľ��
	}
	cout << p->data << '\n';      //������һ������ֵ
}