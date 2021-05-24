#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<windows.h>
#include <conio.h>
#include <dir.h>
#include <process.h>
#include <dirent.h>
#include<time.h>
#define WINDOWS  
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#define TRUE    1
#define FALSE   0
using namespace std;

int mkdir();
int ls();  
int date();
int pwd();
int cat();
int time();
int cal();
int rmdir();
int cp();
int word();

int word()
{
    FILE * file;
    char path[100];
    char ch;
    int characters, words, lines;
    printf("Enter source file path: ");
    scanf("%s", path);
    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        if (ch == '\n' || ch == '\0')
            lines++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    if (characters > 0)
    {
        words++;
        lines++;
    }
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);
    fclose(file);
    return 0;
}
int cp()
{
FILE *fptr1, *fptr2;
char filename[100], c;

printf("Enter the filename to open for reading \n");
scanf("%s", filename);

fptr1 = fopen(filename, "r");
if (fptr1 == NULL)
{
printf("Cannot open file %s \n", filename);
}

printf("Enter the filename to open for writing \n");
scanf("%s", filename);

fptr2 = fopen(filename, "w");
if (fptr2 == NULL)
{
printf("Cannot open file %s \n", filename);

}

c = fgetc(fptr1);
while (c != EOF)
{
fputc(c, fptr2);
c = fgetc(fptr1);
}

printf("\nContents copied to %s", filename);

fclose(fptr1);
fclose(fptr2);
return 0;
}






int rmdir()
{


    int check;
    char* dirname = "santa";
 
 
    check = rmdir(dirname);
 

    if (!check)
        {
printf("Directory deleted\n");

}
    else {
        printf("Unable to delete directory\n");
       
    }
 
   
}



int cal(){


int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
" ",
"\n\n\nJanuary",
"\n\n\nFebruary",
"\n\n\nMarch",
"\n\n\nApril",
"\n\n\nMay",
"\n\n\nJune",
"\n\n\nJuly",
"\n\n\nAugust",
"\n\n\nSeptember",
"\n\n\nOctober",
"\n\n\nNovember",
"\n\n\nDecember"
};

int hours, minutes, seconds, day, month, year;

time_t now;
time(&now);

printf("Today is : %s", ctime(&now));

struct tm *local = localtime(&now);

hours = local->tm_hour;
minutes = local->tm_min;
seconds = local->tm_sec;

day = local->tm_mday;
month = local->tm_mon + 1;
year = local->tm_year + 1900;
int daycode;
int d1, d2, d3;

d1 = (year - 1.)/ 4.0;
d2 = (year - 1.)/ 100.;
d3 = (year - 1.)/ 400.;
daycode = (year + d1 - d2 + d3) %7;


if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
{
days_in_month[2] = 29;
}
else
{
days_in_month[2] = 28;
}
int month1=month;
for ( month = 1; month <= 12; month++ )
{
if(month1==month){
printf("%s", months[month]);
printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );


for ( day = 1; day <= 1 + daycode * 5; day++ )
{
printf(" ");
}




for ( day = 1; day <= days_in_month[month]; day++ )
{
printf("%2d", day );

if ( ( day + daycode ) % 7 > 0 )
printf("   " );
else
printf("\n " );
}}
daycode = ( daycode + days_in_month[month] ) % 7;
}


}

int time(int func)
{
clock_t time_req;
 time_req = clock();
    if(func==1)
  mkdir();
  else if(func==2)
  ls();
  else if(func==3)
  date();
  else if(func==4)
  pwd();
  else if(func==5)
  cat();
 
    time_req = clock() - time_req;
    cout<<"Processor time taken was "<<(float)time_req/CLOCKS_PER_SEC<<" seconds\n";

}

int cat(){

  int num;
  FILE *fptr;
  fptr = fopen("prog2.txt","w");
 
  if(fptr == NULL)
    {
      printf("Error!");
      return 1;
    }
 
  printf("Enter a number to save it in a file: ");
  scanf("%d",&num);
 
  fprintf(fptr,"%d",num);
  fclose(fptr);
 
  return 0;

}

int pwd()
{
char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  printf("Current working dir: %s\n", buff);
  return 1;

}
int date()
{


int hours, minutes, seconds, day, month, year;
time_t now;

time(&now);

printf("Today is : %s", ctime(&now));

struct tm *local = localtime(&now);

hours = local->tm_hour;
minutes = local->tm_min;
seconds = local->tm_sec;
day = local->tm_mday;
month = local->tm_mon + 1;
year = local->tm_year + 1900;
if (hours < 12)
printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);
else
printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);

printf("Date is : %02d/%02d/%d\n", day, month, year);


    return 0;
}
int mkdir()
{
    int check;
    char* dirname = "santa";
 
 
    check = mkdir(dirname);
 
    if (!check)
        {
printf("Directory created\n");
}

    else {
        printf("Unable to create directory\n");
    }
 
}
int ls()
{
     struct dirent *de;  
   
    DIR *dr = opendir(".");
 
    if (dr == NULL)  
    {
        printf("Could not open current directory" );
        return 0;
    }
 
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);
 
    closedir(dr);  
    return 0;
}
int main(void)
{
printf("\t\t\t WElCOME TO OUR LINUX SHELL \n");
printf("\t\t\tSELECT OPTION NUMBER TO ALLOW US TO SERVICE YOUR NEED:\n");
while(1){

printf("\n OPTIONS:\n");
printf(" 1>mkdir - creating a new sub-directory in current directory \n 2> ls- list of folders and files of current directory \n 3>date - displays date and time of current working pc \n 4>pwd-complete path of current working directory \n 5)cat - creating a new text file in current directory adds content in it. \n 6>time abc - gives the execution time of command abc \n 7>cal-shows the calendar of the month of system \n 8> rmdir-removing the directory from the current direcrory \n 9>cp- copying contents from one file to another \n 10>word- to count the no of lines words and characters\n 11> exit \n");
int option;
scanf("\n%d",&option);
switch(option)
{
case 1:
mkdir();
break;
case 2:
ls();
break;
case 3:
date();
break;
case 4:
pwd();
break;
case 5:
cat();
break;
case 6:
printf("enter the number of command whose time is to be checked");
int func;
scanf("%d",&func);
time(func);
break;
case 7:
cal();
break;
case 8:
rmdir();
break;
case 9:
cp();
break;
case 10:
word();
break;
case 11:
exit(0);
break;
default:
printf("enter valid number");
   break;
}
}
}
