#include<iostream>
#include <windows.h>
#include<iomanip>
using namespace std;

int  MaxSum2(int a[],int len){
	int i;
	int maxSum = 0;
	int b[len] = {0};
	b[0] = a[0];
	maxSum = b[0]; //�ݶ�b[0]Ϊ����Ӷκ�
	for (i = 1; i < len; i++) {
        if (b[i - 1] > 0)
            b[i] = b[i - 1] + a[i];
        else {
            b[i] = a[i];
        }
        if (b[i] > maxSum) {
            maxSum = b[i];
        }
    }
    return maxSum;
}

int main(){
	int arr[]={-2,11,-4,13,-5,-2};
	
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	int a = MaxSum2(arr,6); 
//	cout<<"����Ӷκ�:"<<MaxSum2(arr,6)<<endl;
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);
	cout<<"����Ӷκ�:"<<a<<endl;
    cout  << time; //��λ������.
	
	return 0;
}
