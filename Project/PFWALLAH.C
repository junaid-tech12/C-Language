#include<stdio.h>
#include<string.h>

#define MAX 100



// ================= STUDENT STRUCTURE =================

struct student
{
	char name[50];
	char father_name[50];
	char reg_no[100];
	char courses[100];
	char email[100];
	char Domicile[50];
	int semester;
	float gpa;
	char fee_status[50];
	int phone_No;
};




// ================= COURSE STRUCTURE =================

struct course
{
	char course_code[20];
	char course_name[50];
	int credit_hours;
};




// ================= ENROLLMENT STRUCTURE =================

struct enrollment
{
	char reg_no[100];
	char course_code[20];
};




// ================= MARKS STRUCTURE =================

struct marks
{
	char reg_no[100];
	char course_code[20];
	int marks;
};




// ================= FUNCTION DECLARATIONS =================


// Student functions

void menu(struct student students[], int *count);

void displayall(struct student students[], int count);

void addstudent(struct student students[], int *count);

void searchbyregno(struct student students[], int count);

void searchbyname(struct student students[], int count);

void updatedata(struct student students[], int count);

void deletedata(struct student students[], int *count);



// Course functions

void addcourse();

void displayallcourse();

void enrollstudent();

void displaystudentcourses();



// Result functions

void addmarks();

void calculategpa();

void displaypassfail();

void sortbymarks();

void sortbyname();

void findtopper();

void departmentreport();

void Backup();

void countstudent();



// File functions

int loadstudent(struct student students[]);

void savestudent(struct student students[], int count);





// ================= MAIN FUNCTION =================


int main()
{

	struct student students[MAX];


	int count;



	// Load data from file

	count = loadstudent(students);



	menu(students,&count);



	return 0;

}







// ================= LOAD STUDENT DATA =================


int loadstudent(struct student students[])
{

	FILE *f;

	int count=0;



	f=fopen("student.Data","rb");



	if(f==NULL)
	{
		return 0;
	}



	while(fread(&students[count],
	sizeof(struct student),1,f))
	{

		count++;


		if(count>=MAX)
		{
			break;
		}

	}



	fclose(f);



	return count;

}








// ================= SAVE STUDENT DATA =================


void savestudent(struct student students[], int count)
{

	FILE *f;



	f=fopen("student.Data","wb");



	if(f==NULL)
	{
		printf("File cannot open\n");
		return;
	}



	fwrite(students,
	sizeof(struct student),
	count,
	f);



	fclose(f);

}


// ================= MENU FUNCTION =================


void menu(struct student students[], int *count)
{

	int choice;


	while(1)
	{

		printf("\n========== STUDENT MANAGEMENT SYSTEM ==========\n");

		printf("1. Display All Students\n");
		printf("2. Add Student\n");
		printf("3. Search Student By Reg No\n");
		printf("4. Search Student By Name\n");
		printf("5. Update Student Data\n");
		printf("6. Delete Student Data\n");
		printf("7. Add Course\n");
		printf("8. Display All Courses\n");
		printf("9. Enroll Student In Course\n");
		printf("10. Display Student Courses\n");
		printf("11. Add Marks\n");
		printf("12. Calculate GPA\n");
		printf("13. Display Pass Fail\n");
		printf("14. Sort By Marks\n");
		printf("15. Sort By Name\n");
		printf("16. Find Topper\n");
		printf("17. Department Report\n");
		printf("18. Backup Record\n");
		printf("19. Count Students\n");
		printf("20. Exit\n");


		printf("Enter Your Choice: ");
		scanf("%d",&choice);



		switch(choice)
		{

			case 1:
				displayall(students,*count);
				break;


			case 2:
				addstudent(students,count);
				break;


			case 3:
				searchbyregno(students,*count);
				break;


			case 4:
				searchbyname(students,*count);
				break;


			case 5:
				updatedata(students,*count);
				break;


			case 6:
				deletedata(students,count);
				break;


			case 20:

				printf("Code Author: Mian Junaid Qasim\n");
				printf("Thank You\n");
				return;


			default:

				printf("Function will be added in next parts\n");

		}

	}

}






