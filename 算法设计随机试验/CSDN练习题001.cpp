/*����Ҫ��ʵ��һ���������Ը�����һ���ַ����������ַ���
��ӡ�������ַ����д����һ���ַ�ƥ���λ�ÿ�ʼ����ڶ�
���ַ�ƥ���λ��֮��������ַ� */ 

//�����Ǹ����� ���в��Գ������� 
#include<stdio.h>

#define MAXS 10

char *match(char *s, char ch1, char ch2);

int main(){
	char str[MAXS],ch_start,ch_end,*p;
	scanf("%s\n",str);
	printf("str[0]:%c\n",str[0]);
	scanf("%c %c",&ch_start,&ch_end);
	p = match(str,ch_start,ch_end);
	printf("%s\n",p);
	
	return 0;
} 

//����
char *match(char *s, char ch1, char ch2){
	int count_start = 0,count_end = 0,count;
	while(count_start<10){
		if(s[count_start]==ch1)
		    break;
	}
	while(count_end<10){
		if(s[count_end]==ch2)
		    break;
	}
	printf("%d %d ch1:%c ch2:%c\n",count_start,count_end,ch1,ch2);
	if(count_start<=count_end&&s[count_start]==ch1&&s[count_end]==ch2){
		for(count = count_start;count<=count_end;count++)
			printf("%c",s[count]);
		printf("\n");
	}
	else{
		printf("ERROR\n");
	}
	char *p;
	p = &s[count_start];
	return p;
}
