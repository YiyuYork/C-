#include<iostream> 
#include <stdio.h>
#include <windows.h>
#include<iomanip>
using namespace std;

int shiyan1_2(int m,int n){
	int r;
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
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
	
	cout<<"output:"<<shiyan1_2(2744,1176)<<endl;
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout  << time; //µ¥Î»ÊÇÄÉÃë.
}
