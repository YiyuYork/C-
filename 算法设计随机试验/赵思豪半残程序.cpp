/*1. 键盘输入1,2,3,4,5，将其按输入的逆序存储在带头结点的单链表中，然后完成下列操作：
A. 输出链表所有结点值
B. 在所有值为偶数的结点前插入新结点，结点值为该偶数的3倍，再次输出链表。
C. 删除链表中所有个位数为2的结点，输出最后的链表。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;//建立结构体

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
}//结点


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
