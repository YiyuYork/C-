#include<iostream>
#include <stdio.h>
#include <windows.h>
#include<iomanip>
#include<math.h>
using namespace std;

struct point{
	int x,y;
};

double Distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int Partition(point r[],int first,int end){
	int i=first,j=end;
	while(i<j){
		while(i<j&&r[i].y<=r[j].y)j--;
		if(i<j){
			point temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i++;
		}
		while(i<j&&r[i].y<=r[j].y)i++;
		if(i<j){
			point temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			j--;
		}
	}
	return i;
}

void QuickSort(point r[],int first,int end){
	int pivot;
	if(first<end){
		pivot=Partition(r,first,end);
		QuickSort(r,first,pivot-1);
		QuickSort(r,pivot+1,end);
	}
}

void ClosePoints(point s[],int n){
	int index1,index2;
	int d,minDist=1000;
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			d = (s[i].x-s[j].x)*(s[i].x-s[j].x) + (s[i].y-s[j].y)*(s[i].y-s[j].y);
			if(d<minDist){
				minDist = d;
				index1=i;
				index2=j;
			}
		}
	}
	cout<<"蛮力法最近点距离:"<<sqrt(minDist)<<endl;
	cout<<"两个点分别为"<<"("<<s[index1].x<<","<<s[index1].y<<")"<<"和"<<"("<<s[index2].x<<","<<s[index2].y<<")"<<endl;
}

double Closest(point s[],int high,int low){
	double d1,d2,d3,d;
	int mid,i,j,index;
	point p[12];  //存放点集合p1,p2 
	if(high-low==1)
		return Distance(s[low],s[high]);
	if(high-low==2){
		d1=Distance(s[low],s[low+1]);
		d2=Distance(s[low+1],s[high]);
		d3=Distance(s[low],s[high]);
		if((d1<d2)&&(d1<d3))
			return d1;
		else if(d2<d3)
			return d2;
		else
			return d3;
	}
	mid = (low+high)/2; //计算中间点
	d1=Closest(s,low,mid);
	d2=Closest(s,mid+1,high);
	if(d1<=d2)
		d=d1;
	else
		d=d2;
	index=0;
	for(i=mid;(i>=low)&&(s[mid].x-s[i].x<d);i--)
		p[index++]=s[i];
	for(i=mid+1;(i<=high)&&(s[i].x-s[mid].x<d);i++)
		p[index++]=s[i];
	QuickSort(p,0,index-1);
	for(i=0;i<index;i++){
		for(j=i+1;j<index;j++){
			if(p[j].y-p[i].y>=d)
				break;
			else{
				d3=Distance(p[i],p[j]);
				if(d3<d)d=d3;
			}
		}
	}
	return d;
}

int main(){
	point s[12];
	for(int i=0;i<12;i++){
		cin>>s[i].x>>s[i].y;
	}
	
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	
	ClosePoints(s,12);
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);

    cout<<"蛮力法花费的时间:"<<time<<endl;
    
    cout<<"1"<<endl;
    LARGE_INTEGER nFreq1;
    LARGE_INTEGER nBeginTime1;
    LARGE_INTEGER nEndTime1;
    double time1;
	QueryPerformanceFrequency(&nFreq1);
	QueryPerformanceCounter(&nBeginTime1);
	
	cout<<"1"<<endl;
	cout<<"蛮力法最近对距离为:"<<Closest(s,0,12)<<endl;
	
	QueryPerformanceCounter(&nEndTime1);
	time1=(double)(nEndTime1.QuadPart-nBeginTime1.QuadPart)*1000000000/(double)(nFreq1.QuadPart);
	cout<<"分治法花费的时间:"<<time1<<endl;
}
