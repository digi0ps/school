#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
long uc;
void f(char xx){
	cout<<endl;
	for(int i=0;i<80;i++) cout<<xx;
	cout<<endl;
}
void g(){
	getchar();
}
void cls(){
	system("clear");
}
class Interface {
public:
	Interface(){
		system("clear");
	}
	void Welcome(char* cname){
		system("clear");
		f('x');
		cout<<"\n\t\t\tWelcome to the "<<cname<<" reservation system"<<endl;
		f('x'); cout<<endl; cout<<endl;
	}
	int LoginMenu(){
		f('-');
		cout<<"\nPress the option you wish to enter: "<<endl;
		cout<<"1)Sign In"<<endl;
		cout<<"2)Sign Up"<<endl;
		f('-');
		cout<<endl;
		int op1;
		cin>>op1;
		return op1;
	}
	int AdminMenu(){
        system("clear");
        f('x');
        cout<<"Welcome admin.\n\n";
        f('x');
        cout<<endl;
        f('-');
        cout<<"1) Add new flight schedule"<<endl;
        cout<<"2) Delete a flight schedule"<<endl;
        cout<<"3) View bookings log"<<endl;
        cout<<"4) Delete an user"<<endl;
        cout<<"5) Change admin password"<<endl;
		f('-');
		cout<<"\nENTER AN OPTION: ";
        int op2;
        cin>>op2;
        return op2;
	}
	int UserMenu(char* user){
		f('x');
        cout<<"Welcome "<<user<<".\n";
        f('x');
        f('-');
        cout<<"1) Book a flight"<<endl;
        cout<<"2) View status"<<endl;
        cout<<"3) View Transaction Log"<<endl;
        cout<<"4) Cancel your flight"<<endl;
        cout<<"5) Logout"<<endl;
		f('-');
		cout<<endl<<"ENTER AN OPTION: ";
        int op3;
        cin>>op3;
        return op3;
	}
}ui; //object for doing major UI related operations


