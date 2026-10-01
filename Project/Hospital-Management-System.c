#include<stdio.h>
struct patient{
    int ID;
    int age;
    char name[50];
    char Docter[50];
    char Disease[50];
    float Bill;
    float Weight;
    float Height;
    char Gender[50];
    char Bloodgroup[5];
};
void input(struct patient patients[]){
    int choice;
    do{
        printf("Enter 1 for Display Table....\n");
        printf("Enter 2 for Total Amount.....\n");
        printf("Enter 3 for search by name......\n ");
         printf("Enter 4 for search by ID.....\n ");
        printf("Enter 5 for Total Male......\n ");
        printf("Enter 6 for Total Female.....\n ");
        printf("Enter 7 for search by Docter.....\n ");
        printf("Enter 8 for search by Disease.....\n ");
        printf("Enter 9 for Average bill amount....\n ");
        printf("Enter 10 for search by age range.....\n");
        printf("Enter 11 for Total femal bill.....\n");
        printf("Enter 12 for Total male bill....\n ");
        printf("Enter 13 for Emergency Patient.....\n ");
        printf("Enter 14 for Highest and lowest bill patient....\n");
        printf("Enter 15 for Exit.....\n ");
        printf("Enter your choice....\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("______________________________________________________________\n");
            printf("HOSPITAL MANAGEMENT SYSTEM\n");
            printf("______________________________________________________________\n");
            for(int i=0;i<10;i++){
                printf("%-4d,%-3d,%-10s,%-10s,%-10s,%-10f,%-10f,%-10f,%-10s,%-10s",
                patients[i].ID,
                patients[i].age,
                patients[i].name,
                patients[i].Docter,
                patients[i].Disease,
                patients[i].Bill,
                patients[i].Weight,
                patients[i].Height,
                patients[i].Gender,
                patients[i].Bloodgroup
                );
        }
             
            break;
            case 2:
            float sum=0.0;
            for(int i=1;i<=10;i++){
              sum=sum+patients[i].Bill;
            }
            printf("Total amount is: %f",sum);
            break;
            case 3:


        }


    }while(choice!=0);
    

}

int main(){
    
    struct patient patients[10]={
    {111,34,"Ali","Junaid","Malaria",15000.0,55.0,5.2,"Male","A"};
     {222,34,"Asad","Mehmood","Cancer",15000.0,56.0,5.2,"Male",'A'};
    {333,24,"Asif","Mustafa","Malaria",5000.0,55.0,6.2,"Male",'B'};
    {444,34,"Ahmed","Hashim","Diabates",65000.0,65.0,5.0,"Male",'O'};
    {555,38,"Kamran","Zakir","Typhoid",15000.0,45.0,5.2,"Male",'A'};
    {666,39,"Sajjad","Noman","Malaria",15000.0,45.0,5.4,"Male",'A'};
    {777,64,"Zahid","Zain","Hypertension",16000.0,58.0,5.7,"Male",'B'};
    {888,84,"Khadija","Fahad","Malaria",17000.0,59.0,5.2,"Female",'AB'};
    {999,64,"Uzma","Ahsan","Appendicitus",45000.0,75.0,5.7,"Female",'A'};
     {000,54,"Shoaib","Jalali","Malaria",25000.0,85.0,5.2,"Male",'A'}
    }
    input( patients);













    

   




}