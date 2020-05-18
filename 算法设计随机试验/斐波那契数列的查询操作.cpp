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
		return -1; //当输入的数字 n为负数或者不符合上述任一情形的，返回-1 
	}
}

void showFibonacci(int n){
	int array[MAX+1];
	int i;
	array[0] = 0;
	array[1] = 1;
	if(0<=n && n<=MAX){
		printf("斐波那契数列:\n");
		for(i = 2;i<=n;i++){
			array[i] = array[i-1] + array[i-2];
		}
		for(i = 0;i<=n;i++){
			printf("%4d ",array[i]);
		}
	}
	else if(n>MAX)
		printf("输入的n值超过了展示的范围\n");
	else
		printf("输入的n值不合法\n"); 
} 

int main(){
	int n;
	printf("输入你想要查看斐波那契序列的序号:");
	scanf("%d",&n); 
	if(n<0)
		printf("the number n is error\n");
	else
		printf("Fib(%d)=%d\n",n,Fibonacci(n));
	showFibonacci(n);
	return 0;
}
