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
	CheckSame(&L);
	print(L);
	getchar();
	getchar();
 } 
