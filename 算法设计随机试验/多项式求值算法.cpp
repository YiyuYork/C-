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
	return y;//����ֵΪ����  p[0]��x��0�η� + p[1]��x��1�η� + p[2]��x��2�η� + ... + p[MAX-1]��x��MAX-1�η�
}

int main(){	
	int p[MAX] = {1,2,3,4,5};
	int w[MAX] = {0,1,2,3,4};
	int x;
	printf("please input the value of x:");
	scanf("%d",&x);
	printf("\n��xΪ%d��ʱ��,���Ϊ:%d",x,power(p,x));//���ؽ��Ϊ p�������Ľ�� 
	printf("\n��xΪ%d��ʱ��,���Ϊ:%d",x,power(w,x));//���ؽ��Ϊ w�������Ľ�� 
	return 0;
}
