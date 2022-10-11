#include<stdio.h>
#include<string.h>
struct student
{
   char name[35];
   int roll_no;
   float marks;
   char grade;
   float percent;
};

int main()
{
    struct student ram, shreya, priya, shreeja, arsh;
    printf("%ld\n", sizeof(arsh));
    arsh.roll_no = 1;
    arsh.marks = 599;
    arsh.percent = arsh.marks/7 ;
    strcpy(arsh.name, "Arsh Mehra");
    printf("%s \n Roll no.= %d \n Marks = %f \n Percentage = %f",arsh.name , arsh.roll_no, arsh.marks, arsh.percent);
}

