#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;

void c(){
	system("clear");
}
void g(){
	getchar();
}
void f(char xx){
	for(int i=0;i<80;i++)cout<<xx;
}
class details {
	public:
		char username[20][5];
		char pass[30];
		void input(){
			int i;
			cout<<"\n\n\n";
			f('x');
			cout<<"\n\tEnter the 5 subject teachers name who can access the database: "<<endl<<endl;
			i=5;
			while(i--){
				cout<<"\t";
				cout<<5-i<<") ";
				cin>>username[i];
			}
			cout<<endl;
			for(i=0;i<80;i++)cout<<"-";
			cout<<endl;
			cout<<"\n\tEnter the MASTER PASSWORD: ";
			cin>>pass;
			cout<<endl;
			for(i=0;i<80;i++)cout<<"-";
			cout<<endl;
			getchar();
		}
	};
int i;
class student {
public:
float unit1[5], unit2[5], terminal[5], tu1, tu2, tt;
float total;
char grade;
int rollno;
 void input(){
          //Inputing Unit 1
f('x');
     cout<<endl;
 	 cout<<"\tENTER ROLLNO: ";
 	 cin>>rollno;
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
f('x');
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
f('x');
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
f('x');cout<<endl;g();cout<<"\n\tPress enter to return to the menu";g();c();
}
void compute(){
          tu1=tu2=tt=total=0;
          for(i=0;i<5;i++) tu1+=unit1[i];
          for(i=0;i<5;i++) tu2+=unit2[i];
          for(i=0;i<5;i++) tt+=terminal[i];
          total=((tu1+tu2)/250*20/100)+(tt/500*80/100);
          total*=100;
          if(total>=80) grade = 'A';
          else if(total>=60) grade = 'B';
          else if(total>=40) grade = 'C';
          else if(total>=20) grade = 'D';
          else grade = 'E';
}
void output(){
	f('x');
	cout<<"\n\tROLLNO :"<<rollno<<endl;
	f('x');
cout<<"\n\t\t\t     ***** UNIT 1 MARKS *****"<<endl;
     cout<<"\n\tEnglish: ";
     	cout<<unit1[0];
     cout<<endl;
    	 cout<<"\n\tPhysics: ";
     cout<<unit1[1];
        cout<<endl;
     cout<<"\n\tChemistry: ";
     cout<<unit1[2];
        cout<<endl;
     cout<<"\n\tMaths: ";
     cout<<unit1[3];
        cout<<endl;
     cout<<"\n\tComputer: ";
     cout<<unit1[4];


cout<<endl;f('x');
cout<<"\n\t\t\t     ***** UNIT 2 MARKS *****"<<endl;
     cout<<"\n\tEnglish: ";
     	cout<<unit2[0];
     cout<<endl;
     	cout<<"\n\tPhysics: ";
     cout<<unit2[1];
        cout<<endl;
     cout<<"\n\tChemistry: ";
     cout<<unit2[2];
        cout<<endl;
     cout<<"\n\tMaths: ";
     cout<<unit2[3];
        cout<<endl;
     cout<<"\n\tComputer: ";
     cout<<unit2[4];


cout<<endl;f('x');
cout<<"\n\t\t\t     ***** TERMINAL MARKS *****"<<endl;
     cout<<"\n\tEnglish: ";
     	cout<<terminal[0];
     cout<<endl;
     	cout<<"\n\tPhysics: ";
     cout<<terminal[1];
        cout<<endl;
     cout<<"\n\tChemistry: ";
     cout<<terminal[2];
        cout<<endl;
     cout<<"\n\tMaths: ";
     cout<<terminal[3];
        cout<<endl;
     cout<<"\n\tComputer: ";
     cout<<terminal[4];


cout<<endl;f('x');
cout<<endl;


cout<<"\n\tTOTAL: "<<total;
cout<<"\n\tGRADE: "<<grade;


cout<<endl;f('x');
}
};



void add(){
	cout<<endl;
	f('x');
	cout<<"\n\tEnter the number of student report cards to be added: ";
	int n;
	cin>>n;
	fstream reps("reports.dat", ios::app | ios::binary);
	student s;
	while(n--){
		s.input();
		reps.write((char *)&s, sizeof(s));
		cout<<"\n\tReport written successfull.\n";
		
	}g();cout<<"\tPress enter to return to the menu.";g();c();
}

