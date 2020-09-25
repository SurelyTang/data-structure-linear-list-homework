#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>     // 提供 strstr 原型
typedef int ElemType;

typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;
typedef LNode* LinkList;
void InitList(LinkList* L) {
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit;
    }
    (*L)->next = NULL;
} 
void DelKey(LinkList L,int key)
{
	LinkList p, q;
    int j;
    if(L == NULL || L->next == NULL) {
        return;
    }
    p=L;
    /*while(p->data==key)//第一个结点 
    {
    	L=L->next;
		p=L; 
	}*/
	while(p->next!=NULL)
	{
		q=p->next;
		while(q->data==key&&q->next!=NULL)
		{
			p->next = q->next;
    		free(q);
    		q=p->next;
		}
		if(q->data==key&&q->next==NULL)
		{
			p->next=NULL;
			break; 
		}
		p=p->next;
	} 
 } 
void print(LinkList L)
{
	while(L->next!=NULL)
	{
		L=L->next;
		printf("%d ",L->data);
	}
} 
void CheckList(LinkList L)
{
	LinkList p, q;
	if(L == NULL || L->next == NULL) {
        return;
    }
    p=L;
	while(p->next!=NULL)
	{
		q=p->next;
		int key=q->data;
		DelKey(q,key);
		p=p->next;
	 } 
}