// ================= DISPLAY ALL STUDENTS =================


void displayall(struct student students[], int count)
{

	if(count==0)
	{
		printf("\nNo Student Record Found\n");
		return;
	}



	printf("\n====================================================================\n");
	printf("                         STUDENT RECORD\n");
	printf("====================================================================\n");



	printf("%-12s %-12s %-15s %-20s %-8s\n",
	"Name",
	"Father",
	"Reg No",
	"Course",
	"GPA");




	for(int i=0;i<count;i++)
	{

		printf("%-12s %-12s %-15s %-20s %-8.2f\n",
		
		students[i].name,
		students[i].father_name,
		students[i].reg_no,
		students[i].courses,
		students[i].gpa);

	}

}







// ================= ADD STUDENT =================


void addstudent(struct student students[], int *count)
{

	if(*count>=MAX)
	{
		printf("Database Full\n");
		return;
	}



	struct student s;



	getchar();



	printf("Enter Student Name: ");
	fgets(s.name,50,stdin);
	s.name[strcspn(s.name,"\n")]=0;



	printf("Enter Father Name: ");
	fgets(s.father_name,50,stdin);
	s.father_name[strcspn(s.father_name,"\n")]=0;



	printf("Enter Registration No: ");
	fgets(s.reg_no,100,stdin);
	s.reg_no[strcspn(s.reg_no,"\n")]=0;



	printf("Enter Courses: ");
	fgets(s.courses,100,stdin);
	s.courses[strcspn(s.courses,"\n")]=0;



	printf("Enter Email: ");
	fgets(s.email,100,stdin);
	s.email[strcspn(s.email,"\n")]=0;



	printf("Enter Domicile: ");
	fgets(s.Domicile,50,stdin);
	s.Domicile[strcspn(s.Domicile,"\n")]=0;



	printf("Enter Semester: ");
	scanf("%d",&s.semester);



	printf("Enter GPA: ");
	scanf("%f",&s.gpa);



	getchar();



	printf("Enter Fee Status: ");
	fgets(s.fee_status,50,stdin);
	s.fee_status[strcspn(s.fee_status,"\n")]=0;



	printf("Enter Phone No: ");
	scanf("%d",&s.phone_No);




	// Store student in array

	students[*count]=s;


	(*count)++;




	// Save data in file

	savestudent(students,*count);



	printf("\nStudent Added Successfully\n");

}
// ================= SEARCH STUDENT BY REGISTRATION NUMBER =================


void searchbyregno(struct student students[], int count)
{

	char reg[100];

	int found=0;



	getchar();



	printf("\nEnter Registration No: ");

	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;





	for(int i=0;i<count;i++)
	{


		if(strcmp(students[i].reg_no,reg)==0)
		{


			printf("\n========== STUDENT FOUND ==========\n");


			printf("Name: %s\n",students[i].name);

			printf("Father Name: %s\n",students[i].father_name);

			printf("Registration No: %s\n",students[i].reg_no);

			printf("Courses: %s\n",students[i].courses);

			printf("Email: %s\n",students[i].email);

			printf("Domicile: %s\n",students[i].Domicile);

			printf("Semester: %d\n",students[i].semester);

			printf("GPA: %.2f\n",students[i].gpa);

			printf("Fee Status: %s\n",students[i].fee_status);

			printf("Phone No: %d\n",students[i].phone_No);



			found=1;

			break;

		}

	}




	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}







// ================= SEARCH STUDENT BY NAME =================


void searchbyname(struct student students[], int count)
{

	char name[50];

	int found=0;



	getchar();



	printf("\nEnter Student Name: ");

	fgets(name,50,stdin);

	name[strcspn(name,"\n")]=0;





	for(int i=0;i<count;i++)
	{


		if(strcmp(students[i].name,name)==0)
		{


			printf("\n========== STUDENT FOUND ==========\n");


			printf("Name: %s\n",students[i].name);

			printf("Father Name: %s\n",students[i].father_name);

			printf("Registration No: %s\n",students[i].reg_no);

			printf("Courses: %s\n",students[i].courses);

			printf("GPA: %.2f\n",students[i].gpa);



			found=1;


		}

	}




	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}







