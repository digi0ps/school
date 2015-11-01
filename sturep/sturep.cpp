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
class details {
	public:
		char username[20][5];
		char pass[30];
		void input(){
			int i;
			cout<<"\n\n\n";
			for(i=0;i<80;i++)cout<<"x";
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
int signin(details d){
cout<<endl;
system("clear");
for(int i=0;i<80;i++)cout<<"x";
cout<<"\n\t\t\t\t      LOGIN:"<<endl;
for(int i=0;i<80;i++)cout<<"x";
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
			for(int i=0;i<80;i++)cout<<"x";
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
				for(int i=0;i<80;i++)cout<<"x";
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
	    for(int i=0;i<80;i++)cout<<"x";
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
		for(int i=0;i<80;i++)cout<<"x";cout<<endl;
		cout<<"\n\t\t\t\t\tMENU"<<endl<<endl;
		for(int i=0;i<80;i++)cout<<"x";cout<<endl<<endl;
		cout<<"\n\t1)Add report card\n";
		cout<<"\n\t2)Display grades\n";
		cout<<"\n\t3)Modify/Delete report\n";
		cout<<"\n\t4)Number of Pass/Fail\n";
		cout<<"\n\t5)Display report card\n";
		cout<<"\n\t6)Exit\n";
		cout<<"\n\n\n\n";
		cout<<"\tENTER YOUR OPTION: ";
		cin>>opt;
		switch(opt){
			case 1:
				// add();
				break;
			case 2:
				// displaygrades();
				break;
			case 3:
				// modifydelete();
				break;
			case 4:
				// numpassfail();
				break;
			case 5:
				// display();
				break;
			case 6:
				system("exit");
				break;
			default:
				cout<<"\n\tInvalid Input"; g();
		}
		}
		while(opt!=6);
	}	
}