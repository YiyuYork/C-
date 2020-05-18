#include<iostream> 
#include <stdio.h>
#include <windows.h>
#include<iomanip>
using namespace std;

int shiyan1_2(int m,int n){
	int t;
	while((m-n)!=0){
		t=(m>n)?n:m;
		n=(m-n>0)?m-n:n-m;
		m=t;
	}
	return m;
}

int main(){
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	
	cout<<"output:"<<shiyan1_2(328,192)<<endl;
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout  << time; //µ¥Î»ÊÇÄÉÃë.
}
