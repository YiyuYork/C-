#include <iostream>
#include <string.h>

using namespace std;

void GetNext(char T[],int next[]){
    int i,j,len;
    next[0]=-1;
    for(j=1;T[j]!='\0';j++){
        //依次求解next[j]
        for(len=j-1;len>=1;len--){//相等子串的最大长度为j-1
            for(i=0;i<len;i++)//依次比较T[0]-T[len-1]与T[j-len]-T[j-1]
                if(T[i]!=T[j-len+i])break;
            if(i==len){
                next[j]=len;
                break;
            }
        }
        if(len<1) next[j]=0;//其他情况，无相等子串

    }
}

int KMP(char S[],char T[]){//求T在S中的序号
    int i=0,j=0;
    int next[80];//假定模式最长为80个字符
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
    if(T[j]=='\0')//此处是j ！！！
        return (i-strlen(T)+1);//返回本趟匹配的开始位置
    else
        return 0;
}

int main()
{
    char S[]="ababaababcb";
    char T[]="ababc";
    int result = KMP(S,T);
    if(result==0)
        cout<<"匹配失败"<<endl;
    else
        cout<<"匹配成功，匹配的开始位置为:"<<result<<endl;
    return 0;
}