// ================= UPDATE STUDENT DATA =================


void updatedata(struct student students[], int count)
{

	char reg[100];

	int found=0;



	getchar();



	printf("\nEnter Registration No to Update: ");

	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;





	for(int i=0;i<count;i++)
	{


		if(strcmp(students[i].reg_no,reg)==0)
		{


			printf("\nStudent Found\n");



			getchar();



			printf("Enter New Name: ");

			fgets(students[i].name,50,stdin);

			students[i].name[strcspn(students[i].name,"\n")]=0;




			printf("Enter New Father Name: ");

			fgets(students[i].father_name,50,stdin);

			students[i].father_name[strcspn(students[i].father_name,"\n")]=0;




			printf("Enter New Courses: ");

			fgets(students[i].courses,100,stdin);

			students[i].courses[strcspn(students[i].courses,"\n")]=0;




			printf("Enter New GPA: ");

			scanf("%f",&students[i].gpa);





			savestudent(students,count);



			printf("\nStudent Data Updated Successfully\n");



			found=1;

			break;

		}

	}





	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}







// ================= DELETE STUDENT DATA =================


void deletedata(struct student students[], int *count)
{

	char reg[100];

	int found=0;



	getchar();



	printf("\nEnter Registration No to Delete: ");

	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;





	for(int i=0;i<*count;i++)
	{


		if(strcmp(students[i].reg_no,reg)==0)
		{


			for(int j=i;j<*count-1;j++)
			{

				students[j]=students[j+1];

			}





			(*count)--;



			savestudent(students,*count);




			printf("\nStudent Deleted Successfully\n");



			found=1;


			break;

		}

	}





	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}
// ================= SEARCH STUDENT BY REGISTRATION NUMBER =================

void searchbyregno(struct student students[], int count)
{
	char reg[100];
	int found=0;

	getchar();

	printf("\nEnter Registration No: ");
	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;


	for(int i=0;i<count;i++)
	{
		if(strcmp(students[i].reg_no,reg)==0)
		{
			printf("\n========== STUDENT FOUND ==========\n");

			printf("Name: %s\n",students[i].name);
			printf("Father Name: %s\n",students[i].father_name);
			printf("Registration No: %s\n",students[i].reg_no);
			printf("Courses: %s\n",students[i].courses);
			printf("Email: %s\n",students[i].email);
			printf("Domicile: %s\n",students[i].Domicile);
			printf("Semester: %d\n",students[i].semester);
			printf("GPA: %.2f\n",students[i].gpa);
			printf("Fee Status: %s\n",students[i].fee_status);
			printf("Phone No: %d\n",students[i].phone_No);

			found=1;
			break;
		}
	}


	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}





// ================= SEARCH STUDENT BY NAME =================


void searchbyname(struct student students[], int count)
{
	char name[50];
	int found=0;


	getchar();


	printf("\nEnter Student Name: ");
	fgets(name,50,stdin);

	name[strcspn(name,"\n")]=0;



	for(int i=0;i<count;i++)
	{
		if(strcmp(students[i].name,name)==0)
		{
			printf("\n========== STUDENT FOUND ==========\n");

			printf("Name: %s\n",students[i].name);
			printf("Father Name: %s\n",students[i].father_name);
			printf("Registration No: %s\n",students[i].reg_no);
			printf("Courses: %s\n",students[i].courses);
			printf("GPA: %.2f\n",students[i].gpa);

			found=1;
		}
	}


	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}







// ================= UPDATE STUDENT DATA =================


void updatedata(struct student students[], int count)
{
	char reg[100];
	int found=0;


	getchar();


	printf("\nEnter Registration No to Update: ");
	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;



	for(int i=0;i<count;i++)
	{
		if(strcmp(students[i].reg_no,reg)==0)
		{
			printf("\nStudent Found\n");


			getchar();


			printf("Enter New Name: ");
			fgets(students[i].name,50,stdin);

			students[i].name[strcspn(students[i].name,"\n")]=0;



			printf("Enter New Father Name: ");
			fgets(students[i].father_name,50,stdin);

			students[i].father_name[strcspn(students[i].father_name,"\n")]=0;



			printf("Enter New GPA: ");
			scanf("%f",&students[i].gpa);



			savestudent(students,count);


			printf("\nStudent Data Updated Successfully\n");


			found=1;
			break;
		}
	}



	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}








