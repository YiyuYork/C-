/*1. ��������1,2,3,4,5�����䰴���������洢�ڴ�ͷ���ĵ������У�Ȼ��������в�����
A. ����������н��ֵ
B. ������ֵΪż���Ľ��ǰ�����½�㣬���ֵΪ��ż����3�����ٴ��������
C. ɾ�����������и�λ��Ϊ2�Ľ�㣬�����������*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;//�����ṹ��

LinkList create()
{
	LinkList L,p;
	int x1,i;
	L=(LinkList)malloc(sizeof(Node));
	L->next = NULL;
	for(i=1;i<6;i++){
		p=(LinkList)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}//���


int main(){
    printf("Process is running...\n");
	//A
	LinkList head1,p1;
	head1=create();
	p1=head1->next;
	while(p1){
		printf("%d ",p1->data);
		p1=p1->next;

	}
    printf("\n===========================\n");

}
