#include<iostream>
using namespace std;
//˳������㷨 
int SeqSearch(int A[],int n,int k){
	int i=0; 
	for(;i<n;i++)
		if(A[i]==k)break;
	if(i==n)return 0;	//����ʧ�ܣ�����ʧ�ܵı�־ 
	else return i+1;	//���ҳɹ������ؼ�¼����ţ��±��һ�� 
}

int main(){
	int arr[] = {9,24,7,4232,646,5235,6443,6483,56};
	int k;
	cout<<"�����������ѯ��һ����:"<<endl;
	cin >>k;
	int result = SeqSearch(arr,9,k);
	if(result == 0)
	cout<<"����ʧ��"<<endl;
	else
	cout<<"���ҳɹ�,���Ϊ:"<<result
	<<endl;
	return 0;
}
