#include<iostream>
#include<cstdlib>
using namespace std;
int DEBUG =0;

int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
int hex(int l,int x,int m,int k){
    int res=0;
    if(m==0){
        res=1;
    }else if(x==1){
        if(k>=m && m>l)res=1;
    }else{
        for(int i=0; i<=k; i++){
            if((m-i)>=0){
                res += hex(l-i*x,x-1,m-i,k);
                res %=100000007;
            }
        }
    }
    return res;
}
int main(int argc,char **argv){
    if(argc >=2){
        DEBUG = atoi(argv[1]);
    }
    int n,l,x,k;
    int m=5;
    if(scanf("%d%d%d%d",&n,&l,&x,&k)==4){
        int sum=0;
        for(int i=l; i<=n; i++){
            sum +=hex(i,x,m,k);
            sum %= 100000007;
            if(DEBUG)cout<<"i="<<i<<"sum="<<sum<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
    }
