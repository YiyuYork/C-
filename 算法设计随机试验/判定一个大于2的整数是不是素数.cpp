#include<stdio.h>
#include<math.h>

int test(int x){
	int i;
	int s = sqrt(x);
	for(i=2;i<=s;i++){
		if(x%i==0)
			return false;
	}
	return true;
} 

int main(){	
	int x;
	printf("please input one number which greater than 2:");
	scanf("%d",&x);
	if(x>2){
		if(test(x))
			printf("%d是素数",x);
		else
			printf("%d不是素数",x);
	}
	else
		printf("the number you input is wrong");
	return 0;
}
