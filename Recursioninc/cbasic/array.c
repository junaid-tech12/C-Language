#include<stdio.h>
int main(){
    int number[5];
    for(int i=0;i<5;i++){
        printf("Enter number %d: ",i+1);
        scanf("%d",&number[i]);
    }
    for(int i=0;i<5;i++){
        printf("number is %d\n",number[i]);
    }
    printf("the first number is: %d\n",number[0]);
    number[2]=100;
    printf("the third number is: %d\n",number[2]);
    int sizeofnumber=sizeof(number)/sizeof(number[0]);
    printf("the size of the array is: %d\n",sizeofnumber);
    return 0;
}