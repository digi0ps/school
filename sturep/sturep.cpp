#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;

void gc(){
	getchar();
	system("clear");
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
					gc();
					system("clear");
				return signin(d);
			}

		}
}
int main(){
	gc();
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
		for(int i=0;i<80;i++)cout<<"x";cout<<endl;
		cout<<"\n \t \t \t \tMENU"<<endl;
		for(int i=0;i<80;i++)cout<<"x";cout<<endl;
	}	
}