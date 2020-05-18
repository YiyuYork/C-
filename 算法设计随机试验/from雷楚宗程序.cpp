#include<stdio.h>
int main (void){

	int i,j,t;

	int a[10];

	for(i= 0;i<10;i++){
		scanf("%d",&a[i]);
	}

	for(i= 0;i<10;i++){

		for(j=0;j<9-i;j++)
		{

			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for (j=0;j<10;j++){
		
		printf("%d ",a[j]) ;
		
	}

	return 0 ;

}
