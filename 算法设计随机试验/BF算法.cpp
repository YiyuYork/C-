#include<iostream> 
#include <stdio.h>
#include <windows.h>
#include<iomanip>
using namespace std;

int BF(char S[ ], char T[ ]) 
{
    int i=0;
	int j=0;   
    while ((S[i] != '\0') && (T[j] != '\0'))
    {
         if (S[i]==T[j]) {i++; j++;}  
         else {i=i-j+1; j=0; }   
    }
    if (T[j]=='\0') return (i-j+1);   //返回的不是下标 
    else return 0;
}

int main(){
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	
	char S[] = "ababcabccabcacbab";
	char T[] = "abcac";
	cout<<"output:"<<BF(S,T)<<endl;
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout  << time; //单位是纳秒.
}
