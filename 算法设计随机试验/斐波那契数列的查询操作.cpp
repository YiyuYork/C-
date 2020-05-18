#include<stdio.h>
#define MAX 20

int Fibonacci(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else if(n>=2){
		return Fibonacci(n-1) + Fibonacci(n-2);
	}
	else{
		return -1; //����������� nΪ�������߲�����������һ���εģ�����-1 
	}
}

void showFibonacci(int n){
	int array[MAX+1];
	int i;
	array[0] = 0;
	array[1] = 1;
	if(0<=n && n<=MAX){
		printf("쳲���������:\n");
		for(i = 2;i<=n;i++){
			array[i] = array[i-1] + array[i-2];
		}
		for(i = 0;i<=n;i++){
			printf("%4d ",array[i]);
		}
	}
	else if(n>MAX)
		printf("�����nֵ������չʾ�ķ�Χ\n");
	else
		printf("�����nֵ���Ϸ�\n"); 
} 

int main(){
	int n;
	printf("��������Ҫ�鿴쳲��������е����:");
	scanf("%d",&n); 
	if(n<0)
		printf("the number n is error\n");
	else
		printf("Fib(%d)=%d\n",n,Fibonacci(n));
	showFibonacci(n);
	return 0;
}
