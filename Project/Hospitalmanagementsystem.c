#include<stdio.h>
#include<string.h>

struct patient
{
    int ID;
    int age;
    char name[50];
    char doctor[50];
    char disease[50];
    float bill;
    float weight;
    float height;
    char gender[10];
    char bloodGroup[5];
};

/* Function Prototypes */

void menu(struct patient patients[]);
void displayTable(struct patient patients[]);
void totalBill(struct patient patients[]);
void searchByName(struct patient patients[]);
void searchByID(struct patient patients[]);
void totalMale(struct patient patients[]);
void totalFemale(struct patient patients[]);
void searchByDoctor(struct patient patients[]);
void searchByDisease(struct patient patients[]);
void averageBill(struct patient patients[]);
void ageRange(struct patient patients[]);
void femaleBill(struct patient patients[]);
void maleBill(struct patient patients[]);
void emergencyPatient(struct patient patients[]);
void highestLowestBill(struct patient patients[]);

int main()
{
    struct patient patients[10]=
    {
        {111,34,"Ali","Junaid","Malaria",15000,55,5.2,"Male","A"},
        {222,28,"Asad","Mehmood","Cancer",80000,60,5.6,"Male","B"},
        {333,24,"Asif","Mustafa","Malaria",5000,55,6.2,"Male","B"},
        {444,34,"Ahmed","Hashim","Diabetes",65000,65,5.5,"Male","O"},
        {555,38,"Kamran","Zakir","Typhoid",15000,45,5.2,"Male","A"},
        {666,39,"Sajjad","Noman","Malaria",15000,45,5.4,"Male","A"},
        {777,64,"Zahid","Zain","Hypertension",16000,58,5.7,"Male","B"},
        {888,84,"Khadija","Fahad","Malaria",17000,59,5.2,"Female","AB"},
        {999,64,"Uzma","Ahsan","Appendicitis",45000,75,5.7,"Female","A"},
        {1000,54,"Shoaib","Jalali","Malaria",25000,85,5.8,"Male","A"}
    };

    menu(patients);

    return 0;
}

