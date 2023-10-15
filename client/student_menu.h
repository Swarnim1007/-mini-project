/*
Author: 	Swarnim
Roll No.: 	MT2023029
Date: 		15/10/2023
*/

#include "../macros.h"

void viewAllCourses(char* login_id,int sock);

int studentMenu(char* login_id,int  sock){//used in client.c
	printf("------- Welcome to Student Menu --------\n");
	printf("1. View All Courses\n");
	printf("2. Enroll (pick) New Course\n");
	printf("3. Drop Course \n");
	printf("4. View Enrolled Course Details \n");
	printf("5. Change Password\n");
	printf("6. Logout & Exit\n");

	int choice;
	printf("Enter Your Choice: ");
	scanf("%d", &choice);
	write(sock, &choice, sizeof(choice));
	switch (choice)
	{
	case 1: viewAllCourses(login_id,sock);
		break;
	case 6:
		return -1;
	default:
		break;
	}
}

void viewAllCourses(char* login_id,int sock) {
	
	int n;
	struct Courses course[n];
	read(sock, &n, sizeof(n));
	read(sock, &course, sizeof(course));
	if(n >= 1) {
		for(int i = 0; i < n; i++) {
			write(STDOUT_FILENO, "******Course Details*****\n", strlen("******Course Details*****\n"));
    		write(STDOUT_FILENO, "Course Id: ", strlen("Course Id: "));
			write(STDOUT_FILENO, course[i].course_id, strlen(course[i].course_id));
			write(STDOUT_FILENO, "\nName: ", strlen("\nName: "));
			write(STDOUT_FILENO, course[i].name, strlen(course[i].name));
			write(STDOUT_FILENO, "\nDepartment: ", strlen("\nDepartment: "));
			write(STDOUT_FILENO, course[i].department, strlen(course[i].department));
			write(STDOUT_FILENO, "\nCredits: ", strlen("\nCredits: "));
			write(STDOUT_FILENO, &course[i].credits, sizeof(course[i].credits));
			write(STDOUT_FILENO, "\nNo. Of Available Seats: ", strlen("\nNo. Of Available Seats: "));
			write(STDOUT_FILENO, &course[i].no_of_available_seats, sizeof(course[i].no_of_available_seats));
			write(STDOUT_FILENO, "\nNo. Of Seats: ", strlen("\nNo. Of Seats: "));
			write(STDOUT_FILENO, &course[i].no_of_seats, sizeof(course[i].no_of_seats));
			write(STDOUT_FILENO, "\n \n", strlen("\n \n"));
		}	
	}
	else {
		write(STDOUT_FILENO, "No Course Found!", 17);
	}
}
