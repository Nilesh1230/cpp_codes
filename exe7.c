#include<stdio.h>
#include<string.h>
int min(int a,int b,int c){
    int m=a;
    if(b<m)m=b;
    if(c<m)m=c;
    return m;
}
int func(char* a,char* b){
    int m=strlen(a);
    int n=strlen(b);
    int t[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                t[i][j]=j*2;
            }
            else if(j==0){
                t[i][j]=i*2;
            }
            else if(a[i-1]==b[j-1]){
                t[i][j]=t[i-1][j-1]+0;
            }
            else{
                t[i][j]=min(t[i-1][j]+2,t[i][j-1]+2,t[i-1][j-1]+1);
            }
        }
    }
    return t[m][n];
}
int main(){
    char a[30];
    char b[30];
    printf("enter string:\n");
    scanf("%s",&a);
    scanf("%s",&b);
    int r=func(a,b);
    printf("resultant distance is :%d",r);
}