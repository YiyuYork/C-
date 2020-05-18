#include<stdio.h>
#define MAX 5

int power(int p[],int x){
	int i,power,y;
	power = 1;
	y = p[0];
	for(i=1;i<MAX;i++){
		power = power*x;
		y = y + p[i]*power;
	}
	return y;//返回值为计算  p[0]乘x的0次方 + p[1]乘x的1次方 + p[2]乘x的2次方 + ... + p[MAX-1]乘x的MAX-1次方
}

int main(){	
	int p[MAX] = {1,2,3,4,5};
	int w[MAX] = {0,1,2,3,4};
	int x;
	printf("please input the value of x:");
	scanf("%d",&x);
	printf("\n当x为%d的时候,结果为:%d",x,power(p,x));//返回结果为 p数组计算的结果 
	printf("\n当x为%d的时候,结果为:%d",x,power(w,x));//返回结果为 w数组计算的结果 
	return 0;
}
