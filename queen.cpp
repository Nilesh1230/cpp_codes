#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int possible(int row,int col[]){
    for(int i=row-1; i>=0; --i){
        if(col[row]==col[i]||abs(col[row]-col[i])==row-i){
            return 0;
        }
    }
    return 1;
}

void q_pos(int row,int col[],int n_queen){
    if(possible(row,col)){
        if(row==n_queen-1){
            for(int i=0; i<n_queen; i++){
                printf("%d ",col[i]+1);
            }
            printf("\n");
        }else{
            for(int i=n_queen-1; i>=0; i--){
                col[row+1]=i;
                q_pos(row+1,col,n_queen);
            }
        }
    }

}

// void q_pos(int row,int col[],int n_queen){
//     if(possible(row,col)){
//         if(row==n_queen){
//             for(int i=0; i<n; i++){
//             printf("%d",col[i]+1);
//          }
//          printf("\n");
//          return;
//     }
//     for(int i=0; i<n_queen; i++){
//         col[row]=i;
//         if(possible(row,col)){
//             q_pos(row+1,col,n_queen);
//         }
//     }
// }
int main(){
    int n_queen;
    scanf("%d",&n_queen);
    int col[n_queen];
    q_pos(-1,col,n_queen);
    return 0;
}