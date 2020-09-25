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
    // 分配指定容量的内存，如果分配失败，则返回NULL
    (*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if((*L).elem == NULL) {
        // 存储内存失败
        exit;
    }
    (*L).length = 0;                    // 初始化顺序表长度为0
    (*L).listsize = LIST_INIT_SIZE;     // 顺序表初始内存分配量
}
void ListDelete(SqList* L, int i) {
    ElemType* p, * q;
    if(L == NULL || (*L).elem == NULL) {
        return;
    }
    if(i < 1 || i > (*L).length) {
        return;
    }
    
    // p为被删除元素的位置
    p = &(*L).elem[i - 1];
    // 表尾元素位置
    q = (*L).elem + (*L).length - 1;
    // 2.左移元素，被删除元素的位置上会有新元素进来
    for(++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    // 3.表长减1
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
