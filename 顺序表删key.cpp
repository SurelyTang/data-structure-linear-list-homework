#include <stdio.h>
#include"SqList.h"
main()
{
	SqList L;
	InitList(&L);
	int n,x;
	printf("����Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("����Ԫ�أ�\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		ListAdd(&L,x);
	}
	int key;
	//printf("%d %d",L.elem[2],L.elem[6]);
	printf("����key��\n");
	scanf("%d",&key);
	CheckKey(&L,key);
	print(L);
	getchar(); 
	getchar();
 } 
