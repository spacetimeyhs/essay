#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList *L) 
{
/*initialize the linklist*/
	*L=(LinkList)malloc(sizeof(struct LNode));
	if(!*L)
		exit(OVERFLOW);
	(*L)->next=NULL;
	return OK;
}//InitList

Status ListInsert(LinkList L,int i,ElemType e) 
{
/*insert x into node linklist L,locate before i*/
	int j=0;
	LinkList p=L,s;
	while(p&&j<i-1) 
	{ 
	/*find the i-1 node*/
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
		return ERROR;
	s=(LinkList)malloc(sizeof(struct LNode));
	s->data=e; /*insert into linklist L*/
	s->next=p->next;
	p->next=s;
	return OK;
}//ListInsert

Status ListTraverse(LinkList L,void(*vi)(ElemType))
{
/*traverse linklist use vi*/
	LinkList p=L->next;
	while(p) 
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}//ListTraverse

void visit(ElemType c) 
{
	printf("%d ",c);
}//visit

LNode* Locate(LinkList L,int x) 
{
/*find x in linklist L,return x's locate*/
	LinkList p;
	if(x>Length(L)) return NULL;
	for(p=L->next; p&&p->data!=x; p=p->next);
	return p;
}//Locate

int Length(LinkList L) 
{
/*return the linklist length*/
	int k;
	LinkList p;
	for(k=0,p=L; p->next; p=p->next,k++);
	return k;
}//Length

Status LinkList_reverse(LinkList L) 
{
/*reverse the linklist*/
	LinkList p,q,s;
	p=L->next;
	q=p->next;
	s=q->next;
	p->next=NULL;
	if(!q->next) 
	{
		L->next=q;
		q->next=p;
		p->next=NULL;
		return OK;
	}
	while(s->next) 
	{
		q->next=p;
		p=q;
		q=s;
		s=s->next; //insert elem into new linklist head
	}
	q->next=p;
	s->next=q;
	L->next=s;
	return OK;
}//LinkList_reverse

void main() 
{
	LinkList L;
	LNode*p;
	ElemType e;
	Status i;
	int j;
	i=InitList(&L);
	for(j=1; j<=8; j++)
		i=ListInsert(L,1,j);
	printf("��L�ı�ͷ���β���1��5��L=");
	ListTraverse(L,visit);
	printf("�õ�����ĳ���Ϊ%d\n",Length(L));
	printf("������Ҫ���ҵ����֣�");
	scanf("%d",&e);
	p=Locate(L,e);
	if(p) 
	{
		printf("������Ԫ��%d�ĵ�ֵַΪ:%d\n",e,p);
		printf("��ַ%d���洢������Ϊ:%d\n",p,p->data);
	} else
		printf("δ�ҵ�Ҫ���ҵ�����\n");
	LinkList_reverse(L);
	printf("������͵����ú�Ľ����:");
	ListTraverse(L,visit);
}
