#include<iostream>
using namespace std;

void Union(int A[],int n,int B[],int m,int C[]){
	//合并两个升序序列 A 和 B 为一个升序序列 C 
	int i=0,j=0,k=0;
	while(i<n&&j<m){
		if(A[i]<=B[j])C[k++]=A[i++];//A[i]和B[j]中较小者存入C[k] 
		else C[k++]=B[j++];
	}
	while(i<n)C[k++]=A[i++];//收尾处理，序列 A 或 B中还有剩余记录 
	while(j<m)C[k++]=B[j++];
}
int main(){
	int a[] = {1,4,7,9,23};
	int b[] = {2,8,14,16,18,60};
	int c[11];
	Union(a,5,b,6,c);
	for(int i = 0;i<11;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