// ================= DELETE STUDENT DATA =================


void deletedata(struct student students[], int *count)
{
	char reg[100];
	int found=0;


	getchar();


	printf("\nEnter Registration No to Delete: ");
	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;



	for(int i=0;i<*count;i++)
	{
		if(strcmp(students[i].reg_no,reg)==0)
		{

			for(int j=i;j<*count-1;j++)
			{
				students[j]=students[j+1];
			}



			(*count)--;



			savestudent(students,*count);



			printf("\nStudent Deleted Successfully\n");


			found=1;
			break;
		}
	}



	if(found==0)
	{
		printf("\nStudent Not Found\n");
	}

}


// ================= ADD COURSE =================


void addcourse()
{
	struct course c;

	FILE *f;


	getchar();


	printf("\nEnter Course Code: ");
	fgets(c.course_code,20,stdin);

	c.course_code[strcspn(c.course_code,"\n")]=0;



	printf("Enter Course Name: ");
	fgets(c.course_name,50,stdin);

	c.course_name[strcspn(c.course_name,"\n")]=0;



	printf("Enter Credit Hours: ");
	scanf("%d",&c.credit_hours);




	f=fopen("course.Data","ab");


	if(f==NULL)
	{
		printf("File Cannot Open\n");
		return;
	}



	fwrite(&c,sizeof(struct course),1,f);


	fclose(f);



	printf("\nCourse Added Successfully\n");

}







// ================= DISPLAY ALL COURSES =================


void displayallcourse()
{
	struct course c;

	FILE *f;



	f=fopen("course.Data","rb");



	if(f==NULL)
	{
		printf("\nNo Course Record Found\n");
		return;
	}




	printf("\n================================================\n");
	printf("                 COURSE LIST\n");
	printf("================================================\n");



	printf("%-15s %-25s %-10s\n",
	"Code",
	"Course Name",
	"Credit");




	while(fread(&c,sizeof(struct course),1,f))
	{

		printf("%-15s %-25s %-10d\n",
		c.course_code,
		c.course_name,
		c.credit_hours);

	}




	fclose(f);

}







// ================= ENROLL STUDENT IN COURSE =================


void enrollstudent()
{
	struct enrollment e;


	FILE *f;



	getchar();



	printf("\nEnter Student Registration No: ");

	fgets(e.reg_no,100,stdin);

	e.reg_no[strcspn(e.reg_no,"\n")]=0;




	printf("Enter Course Code: ");

	fgets(e.course_code,20,stdin);

	e.course_code[strcspn(e.course_code,"\n")]=0;





	f=fopen("enrollment.Data","ab");



	if(f==NULL)
	{
		printf("File Cannot Open\n");
		return;
	}




	fwrite(&e,sizeof(struct enrollment),1,f);



	fclose(f);



	printf("\nStudent Enrolled Successfully\n");

}







// ================= DISPLAY STUDENT COURSES =================


void displaystudentcourses()
{
	struct enrollment e;

	char reg[100];

	int found=0;


	FILE *f;



	getchar();



	printf("\nEnter Student Registration No: ");

	fgets(reg,100,stdin);

	reg[strcspn(reg,"\n")]=0;





	f=fopen("enrollment.Data","rb");



	if(f==NULL)
	{
		printf("\nNo Enrollment Found\n");
		return;
	}




	printf("\nStudent Courses:\n");



	while(fread(&e,sizeof(struct enrollment),1,f))
	{

		if(strcmp(e.reg_no,reg)==0)
		{

			printf("Course Code: %s\n",e.course_code);

			found=1;

		}

	}




	fclose(f);



	if(found==0)
	{
		printf("No Course Assigned\n");
	}

}