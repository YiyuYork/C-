#include <iostream>
#include <string.h>

using namespace std;

void GetNext(char T[],int next[]){
    int i,j,len;
    next[0]=-1;
    for(j=1;T[j]!='\0';j++){
        //�������next[j]
        for(len=j-1;len>=1;len--){//����Ӵ�����󳤶�Ϊj-1
            for(i=0;i<len;i++)//���αȽ�T[0]-T[len-1]��T[j-len]-T[j-1]
                if(T[i]!=T[j-len+i])break;
            if(i==len){
                next[j]=len;
                break;
            }
        }
        if(len<1) next[j]=0;//���������������Ӵ�

    }
}

int KMP(char S[],char T[]){//��T��S�е����
    int i=0,j=0;
    int next[80];//�ٶ�ģʽ�Ϊ80���ַ�
    GetNext(T,next);
    while(S[i]!='\0'&&T[j]!='\0'){
        if(S[i]==T[j]){
            i++;j++;
        }
        else{
            j=next[j];
            if(j==-1){
                i++;j++;
            }
        }
    }
    if(T[j]=='\0')//�˴���j ������
        return (i-strlen(T)+1);//���ر���ƥ��Ŀ�ʼλ��
    else
        return 0;
}

int main()
{
    char S[]="ababaababcb";
    char T[]="ababc";
    int result = KMP(S,T);
    if(result==0)
        cout<<"ƥ��ʧ��"<<endl;
    else
        cout<<"ƥ��ɹ���ƥ��Ŀ�ʼλ��Ϊ:"<<result<<endl;
    return 0;
}
