#include<stdio.h>
#include "LinkList.h" 
 main()
 {
 	LinkList head,L,R;
 	InitList(&head);
 	L=head;
	int n,x;
	printf("����Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("����Ԫ�أ�\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		InitList(&R);
		R->data=x;
		R->next=NULL;
		L->next=R;
		L=R;
	}
	int key;
	printf("����key��\n");
	scanf("%d",&key);
	DelKey(head,key);
	print(head);
	getchar();
	getchar();
 }
