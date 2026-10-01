#include<stdio.h>
void inputname(){
    char name;
    printf("Enter name...:");
    fgets(name,50,stdin);
}



int main(){
    inputname();
    displayname();
}