#include<stdio.h>
int merge_count(int arr[],int l,int m,int r){
    int i,j,k;
    int inv_count=0;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0; i<n1; i++){
        L[i]=arr[l+i];
    }
    for(j=0; j<n2; j++){
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
            inv_count+=(m-i+1);
        }
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    return inv_count;
}
int merge_sort(int arr[],int l,int r){
    int inv_count=0;
    if(r<l){
        int m=l+(r-l)/2;
        inv_count+=merge_sort(arr,l,m);
        inv_count+=merge_sort(arr,m+1,r);
        inv_count+=merge_count(arr,l,m,r);
    }
    return inv_count;
}
int get_inversion(int arr[],int n){
   return merge_sort(arr,0,n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter %d  element",n);
    // for(int i=0; i<n; i++){
    //     scanf("%d",&arr[i]);
    // }
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    printf("\n");
    }
    int inversion_count=get_inversion(arr,n);
    printf("%d\n",inversion_count);
    return 0;
}