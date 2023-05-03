//Write a Program to Implement the Structure and Pointer concept in C. Demonstrate with
//examples



#include <stdio.h>
#include <stdlib.h>
struct student{
   char name[30];
   int roll_number;
   float marks;
};

int main()
{
   struct student *ptr;
   int i, n;

   printf("Enter the number of students: ");
   scanf("%d", &n);

   ptr = (struct student*) malloc(n * sizeof(struct student));

   for(i=0;i<n;i++)
   {
       printf("Enter name, roll number and marks respectively: ");
    
       scanf("%s %d %f", (ptr+i)->name, &(ptr+i)->roll_number, &(ptr+i)->marks);
   }

   printf("Displaying Information:\n");
   for(i = 0; i < n; ++i){

       printf("Name: %s  Roll number: %d   Marks: %f \n", (ptr+i)->name, (ptr+i)->roll_number, (ptr+i)->marks);
   }

return 0;
}