void menu(struct patient patients[])
{
    int choice;

    do
    {
        printf("\n==========================================\n");
        printf("      HOSPITAL MANAGEMENT SYSTEM\n");
        printf("==========================================\n");

        printf("1. Display Table\n");
        printf("2. Total Bill\n");
        printf("3. Search by Name\n");
        printf("4. Search by ID\n");
        printf("5. Total Male Patients\n");
        printf("6. Total Female Patients\n");
        printf("7. Search by Doctor\n");
        printf("8. Search by Disease\n");
        printf("9. Average Bill\n");
        printf("10. Search by Age Range\n");
        printf("11. Female Bill\n");
        printf("12. Male Bill\n");
        printf("13. Emergency Patients\n");
        printf("14. Highest & Lowest Bill\n");
        printf("15. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displayTable(patients);
                break;

            case 2:
                totalBill(patients);
                break;

            case 3:
                searchByName(patients);
                break;

            case 4:
                searchByID(patients);
                break;

            case 5:
                totalMale(patients);
                break;

            case 6:
                totalFemale(patients);
                break;

            case 7:
                searchByDoctor(patients);
                break;

            case 8:
                searchByDisease(patients);
                break;

            case 9:
                averageBill(patients);
                break;

            case 10:
                ageRange(patients);
                break;

            case 11:
                femaleBill(patients);
                break;

            case 12:
                maleBill(patients);
                break;

            case 13:
                emergencyPatient(patients);
                break;

            case 14:
                highestLowestBill(patients);
                break;

            case 15:
                printf("\nThank You...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice!=15);
}

void displayTable(struct patient patients[])
{
    printf("\n=====================================================================================================================================\n");

    printf("%-6s %-5s %-12s %-12s %-15s %-10s %-10s %-10s %-10s %-10s\n",
           "ID","Age","Name","Doctor","Disease","Bill","Weight","Height","Gender","Blood");

    printf("=====================================================================================================================================\n");

    for(int i=0;i<10;i++)
    {
        printf("%-6d %-5d %-12s %-12s %-15s %-10.2f %-10.1f %-10.1f %-10s %-10s\n",
               patients[i].ID,
               patients[i].age,
               patients[i].name,
               patients[i].doctor,
               patients[i].disease,
               patients[i].bill,
               patients[i].weight,
               patients[i].height,
               patients[i].gender,
               patients[i].bloodGroup);
    }

    printf("=====================================================================================================================================\n");
}
void totalBill(struct patient patients[])
{
    float sum=0;

    for(int i=0;i<10;i++)
    {
        sum = sum + patients[i].bill;
    }

    printf("\nTotal Hospital Bill = %.2f\n",sum);
}
void totalMale(struct patient patients[])
{
    int count=0;

    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].gender,"Male")==0)
        {
            count++;
        }
    }

    printf("\nTotal Male Patients = %d\n",count);
}
void totalFemale(struct patient patients[])
{
    int count=0;

    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].gender,"Female")==0)
        {
            count++;
        }
    }

    printf("\nTotal Female Patients = %d\n",count);
}
void averageBill(struct patient patients[])
{
    float sum=0;
    float average;

    for(int i=0;i<10;i++)
    {
        sum = sum + patients[i].bill;
    }


    average = sum / 10;


    printf("\nAverage Bill Amount = %.2f\n",average);
}
void searchByName(struct patient patients[])
{
    char searchName[50];
    int found=0;

    printf("\nEnter Patient Name : ");
    scanf("%s",searchName);


    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].name,searchName)==0)
        {
            printf("\nPatient Found\n");

            printf("ID : %d\n",patients[i].ID);
            printf("Name : %s\n",patients[i].name);
            printf("Age : %d\n",patients[i].age);
            printf("Doctor : %s\n",patients[i].doctor);
            printf("Disease : %s\n",patients[i].disease);
            printf("Bill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nPatient Not Found\n");
    }
}
void searchByID(struct patient patients[])
{
    int id;
    int found=0;

    printf("\nEnter Patient ID : ");
    scanf("%d",&id);


    for(int i=0;i<10;i++)
    {
        if(patients[i].ID==id)
        {
            printf("\nPatient Found\n");

            printf("ID : %d\n",patients[i].ID);
            printf("Name : %s\n",patients[i].name);
            printf("Age : %d\n",patients[i].age);
            printf("Doctor : %s\n",patients[i].doctor);
            printf("Disease : %s\n",patients[i].disease);
            printf("Bill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nPatient Not Found\n");
    }
}
void searchByDoctor(struct patient patients[])
{
    char doctorName[50];
    int found=0;


    printf("\nEnter Doctor Name : ");
    scanf("%s",doctorName);


    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].doctor,doctorName)==0)
        {
            printf("\nPatient Name : %s",patients[i].name);
            printf("\nDisease : %s",patients[i].disease);
            printf("\nBill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nNo Patient Found For This Doctor\n");
    }
}
void searchByDisease(struct patient patients[])
{
    char diseaseName[50];
    int found=0;


    printf("\nEnter Disease Name : ");
    scanf("%s",diseaseName);


    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].disease,diseaseName)==0)
        {
            printf("\nPatient Name : %s",patients[i].name);
            printf("\nDoctor : %s",patients[i].doctor);
            printf("\nBill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nNo Patient Found For This Disease\n");
    }
}
void ageRange(struct patient patients[])
{
    int minAge;
    int maxAge;
    int found=0;


    printf("\nEnter Minimum Age : ");
    scanf("%d",&minAge);

    printf("Enter Maximum Age : ");
    scanf("%d",&maxAge);


    for(int i=0;i<10;i++)
    {
        if(patients[i].age>=minAge && patients[i].age<=maxAge)
        {
            printf("\nPatient Name : %s",patients[i].name);
            printf("\nAge : %d",patients[i].age);
            printf("\nDisease : %s",patients[i].disease);
            printf("\nBill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nNo Patient Found In This Age Range\n");
    }
}
void femaleBill(struct patient patients[])
{
    float sum=0;


    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].gender,"Female")==0)
        {
            sum=sum+patients[i].bill;
        }
    }


    printf("\nTotal Female Patient Bill = %.2f\n",sum);
}
void maleBill(struct patient patients[])
{
    float sum=0;


    for(int i=0;i<10;i++)
    {
        if(strcmp(patients[i].gender,"Male")==0)
        {
            sum=sum+patients[i].bill;
        }
    }


    printf("\nTotal Male Patient Bill = %.2f\n",sum);
}
void emergencyPatient(struct patient patients[])
{
    int found=0;


    printf("\nEmergency Patients\n");
    printf("--------------------------\n");


    for(int i=0;i<10;i++)
    {
        if(patients[i].bill>=50000)
        {
            printf("\nName : %s",patients[i].name);
            printf("\nDisease : %s",patients[i].disease);
            printf("\nBill : %.2f\n",patients[i].bill);

            found=1;
        }
    }


    if(found==0)
    {
        printf("\nNo Emergency Patient\n");
    }
}
void highestLowestBill(struct patient patients[])
{
    int highest=0;
    int lowest=0;


    for(int i=1;i<10;i++)
    {
        if(patients[i].bill > patients[highest].bill)
        {
            highest=i;
        }


        if(patients[i].bill < patients[lowest].bill)
        {
            lowest=i;
        }
    }


    printf("\n==============================\n");
    printf("Patient With Highest Bill\n");
    printf("==============================\n");


    printf("Name : %s\n",patients[highest].name);
    printf("Disease : %s\n",patients[highest].disease);
    printf("Bill : %.2f\n",patients[highest].bill);



    printf("\n==============================\n");
    printf("Patient With Lowest Bill\n");
    printf("==============================\n");


    printf("Name : %s\n",patients[lowest].name);
    printf("Disease : %s\n",patients[lowest].disease);
    printf("Bill : %.2f\n",patients[lowest].bill);
}