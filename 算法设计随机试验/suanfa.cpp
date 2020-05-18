#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char arr[] = "abcdabmmaa";
	int count = 0,i=0;
	char temp;
	int len = strlen(arr);
	char x;
	cout<<"ÊäÈëx:"<<endl; 
	cin>>x;
	while(i<len){
		if(arr[i]==x){
			temp=arr[i];
			arr[i]=arr[len-1-count];
			arr[len-1-count]='\0';
			count++;
		}
		if(arr[i]!=x)
			i++;
	}
	for(i=0;arr[i]!='\0';i++){
		cout<<arr[i]<<endl;
	}
	return 0;
} 
