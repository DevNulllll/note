#include<stdio.h>

int binarysearch(int x,int v[],int n)
{
    int left=0;
    int right=n;
    while(left<right){
        int mid=(right+left)/2;
        if(x<v[mid])right=mid;
        if(x>v[mid])left=mid+1;
        else return mid;
    }
    return -1;
}

int getline(char line(),int limit){
    int c,i;
    while(--limit>0 && (c=getchar()) !=EOF && c!='\n'){
        s[i++]=c;
    }
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}


int strindex(char s[],char t[]){
    int i,j,k;
    for(i=0;s[i]!='\0';i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];k++,j++);
        if(k>0 && t[k]=='\0')
            return i;
    }
    return -1;
}