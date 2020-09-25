#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��realloc��free��exit ԭ��
#include <string.h>     // �ṩ strstr ԭ��
typedef int ElemType;

typedef struct LNode {
    ElemType data;      // ���ݽ��
    struct LNode* next; // ָ����һ������ָ��
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
    /*while(p->data==key)//��һ����� 
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
