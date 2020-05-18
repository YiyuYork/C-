#include<iostream>
using namespace std;
//起泡排序算法 
void BubbleSort(int r[],int n){
	int bound,exchanger=n-1;	//第一趟起泡排序的区间是[0,n-1]
	while(exchanger != 0)		//当上一趟排序有记录交换时 
	{
		bound = exchanger;exchanger = 0;
		for(int j=0;j<bound;j++)//一趟起泡排序区间是[0,bound] 
			if(r[j]>r[j+1]){
				int temp = r[j];
				r[j] = r[j+1];
				r[j+1] = temp;//交换记录
				exchanger = j;//记载每一次记录交换的位置 
			}
	}
}

void printArr(int arr[],int n){
	//打印一个一维的数字数组
	int i=0;
	for(;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[]={34,12,65,23,674,23,1,54,7564,32,-2};
	cout<<"排序前:"<<endl;
	printArr(arr,11);
	BubbleSort(arr,11);
	cout<<"排序后:"<<endl;
	printArr(arr,11);
	return 0;
}
