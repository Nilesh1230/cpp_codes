#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_nondec(int n,int m,int i,int out[],int len,unordered_map<int,int>&mpp,int &c){
    if(len==m){
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=0; i<m; i++)
            mp[out[i]]++;
            
            for(int i=1; i<=n; i++){
                maxi=max(maxi,mp[i]);
            }
            mpp[maxi]++;
            c++;
            return;
        }
        for(int j=i; j<=n; j++){
            out[len]=j;
            print_nondec(n,m,j,out,len+1,mpp,c);
        }
}
int main(){
    int n,m;
    cin>>m>>n;
    int out[m];
    unordered_map<int,int>mp;
    int c=0;
    print_nondec(n,m,1,out,0,mp,c);
    float ans=0;
    for(auto it:mp){
        ans+=(float)it.first*it.second/c;
    }
    cout<<ans;
    return 0;
}
