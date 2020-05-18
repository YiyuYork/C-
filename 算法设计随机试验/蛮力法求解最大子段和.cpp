#include<iostream>
#include <windows.h>
#include<iomanip>
using namespace std;

int MaxSum1(int a[],int len){
	int maxSum = 0;
    int sum = 0;
    int i;
    int j;
    for(i = 0; i < len; i++) //�ӵ�һ������ʼ����
    {
        sum = a[i];
        for(j = i + 1; j < len; j++)//��i����һ������ʼ
        {
            a[i] += a[j];
            if(a[i] > sum)
            {
                sum = a[i];//ÿһ�˵����ֵ
            }
        }

        if(sum > maxSum)
        {
            maxSum = sum;
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
	int a = MaxSum1(arr,6);
	
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);
	cout<<"����Ӷκ�:"<<a<<endl;
    cout  << time; //��λ������.
	
	return 0;
}

