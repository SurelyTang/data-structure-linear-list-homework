#include<stdio.h> 
#include <stdlib.h>  
#define LIST_INIT_SIZE 1000
#define LISTINCREMENT  10
typedef int ElemType;

typedef struct {
    ElemType* elem;
    int length;
    int listsize;
} SqList;

void InitList(SqList* L) {
    // ����ָ���������ڴ棬�������ʧ�ܣ��򷵻�NULL
    (*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if((*L).elem == NULL) {
        // �洢�ڴ�ʧ��
        exit;
    }
    (*L).length = 0;                    // ��ʼ��˳�����Ϊ0
    (*L).listsize = LIST_INIT_SIZE;     // ˳����ʼ�ڴ������
}
void ListDelete(SqList* L, int i) {
    ElemType* p, * q;
    if(L == NULL || (*L).elem == NULL) {
        return;
    }
    if(i < 1 || i > (*L).length) {
        return;
    }
    
    // pΪ��ɾ��Ԫ�ص�λ��
    p = &(*L).elem[i - 1];
    // ��βԪ��λ��
    q = (*L).elem + (*L).length - 1;
    // 2.����Ԫ�أ���ɾ��Ԫ�ص�λ���ϻ�����Ԫ�ؽ���
    for(++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    // 3.����1
    (*L).length--;
}
void ListAdd(SqList* L,int k)
{
	(*L).elem[(*L).length++]=k;
 } 
void CheckKey(SqList *L,int key)
{
	for(int i=0;i<(*L).length;i++)
	{
		if((*L).elem[i]==key)
		{
			ListDelete(L,i+1);
			i--;
		}
	}
}
void CheckSame(SqList *L)
{
	for(int i=0;i<(*L).length;i++)
	{
		int key=(*L).elem[i];
		for(int j=i+1;j<(*L).length;j++)
		if((*L).elem[j]==key)
		{
			ListDelete(L,j+1);
			j--;
		}
	}
}
void print(SqList L)
{
	for(int i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
}
