#include<iostream>
using namespace std;
#define N 10


int Coin(int a[],int low, int high,int n){
	int i,num1,num2,num3;
	int add1=0,add2=0,add3=0;
	if(n==1)
		return low+1;
	num1 = num2 = n/3;
	num3 = n - num1 - num2;
	//����
	for(i=0;i<num1;i++)
		add1=add1+a[low+i];
	for(i=num1;i<num1+num2;i++)
		add2=add2+a[low+i];
	//������ƽ���ߵ�����
	if(add1==add2)
		return Coin(a,low+num1+num2,high,num3);//�ڵ����� 
	else{
		for(i=high-num1+1;i<high+1;i++)
			add3 = add3+a[low+i];
		if(add1==add3)
			return Coin(a,low+num1,low+num1+num2,num2); //�ڵڶ���
		else
			return Coin(a,low,low+num1,num1); //�ڵ�һ��
	}
}

int main(){
	int a[N];
	int i;
	for (i = 0; i < N; i++)  
    	a[i] =1 ;     //����Ӳ�ҵ�����Ϊ1		
	int x = rand()%N; //����0��n�������       
	a[x] = 2;  //��xöӲ��Ϊ�ٱ�
	
	for(i = 0;i<N;i++)
		cout<<"a["<<i<<"]="<<a[i]<<endl;

	
	int jia = Coin(a,0,9,10);
	cout<<"�ٱ�Ϊ:"<<jia<<endl;
}