struct Date {
    int d, m, y;
    int day;
}td;
// declaring time struct and setting the dates
time_t now = time(0);
tm *t = localtime(&now);
char days[][30]={"SUNDAY", "MONDAY", "TUESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};


class company {
	char name[30];
	int totalflights;
	char location[30];
	char admin_password[30];
public:
	void PostCompanyDetails(){
		cout<<"Enter the name of your airline company"<<endl;
		gets(name);
		cout<<"Enter the location of your airline company"<<endl;
		gets(location);
		cout<<"Enter the total number of flights available"<<endl;
		cin>>totalflights;
		cout<<endl<<"Enter admin password"<<endl;
		cin>>admin_password;
	}
	char* CompanyName(){
		return name;
	}
	char* adpw(){
		return admin_password;
	}

};
class user {
public:
	char username[30];
	char password[30];
	long id;
	int logincheck(char us[], char pw[]){
		if(strcmp(us, username)==0){
			if(strcmp(pw, password)==0)
				return 1;
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
}admin;

class flight {

private:
	int full;
public:
	flight(){
		full=0;
	}
	char fname[30];
	long fnum;
	int dey;
	int tseats; //total number of seats
};
void addflight(){
	fstream f("flights.dat", ios::app | ios::binary);
	flight fly;
	cout<<"Flight name: ";
	cin>>fly.fname;
	cout<<"Flight number: ";
	cin>>fly.fnum;
	cout<<"Total number of seats: ";
	cin>>fly.tseats;
	cout<<"Number of operational days: ";
	int opdays; cin>>opdays;
	cout<<"1)SUNDAY\n2)MONDAY\n3)TUESDAY\n4)WEDNESDAY\n5)THURSDAY\n6)FRIDAY\n7)SATURDAY"<<endl;
	cout<<"Enter the operational days with spaces. Eg 1 3 5"<<endl;
	int n;
	for(int i=1;i<=opdays;i++){
		cin>>n;
		fly.dey=n-1;
		f.write((char*)&fly, sizeof(fly));
	}
	cout<<"Flight Schedule successfully stored."<<endl;
	f.close();
	return;
}
void Decision2(){
	int op2;
	op2 = ui.AdminMenu();
	switch(op2){
		case 1:
			addflight();
			break;
		case 2:
			//umm delete flight. idk if am gonna implement this. lets see. time will say.
			break;
		case 3:
			//bookings log. great.
			//maybe in the company class
			//create a main_log.txt
			//copy all log entries there.
			//need to do user log entry first.
			//so skipping this for now
			break;
		case 4:
			//delete an user. i dont think this would be useful in this scenario.
			break;
		case 5:
			//change admin password. simple shit. to the last.
			break;
		default:
			cout<<"Please enter a valid input";
			Decision2();
			return;
	}
}
void signin(){
	system("clear");
	cout<<"LOGIN:"<<endl<<endl;
	char us[30], pass[30];
	int logsucc = 0;
	ifstream u("users.dat",ios::binary);
	user chkuser;
	cout<<"Enter your username: ";
	cin>>us;
	cout<<"Enter your password: ";
	cin>>pass;
	if(strcmp(us, "admin")==0){
        if(strcmp(pass, admin.password)==0){
            cout<<"Admin login successfull.";
            getchar();
            getchar();
            system("clear");
            ui.AdminMenu();
            Decision2();
            return;
        }
        else{
            cout<<"Admin password wrong"<<endl;
            getchar();
            signin();
            return;
        }
	}
    else{
        while(u.read((char *)&chkuser, sizeof(chkuser))){
            if(chkuser.logincheck(us,pass)){
                logsucc = 1;
                break;
                }
        }
        if(logsucc){
            cout<<"Login successfull";
            u.close();
            getchar();
            getchar();
            system("clear");
            ui.UserMenu(chkuser.username);
            return;
        }
        else{
            cout<<"Incorrect Username or Password"<<endl;
            getchar();
            getchar();
            signin();
            return;
        }
    }
}


void signup(){
	system("clear");
	cout<<"REGISTER"<<endl<<endl;
	fstream uct("uct.txt", ios::in);
	uct>>uc;
	uct.close();
	fstream u;
	user newuser, chkuser;
	cout<<"Enter a username: ";
	cin>>newuser.username;
	int f=1;
	u.open("users.dat", ios::in | ios::binary);
    while(u.read((char *)&chkuser, sizeof(chkuser))){
	if(strcmp(newuser.username, chkuser.username)==0)
        f=0;
	}
	u.close();
	if(!f){
        cout<<"Sorry username already exists. Try again with a different username."<<endl;
        getchar();
        getchar();
        signup();
	}
	else{
        u.open("users.dat", ios::app | ios::binary);
        uct.open("uct.txt", ios::out);
        cout<<"Enter a password: ";
        cin>>newuser.password;
        uc=uc+1;
        uct<<uc;
        newuser.id=uc;
        u.write((char*)&newuser, sizeof(newuser));
        u.close();
        uct.close();
        cout<<"Account successfully created"<<endl;
        getchar();
        signin();
    }
	return;
}



void Decision1(){
	int op1; // option variable
	op1 = ui.LoginMenu();
	if(op1==1){
		signin();
		return;
	}
	else if(op1==2){
		signup();
		return;
	}
	else{
		system("clear");
		cout<<"Please enter a valid option"<<endl;
		getchar();
		Decision1();
		return;
	}
}


int main(){
	fstream com; // file manager for the company_info.dat
	fstream uct; //file containing the total number of users
	company c, g;   // object for company_info.dat
    td.d = t->tm_mday;
    td.m = t->tm_mon+1;
    td.y = t->tm_year + 1900;
    td.day = t->tm_wday;
	char cname[30];
	com.open("company_info.dat", ios::in | ios::binary);
	uct.open("uct.txt", ios::in);
	if(!com){
        com.close();
        com.open("company_info.dat", ios::out | ios::binary);

        f('+');
        cout<<endl;
		cout<<"Welcome to the airline project.\nYou have to configure this first in order for it to work.\n";
		f('+');
		cout<<endl;
		getchar();
		cls();
		f('-');
		cout<<endl;
		cout<<"Enter the following details: "<<endl<<endl;
		c.PostCompanyDetails();
		com.write((char*)&c, sizeof(c));
		cout<<"Configuration Done.\nSoftware is ready to roll"<<endl;
		f('-');
		cout<<endl;
		com.close();
		cout<<"Press enter to continue"<<endl;
		strcpy(admin.username, "admin");
		strcpy(admin.password, c.adpw());
		strcpy(cname, c.CompanyName());
		if(!uct){
			uct.close();
			uct.open("uct.txt", ios::out);
			uc=0;
			uct<<uc;
			uct.close();
		}
		getchar();
	}
	else {
		ifstream comp("company_info.dat", ios::binary);
		comp.read((char*)&g, sizeof(g));
		strcpy(cname, g.CompanyName());
		strcpy(admin.password, g.adpw());
	}
	ui.Welcome(cname);
	Decision1();
	return 0;
}
