#include<iostream>
using namespace std;
//���������㷨 
void BubbleSort(int r[],int n){
	int bound,exchanger=n-1;	//��һ�����������������[0,n-1]
	while(exchanger != 0)		//����һ�������м�¼����ʱ 
	{
		bound = exchanger;exchanger = 0;
		for(int j=0;j<bound;j++)//һ����������������[0,bound] 
			if(r[j]>r[j+1]){
				int temp = r[j];
				r[j] = r[j+1];
				r[j+1] = temp;//������¼
				exchanger = j;//����ÿһ�μ�¼������λ�� 
			}
	}
}

void printArr(int arr[],int n){
	//��ӡһ��һά����������
	int i=0;
	for(;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[]={34,12,65,23,674,23,1,54,7564,32,-2};
	cout<<"����ǰ:"<<endl;
	printArr(arr,11);
	BubbleSort(arr,11);
	cout<<"�����:"<<endl;
	printArr(arr,11);
	return 0;
}
