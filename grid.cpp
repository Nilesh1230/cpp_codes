#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<string>
#include<assert.h>
#include<stdlib.h>
using namespace std;
int a[50][50];
int cnt=0;

void solve(int i, int j, int n,int m,int k){
    if(i==n){
        cnt=(cnt+1)%1000000007;
        return;
    }
    if(j==m){
        solve(i+1,0,n,m,k);
        return;
    }
    int p=-1,q=-1;
    if(j!=0)p=a[i][j-1];
    if(i!=0)q=a[i-1][j];
    for(int x=1; x<=k; x++){
        if(x!=p && x!=q){
            a[i][j]=x;
            solve(i,j+1,n,m,k);
        }
    }
}
int main(){
    int t,i,j,x,y,n,m,k;
    cin>>n>>m>>k;
    solve(0,0,n,m,k);
    cout<<cnt<<endl;
    return 0;
}