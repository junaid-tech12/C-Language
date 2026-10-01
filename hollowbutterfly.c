#include<stdio.h>
int main(){
    int n,i,j,k,l;
    printf("Enter a number of rows: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n;j++){
            if(j==1||j==2*n||j==i||j==2*n-i+1){
                printf("*");
            }else{
                printf(" ");
            }

        }
        printf("\n");
    }
    for(i=n;i>=1;i--){
        for(j=1;j<=2*n;j++){
             if(j==1||j==2*n||j==i||j==2*n-i+1){
                printf("*");
            }else{
                printf(" ");
            }

            
        }
        printf("\n");
    
    }
    
    
}