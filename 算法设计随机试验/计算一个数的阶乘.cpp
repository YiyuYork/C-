#include<stdio.h>

int Factorial(int n){	//Factorial ��Ϊ���׳� n��n���е�n 
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
	printf("������Ҫ�����nֵ:");
	scanf("%d",&x);
	if(x<0)
		printf("�����nֵ����С��0.");
	else
	printf("%d��= %d",x,Factorial(x));
	return 0;
} 
