#include<iostream>
#include<stdio.h>
using namespace std;

int middle(int a[]){
	if(a[0]<a[1]&&a[1]<a[2] || a[2]<a[1]&&a[1]<a[0])
		return a[1];
	else if(a[1]<a[0]&&a[0]<a[2] || a[2]<a[0]&&a[0]<a[1])
		return a[0];
	else
		return a[2];
}

int main(){
	int a[5] = {28,34,9807,1,-32}; 
	cout<<"middle number:"<<middle(a)<<endl;
}
