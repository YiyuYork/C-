#include<stdio.h>

int CommonFactor(int m,int n){
	int r = m % n;
	while(r != 0){
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}

int main(){
	printf("%d",CommonFactor(4,6)); //输出4与6的最大公因数 
	return 0;
}
