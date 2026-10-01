#include<stdio.h>
int main(){
    char name[100];
    printf("Enter your name:");
    fgets(name,sizeof(name),stdin);
    FILE*J;
    J=fopen("name.txt","w");
    if(J==NULL){
        printf("Not saved");
        return 1;
    }
    fprintf(J,"%s",name);
    
    fclose(J);

}