void modify(){
	f('x');cout<<endl;
	cout<<"\n\tEnter the rollno whom you want to modfiy:";
	int roll;
	cin>>roll;
	fstream f("reports.dat", ios::in | ios::out | ios::binary);
	int pos = 0; 
	int succ=0;
	student s;
	while(f.read((char *)&s, sizeof(s))){
		if(s.rollno==roll){
			f.seekg(pos);
			s.input();
			f.write((char *)&s, sizeof(s));
			succ=1;
		}
		pos=f.tellg();
	}
	if(!succ){
		cout<<"\n\tRoll number not found.\n";
		g();
		cout<<"\n\tPress enter to return to the menu.\n";
		for(int i=0;i<80;i++)cout<<"x";

		g();
		c();
	}
}





void numpassfail(){
	f('x');cout<<"\n\t\t\t\t PASS/FAIL";
	ifstream f("reports.dat", ios::binary);
	int fail,pass;
	fail=pass=0;
	student s;
	while(f.read((char *)&s, sizeof(s))){
		if(s.total>=40)
			pass++;
		else 
			fail++;
	}
	cout<<"\n\tNumber of students who passed: "<<pass;
	cout<<"\n\tNumber of students who failed: "<<fail;
	cout<<"\n \n\tPress enter to return to the menu.\n";
	for(int i=0;i<80;i++)cout<<"x";
	g();
	c();
}






void display(){
	fstream reps("reports.dat", ios::in | ios::binary);
	student s;
	f('x');
	cout<<"\n\t1)Display All\n\t2)Display for specific rollno\n\n\tEnter your option: ";
	int op;
	cin>>op;
	f('x');cout<<endl;
	if(op==1){
	while(reps.read((char *)&s, sizeof(s))){
		s.output();
		cout<<endl;
		g();
	}
	}
	else if(op==2){
		cout<<"\n\tEnter the rollno: ";
		int roll;
		cin>>roll;
		while(reps.read((char *)&s, sizeof(s))){
			if(s.rollno==roll){
			s.output();
			cout<<endl;

		}
		}
	}
	else
		cout<<"\n\tEnter a valid option"<<endl;
	cout<<"\n\tPress enter to return to the menu\n";
	for(int i=0;i<80;i++)cout<<"x";
	g();
	c();
}	










int signin(details d){
cout<<endl;
system("clear");
f('x');
cout<<"\n\t\t\t\t      LOGIN:"<<endl;
f('x');
		char us[30], pass[30];
		int logsucc = 0;
		cout<<"\n\n\tEnter your username: ";
		cin>>us;
		int usermatch=0, match=0;
		for(int i=0;i<5;i++){
			if(strcmp(d.username[i], us)==0){
				usermatch=1;
				break;
			}
		}
		if(!usermatch){
			cout<<"\n\tYou are not authorized to use this database!"<<endl<<endl;
			f('x');
			getchar();
			getchar();
			system("clear");
			return signin(d);
		}
		else {
			cout<<"\n\tEnter master pass: ";
			cin>>pass;
			if(strcmp(d.pass, pass)==0){
				match=1;
				return 1;
			}
			if(!match){
				cout<<"\n\tWrong password. You are not authorized to use this database."<<endl<<endl;
				f('x');
					g();c();
					system("clear");
				return signin(d);
			}

		}
}









int main(){
	g();c();
	fstream login;
	details d;
	login.open("details.dat", ios::in | ios::binary);
	if(!login){
		login.close();
		login.open("details.dat", ios::out | ios::binary);
		cout<<"\t \t   Welcome to the student report card program.\n\t\t  You need to configure this for the first time."<<endl;
		d.input();
		login.write((char *)&d, sizeof(d));
		cout<<"\n\n\t\tThank you. Details have been succesfullly saved."<<endl;
	    f('x');
	    cout<<endl;
		getchar();
		system("clear");
		system("clear");
	}
	else {
		login.close();
		login.open("details.dat", ios::in | ios::binary);
		login.read((char*)&d, sizeof(d));
		system("clear");
	}
	if(signin(d)){
		system("clear");
		int opt;
		do{	
		f('x');cout<<endl;
		cout<<"\n\t\t\t\t\tMENU"<<endl<<endl;
		f('x');cout<<endl<<endl;
		cout<<"\n\t1)Add report card\n";
		cout<<"\n\t2)Display report card\n";
		cout<<"\n\t3)Modify report\n";
		cout<<"\n\t4)Number of Pass/Fail\n";
		cout<<"\n\t5)Exit\n";
		cout<<"\n\n\n\n";
		cout<<"\tENTER YOUR OPTION: ";
		cin>>opt;
		g();
		c();
		switch(opt){
			case 1:
				 add();
				break;
			case 2:
				 display();
				break;
			
			case 3:
				modify();
				break;
			case 4:
				numpassfail();
				break;
			case 5:
				system("exit");
				break;
			default:
				cout<<"\n\tInvalid Input"; g(); c();
		}
		}
		while(opt!=5);
	}	
}