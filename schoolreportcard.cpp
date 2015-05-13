#include <iostream>
#include <stdio.h>
using namespace std;
short int i;
class student {
float unit1[5], unit2[5], terminal[5], tu1, tu2, tt, tp;
public:
     void input(){
          //Inputing Unit 1
for(i=0;i<80;i++)cout<<"x";
     cout<<endl;
     cout<<"\t\t\t  *****ENTER UNIT 1 MARKS*****"<<endl;
     cout<<"\tEnglish: ";
     do{cin>>unit1[0];}
     while(unit1[0]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
     cout<<endl;
     cout<<"\tPhysics: ";
     do{cin>>unit1[1];}
     while(unit1[1]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tChemistry: ";
     do{cin>>unit1[2];}
     while(unit1[2]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tMaths: ";
     do{cin>>unit1[3];}
     while(unit1[3]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tComputer: ";
     do{cin>>unit1[4];}
     while(unit1[4]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     //Inputing Unit 2
for(i=0;i<80;i++)cout<<"x";
     cout<<endl;
     cout<<"\t\t\t  *****ENTER UNIT 2 MARKS*****"<<endl;
     cout<<"\tEnglish: ";
     do{cin>>unit2[0];}
     while(unit2[0]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tPhysics: ";
     do{cin>>unit2[1];}
     while(unit2[1]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tChemistry: ";
     do{cin>>unit2[2];}
     while(unit2[2]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tMaths: ";
     do{cin>>unit2[3];}
     while(unit2[3]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     cout<<"\tComputer: ";
     do{cin>>unit2[4];}
     while(unit2[4]>25 && cout<<"\tMarks must be less than 25.\n\tRe-enter: ");
        cout<<endl;
     //INputing Terminal
for(i=0;i<80;i++)cout<<"x";
     cout<<endl;
     cout<<"\t\t\t  *****ENTER TERMINAL MARKS*****"<<endl;
     cout<<"\tEnglish: ";
     do{cin>>terminal[0];}
     while(terminal[0]>100 && cout<<"\tMarks must be less than 100.\n\tRe-enter: ");
     cout<<endl;
     cout<<"\tPhysics: ";
     do{cin>>terminal[1];}
     while(terminal[1]>100 && cout<<"\tMarks must be less than 100.\n\tRe-enter: ");
     cout<<endl;
     cout<<"\tChemistry: ";
     do{cin>>terminal[2];}
     while(terminal[2]>100 && cout<<"\tMarks must be less than 100.\n\tRe-enter: ");
     cout<<endl;
     cout<<"\tMaths: ";
     do{cin>>terminal[3];}
     while(terminal[3]>100 && cout<<"\tMarks must be less than 100.\n\tRe-enter: ");
     cout<<endl;
     cout<<"\tComputer: ";
     do{cin>>terminal[4];}
     while(terminal[4]>100 && cout<<"\tMarks must be less than 100.\n\tRe-enter: ");
     cout<<endl;
     //iNPUT OVER :)
     compute();
for(i=0;i<80;i++)cout<<"x";
}
     void compute(){
          tu1=tu2=tt=tp=0;
          for(i=0;i<5;i++) tu1+=unit1[i];
          for(i=0;i<5;i++) tu2+=unit2[i];
          for(i=0;i<5;i++) tt+=terminal[i];
          tp=((tu1+tu2)/250*20/100)+(tt/500*80/100);
          tp*=100;
          cout<<"Consolidated Report = "<<tp<<endl;
     }
};
int main()
{
     int nos;
     for(i=0;i<40;i++) cout<<"- ";
     cout<<"\t\t    WELCOME TO STUDENT REPORT CARD PROGRAM"<<endl;
     for(i=0;i<40;i++) cout<<"- ";
     cout<<endl<<endl;
     cout<<" ---> ENTER THE NUMBER OF STUDENTS: ";
     cin>>nos;
     student s[nos];
     for(i=0;i<nos;i++) {
          cout<<"\nSTUDENT "<<i+1<<" DETAILS:"<<endl;
          s[i].input();
     }
     return 0;
}
