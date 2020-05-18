#include<iostream>
using namespace std;

void Hanoi(int n,char A, char B ,char C){
	if(n==1)cout<<A<<"-->"<<C<<endl;
	else {
		Hanoi(n-1,A,C,B);
		cout<<A<<"-->"<<C<<endl;
		Hanoi(n-1,B,A,C);
	}
}

int main(){
	int n;
	cin>>n;
	Hanoi(n,'A','B','C');
}
