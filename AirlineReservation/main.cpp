#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
void Decision1();
long uc;
char cname[30];
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
		cout<<"3)Exit"<<endl;
		f('-');
		cout<<endl;
		int op1;
		cin>>op1;
		return op1;
	}
	int AdminMenu(){
        system("clear");
        f('x');
        cout<<"\n\t\t\tWELCOME ADMIN\n";
        f('x');
        cout<<endl;
        f('-');
        cout<<"1) Add new flight schedule"<<endl;
        cout<<"2) Modify a flight schedule"<<endl;
        cout<<"3) View bookings log"<<endl;
        cout<<"4) Display all flights"<<endl;
        cout<<"5) Change admin password"<<endl;
		cout<<"6) Logout";
		f('-');
		cout<<"\nENTER AN OPTION: ";
        int op2;
        cin>>op2;
        return op2;
	}
	int UserMenu(char* user){
		f('x');
        cout<<"\n\t\t\tWelcome "<<user<<".\n";
        f('x');
        f('-');
        cout<<"1) Book a flight"<<endl;
        cout<<"2) View Booked Log"<<endl;
        cout<<"3) Cancel your flight"<<endl;
        cout<<"4) Logout"<<endl;
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
char days[][30]={"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};


class company {
	char name[30];
	int totalflights;
	char location[30];
	char admin_password[30];
public:
	void PostCompanyDetails(){
		f('*');
		cout<<endl;
		cout<<"Enter the name of your airline company: ";
		gets(name);
		cout<<"Enter the location of your airline company: ";
		gets(location);
		cout<<"Enter the total number of flights available: ";
		cin>>totalflights;
		cout<<"Enter admin password: ";
		cin>>admin_password;
		f('*');
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
	void dislplaylog(){
		ifstream ulog(username);
		system("clear");
		cout<<"FlightNum : FlightName : From : To : Day : SeatsBooked "<<endl;
		char buff[100];
		while(!ulog.eof()){
			ulog>>buff;
			cout<<buff<<" ";
	}
	g();
	getchar();
	system("clear");
	return;
		}
}admin;

class flight {
public:
	char fname[30];
	long fnum;
	int dey;
	int tseats; //total number of seats
	char from[30], to[30];
	int filled; //number of filled seats
	void output(){
	cout<<endl<<fnum<<" : "<<fname<<" : "<<from<<" : "<<to<<" : "<<days[dey]<<" : "<<tseats<<" : "<<filled<<";";
	}
	void useroutput(){
		cout<<fnum<<" : "<<fname<<" : "<<from<<" : "<<to<<" : "<<days[dey]<<" : "<<filled<<"/"<<tseats<<" ; ";
	}
	void bookie(user a){
		char filename[30];
		fstream userfile(a.username, ios::app); //opening the log of the user in append mode
		fstream adminfile("adminlog.txt", ios::app); //opening the admin log in appendmode
		cout<<"Enter number of seats to book: ";
		int nos;
		do{
			cin>>nos;
		}while((nos<0 && cout<<"Number of seats must be greater than 0"<<endl) || (nos>(tseats-filled) && cout<<"Sorry only "<<tseats-filled<<" seats are available."<<endl) && cout<<"Enter number of seats again:");
		filled=filled+nos;
		userfile<<fnum<<" : "<<fname<<" : "<<from<<" : "<<to<<" : "<<days[dey]<<" : "<<nos<<" ; "<<endl;
		adminfile<<a.username<<" : "<<fnum<<" : "<<fname<<" : "<<from<<" : "<<to<<" : "<<days[dey]<<" : "<<nos<<";\n"<<endl;
		cout<<"Booking...";
		getchar();
		system("clear");
	}
};
void addflight(){
	fstream f("flights.dat", ios::app | ios::binary);
	flight fly;
	cout<<"Flight name: ";
	cin>>fly.fname;
	cout<<"Flight number: ";
	cin>>fly.fnum;
	cout<<"From: ";
	cin>>fly.from;
	cout<<"To: ";
	cin>>fly.to;
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
		fly.filled=0;
		f.write((char*)&fly, sizeof(fly));
	}
	cout<<"Flight Schedule successfully stored."<<endl;
	f.close();
	return;
}

void modifyflight(){
	f('x');cout<<endl;
	cout<<"\n\tEnter the flight number: ";
	int num;
	cin>>num;
	fstream f("flights.dat", ios::in | ios::out | ios::binary);
	int pos = 0; 
	int succ=0;
	flight s;
	while(f.read((char *)&s, sizeof(s))){
		if(s.fnum==num){
			f.seekg(pos);
			//input the detaisl
			cout<<"Flight name: ";
			cin>>s.fname;
			cout<<"Flight number: ";
			cin>>s.fnum;
			cout<<"From: ";
			cin>>s.from;
			cout<<"To: ";
			cin>>s.to;
			cout<<"Total number of seats: ";
			cin>>s.tseats;
			cout<<"Number of operational days: ";
			int opdays; cin>>opdays;
			cout<<"1)SUNDAY\n2)MONDAY\n3)TUESDAY\n4)WEDNESDAY\n5)THURSDAY\n6)FRIDAY\n7)SATURDAY"<<endl;
			cout<<"Enter the operational days with spaces. Eg 1 3 5"<<endl;
			int n;
			for(int i=1;i<=opdays;i++){
				cin>>n;
				s.dey=n-1;
				f.write((char*)&s, sizeof(s));
			}
			cout<<"Flight Schedule successfully stored."<<endl;
			f.close();
			succ=1;
		}
		pos=f.tellg();
		g();
	}
	if(!succ){
		cout<<"\n\tFlight not found.\n";
		g();
		cout<<"\n\tPress enter to return to the menu.\n";
		for(int i=0;i<80;i++)cout<<"x";

		g();
	}
	f.close();
}
void displayflights(){
	fstream fx("flights.dat", ios::in | ios::binary);
	flight s;
	f('x');
	cout<<"FlightNumber : FlightName : From : To : Days : TotalSeats;";
	f('x');
	while(fx.read((char *)&s, sizeof(s))){
	f('-');
	s.output();
	f('-');
	cout<<endl;
	}
	fx.close();
	getchar();
	getchar();

}
void Decision2(){
	int op2;
	op2 = ui.AdminMenu();
	switch(op2){
		case 1:
			addflight();
			Decision2();
			break;
		case 2:
			modifyflight();
			Decision2();
			break;
		case 3:
			//adminlogtxt();
			Decision2();
			break;
		case 4:
			displayflights();
			Decision2();
			break;
		case 5:
			//change admin password. simple shit. to the last.
			break;
		case 6:
			system("clear");
			Decision1();
			break;
		default:
			cout<<"Please enter a valid input";
			Decision2();
			return;
	}
	return;
}
void book(user a){
	f('*');
	cout<<"\n\t\t\tBOOKING\n";
	f('*');
	f('-');
	cout<<endl<<"Enter your location: ";
	char location[30];
	cin>>location;
	cout<<"1) Show all flights"<<endl;
	cout<<"2) Search flights by destination"<<endl;
	cout<<"3) Change your location"<<endl;
	int opt41;
	cin>>opt41;
	fstream fgt("flights.dat", ios::in | ios::binary);
	flight f;
	if(opt41==1){
		system("clear");
		int i=1; int flag=0;
		cout<<"\nFlightNumber : FlightName : From : To : Day : AvailableSeats;"<<endl;
		while(fgt.read((char *)&f, sizeof(f))){
			if(strcmp(f.from, location)==0){
				flag=1;
				cout<<endl;
				cout<<i<<")	 ";
				f.useroutput();
				cout<<endl; i++;
			}
		}
		if(!flag){
			cout<<"Sorry no flight";
			getchar();
			system("clear");
		}
		else{
			cout<<"Select your flight: ";
			int whichflight;
			cin>>whichflight;
			fgt.seekg((whichflight-1)*sizeof(f)); //am moving the file read pointer to the selected flight
			fgt.read((char *)&f, sizeof(f));
			f.bookie(a); //this function handles care of the booking and modifies the flight object
			//need to write the file again
			fgt.close();
			fgt.open("flights.dat", ios::out | ios::binary);
			fgt.seekg((whichflight-1)*sizeof(f)); //am moving the file write pointer to the selected flight
			fgt.write((char *)&f, sizeof(f));
			cout<<endl<<"Flight successfully booked."<<endl;
			fgt.close();
			getchar();
			system("clear");
		}
	}
	else if(opt41==2){
		system("clear");
		cout<<"\nEnter your destination: ";
		char dest[30];
		cin>>dest;
		system("clear");
		int i=1; int flag=0;
		cout<<"\nFlightNumber : FlightName : From : To : Day : AvailableSeats;"<<endl;
		while(fgt.read((char *)&f, sizeof(f))){
			if(strcmp(f.from, location)==0){
				if(strcmp(f.to, dest)==0){
					flag=1;
					cout<<endl;
					cout<<i<<")	 ";
					f.useroutput();
					cout<<endl; i++;
				}
			}
		}
		if(!flag){
			cout<<"Sorry no flight";
			getchar();
			system("clear");
		}
		else{
			cout<<"Select your flight: ";
			int whichflight;
			cin>>whichflight;
			fgt.seekg((whichflight-1)*sizeof(f)); //am moving the file read pointer to the selected flight
			fgt.read((char *)&f, sizeof(f));
			f.bookie(a); //this function handles care of the booking and modifies the flight object
			fgt.close();
			fgt.open("flights.dat", ios::out | ios::binary);
			fgt.seekg((whichflight-1)*sizeof(f)); //am moving the file write pointer to the selected flight
			fgt.write((char *)&f, sizeof(f));
			cout<<endl<<"Flight successfully booked."<<endl;
			fgt.close();
			getchar();
			system("clear");
		}

	}
	else if(opt41==3){
		system("clear");
		book(a);
	}
	return ;
}
void Decision3(user a){
	int opt4 = ui.UserMenu(a.username);
	switch(opt4){
		case 1:
			system("clear");
			book(a);
			Decision3(a);
			return;
			break;
		case 2:
			system("clear");
			a.dislplaylog();
			Decision3(a);
			break;
		case 3:
			system("clear");
			Decision3(a);
			break;
		case 4:
			system("clear");
			Decision1();
			break;
		default:
			cout<<"Invalid option.";
			Decision3(a);
	}
	return;
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
            Decision3(chkuser);
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
	ui.Welcome(cname);
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
	else if(op1==3){
		system("exit");
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
	Decision1();
	return 0;
}
