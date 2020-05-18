#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int *maxSum(int a[], int len){
	int sum,MaxSum;
	int i, *index;
    index = (int *)malloc(sizeof(int)*3);   //����ռ�
	//��ʼ��sum��Ȼ��ʼ�ۼ� 
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
	//����sum��Ȼ��ʼ�����ۼ�
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
	//���index��ֵ 
	cout << "index[1]:" << index[1] << endl << "index[2]:" << index[2] << endl;
	//�ۼ�������Ӷκ͵�ֵ
	MaxSum = 0;
	for(i=index[2]; i<=index[1]; i++)
        MaxSum+=a[i];
    index[0]=MaxSum;
    return index;
//��������˼���Ĵ��� 
/*
    int sum = 0;
    int max = 0;
    //int *index;
    int i, *index;

    index = (int *)malloc(sizeof(int)*3);   //����ռ�

    for(i=0; i<len; i++){
        sum+=a[i];
        if(max<sum){
            max=sum;
            index[1] = i;   //�Ҷ�
            cout<<"index[1]"<<index[1]<<endl;
        }
    }
    max = 0;
    for(i=len-1; i>=0; i--){
        sum+=a[i];
        if(max<sum){
            max=sum;
            index[2] = i;   //���
            cout<<"index[2]"<<index[2]<<endl;
        }
    }
    max = 0;
    cout << "index[1]:" << index[1] << endl << "index[2]:" << index[2] << endl;
    for(i=index[2]; i<index[1]; i++)	//�ۼ�������ӶκͲ���ֵ��max 
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

    cout << "����Ӷκ��ǣ�" << max[0] << endl;
    cout << "Start��" << max[2] << endl;
    cout << "End��" << max[1] << endl;
    cout << "Time used: " << time << endl;
    return 0;
}
