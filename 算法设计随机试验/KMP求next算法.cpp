#include<iostream> 
#include <stdio.h>
#include <windows.h>
#include<iomanip>
using namespace std;

void GetNext(char T[ ], int next[ ]) 
{
 	next[0]=-1;
  	int j=1, k=0;
   	while (T[j]!='\0') 
       	if ((k==0)||(T[j-1]==T[k-1])) {
      		j++;
      		k++;
      		next[j]=k;
     	}
    else k=next[k];
}

void getNext(char T[] , int next[]){
	int j=0, k=-1;
	next[0]=-1;
	while(T[j]!='\0'){
		if(k==-1) {
			next[++j]=0; k=0;
		}
		else if(T[j]==T[k]){
			k++; next[++j]=k;
		}
		else
			k=next[k];
	}
}


int main(){
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	
	char T[] = "abcac";
	int next[6];
	GetNext(T,next);
	for(int i = 0;i<=5;i++){
		cout<<"next["<<i<<"]="<<next[i]<<endl;
	}
	//GetNext 是下标从1开始的
	//getNext 是下标从0开始的 
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout  << time; //单位是纳秒.
}
