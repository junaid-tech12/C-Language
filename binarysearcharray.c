#include<stdio.h>
int binarysearch(int array[],int size,int num){ 
    int start=0,end=size-1,mid; 
    
    while(start<=end){ 
        mid=(start+end)/2; 
        if(num==array[mid]){
            return mid;
        }else if(num>array[mid]){
            start=mid+1;

            
        }else{
            end=mid-1;
        }

    }
    return -1;
    
}
int main(){
    int n;
    int array[]={10,20,30,20,40,20};
    printf("Enter a Number to search....:");
    scanf("%d",&n);
    int result=binarysearch(array,5,n);
    if(result!=-1){
        printf("Value found at index %d\n",result);
    }else{
        printf("Value Not found\n");
    }
    return 0;

}