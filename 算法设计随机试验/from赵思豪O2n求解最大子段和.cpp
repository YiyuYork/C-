#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int *maxSum(int a[], int len){
	int sum,MaxSum;
	int i, *index;
    index = (int *)malloc(sizeof(int)*3);   //申请空间
	//初始化sum，然后开始累加 
	sum = a[0];
	MaxSum = a[0];
	index[1]=0;
	for(i=1;i<len;i++){
		sum = a[i] + sum;
		if(sum>MaxSum){
			MaxSum = sum;
			index[1] = i;
		}
	}
	//调整sum，然后开始反向累加
	sum = a[len-1];
	MaxSum = a[len-1];
	index[2]=len;
	for(i=len-2;i>=0;i--){
		sum = a[i] + sum;
		if(sum>MaxSum){
			MaxSum = sum;
			index[2] = i;
		}
	}
	//输出index的值 
	cout << "index[1]:" << index[1] << endl << "index[2]:" << index[2] << endl;
	//累加求最大子段和的值
	MaxSum = 0;
	for(i=index[2]; i<=index[1]; i++)
        MaxSum+=a[i];
    index[0]=MaxSum;
    return index;
//以下是赵思豪的代码 
/*
    int sum = 0;
    int max = 0;
    //int *index;
    int i, *index;

    index = (int *)malloc(sizeof(int)*3);   //申请空间

    for(i=0; i<len; i++){
        sum+=a[i];
        if(max<sum){
            max=sum;
            index[1] = i;   //右端
            cout<<"index[1]"<<index[1]<<endl;
        }
    }
    max = 0;
    for(i=len-1; i>=0; i--){
        sum+=a[i];
        if(max<sum){
            max=sum;
            index[2] = i;   //左端
            cout<<"index[2]"<<index[2]<<endl;
        }
    }
    max = 0;
    cout << "index[1]:" << index[1] << endl << "index[2]:" << index[2] << endl;
    for(i=index[2]; i<index[1]; i++)	//累加求最大子段和并赋值给max 
        max+=a[i];
    index[0]=max;
    return index;
*/
}
int main()
{
    int a[6] = {-20, 11, -4, 13, -5, -2};
    int *max;

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);

    max = maxSum(a, 6);

    QueryPerformanceCounter(&nEndTime);
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout << "最大子段和是：" << max[0] << endl;
    cout << "Start：" << max[2] << endl;
    cout << "End：" << max[1] << endl;
    cout << "Time used: " << time << endl;
    return 0;
}
