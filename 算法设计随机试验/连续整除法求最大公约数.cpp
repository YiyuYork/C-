#include<iostream> 
#include <stdio.h>
#include <windows.h>
#include<iomanip>
using namespace std;

int shiyan1_1(int m,int n){
	int t;
	if(m<n)
		t=m;
	else
		t=n;
	 
	while(m%t!=0||n%t!=0){
		t--;
	}
	return t;
} 

int main(){
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	
	cout<<"output:"<<shiyan1_1(2744,1176)<<endl;
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout  << time; //µ¥Î»ÊÇÄÉÃë.
}
