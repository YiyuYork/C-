#include<iostream>
using namespace std;
//顺序查找算法 
int SeqSearch(int A[],int n,int k){
	int i=0; 
	for(;i<n;i++)
		if(A[i]==k)break;
	if(i==n)return 0;	//查找失败，返回失败的标志 
	else return i+1;	//查找成功，返回记录的序号（下标加一） 
}

int main(){
	int arr[] = {9,24,7,4232,646,5235,6443,6483,56};
	int k;
	cout<<"请输入你想查询的一个数:"<<endl;
	cin >>k;
	int result = SeqSearch(arr,9,k);
	if(result == 0)
	cout<<"查找失败"<<endl;
	else
	cout<<"查找成功,序号为:"<<result
	<<endl;
	return 0;
}
