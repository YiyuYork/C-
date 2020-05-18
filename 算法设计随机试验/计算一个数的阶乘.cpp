#include<stdio.h>

int Factorial(int n){	//Factorial 意为：阶乘 n是n！中的n 
	int p = 1;
	int i;
	if(n==0)
		return 1;
	else
		for(i = 1;i <= n;i++){
			p = p*i;
		}
	return p;
}

int main(){
	int x;
	printf("输入需要计算的n值:");
	scanf("%d",&x);
	if(x<0)
		printf("输入的n值不能小于0.");
	else
	printf("%d！= %d",x,Factorial(x));
	return 0;
} 
