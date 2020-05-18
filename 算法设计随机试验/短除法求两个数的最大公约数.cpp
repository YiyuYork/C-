#include<stdio.h>

int CommonFactor1(int m,int n){
	int factor = 1,i = 2;
	for(;i <= m && i <= n;i++){
		while(m%i==0&&n%i==0){
			factor *= i;
			m/=i;
			n/=i;
		}
	}
	return factor;
}

int main(){
	printf("%d",CommonFactor1(48,56)); //输出48与56的最大公约数
	return 0;
}
