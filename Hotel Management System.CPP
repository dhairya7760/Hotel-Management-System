#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<cstring>
using namespace std;

int ac=50;
int non_ac=50;
int no_of_room=100;

class hotel
{
	public:
	int day,year,month;
	int no_of_person;
	int no_of_room;
	char name[30];
	char nationality[20];
	int ac;
	int room_no;
	int non_ac;
	int no_of_day;
	char address[20];
}h;

void welcome()
{
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\t\t\t*****************************";
	cout<<"\n\t\t\t  !!!!HOTEL MANAGEMENT!!!!\n";
	cout<<"\t\t\t\t PROJECT \n";
	cout<<"\t\t\t*****************************";
	system("PAUSE");
	cout<<"\n PROJECT PRESENTED BY : ";
	cout<<"\n\t\t\t DHAIRYA CHANGELA-CS 19162171007 \n\t\t\t PRAFFUL CHOUDHARY-CS 19162171008 \n\t\t\t DARSH TURAKHIA-CS 19162171009 \n ";
	cout<<"\n INSTITUTE OF COMPUTER TECHNOLOGY ";
	system("PAUSE");
	cout<<"\n\n\n\n\n\t\tPress any key to continue";
}

void create()
{
	system("CLS");
	char ch;
	ofstream fo("hotel1.dat",ios::app);
	cout<<"\n\t\t\nCREATING FILE";
	cout<<"\nDate of Arrival:";
	cin>>h.day;
	cout<<"\nMonth: ";
	cin>>h.month;
	cout<<"\nYear: ";
	cin>>h.year;
	cout<<"\nNo_of_person: ";
	cin>>h.no_of_person;
	cout<<"\nName: ";
	gets(h.name);
	cout<<"\nAddress: ";
	gets(h.address);
	cout<<"\nNationality: ";
	gets(h.nationality);
	
	if(no_of_room>0)
	{
		cout<<"\nEnter choice (A for ac & N for non_ac): ";
		cin>>ch;
		
		if(ch=='A')
		{
			if(ac>0)
			{
				cout<<"\nENTER ROOM NO: ";
				cin>>h.room_no;
				ac=ac-1;
			}
			no_of_room=no_of_room-1;
			cout<<"\nNow total room available: "<<no_of_room;
		}
			
		else
		{
			if(non_ac>0)
			{
				cout<<"\nENTER ROOM NO : ";
				cin>>h.room_no;
				non_ac=non_ac-1;
			}
			no_of_room=no_of_room-1;
			cout<<"\nNow total room available: "<<no_of_room;
		}
	}
	fo.write((char *)&h,sizeof(h));
	fo.close();
	system("PAUSE");
}

void initial()
{
	h.ac=50;
	h.no_of_room=100;
}

void status()
{
	system("CLS");
	ifstream fi("hotel1.dat",ios::binary|ios::app|ios::in);
	cout<<"\n\t\t\tSTATUS";
	
	while(!fi.eof())
	{
		fi.read((char*)&h,sizeof(h));
	}
	fi.close();
	cout<<"\n";
	cout<<"\n No. of room available in the Hotel : "<<no_of_room;
	system("PAUSE");
}

void read()
{
	system("CLS");
	ifstream fi("hotel1.dat",ios::binary|ios::app|ios::in);
	cout<<"\nPEOPLE STAYING IN THE HOTEL";
	
	while(fi.read((char*)&h,sizeof(h)))
	{
		cout<<"\nRoom No:"<<h.room_no;
		cout<<"\nName:"<<h.name;
		cout<<"\nAddress:"<<h.address;
		cout<<"\nNationality :"<<h.nationality;
		cout<<endl;
	}
	fi.close();
	system("PAUSE");
}

void search()
{
	system("CLS");
	int f=0;
	char n[20];
	ifstream fi("hotel1.dat",ios::binary|ios::app|ios::in);
	cout<<"\nEnter name to whose record to be search: ";
	gets(n);

	while(fi.read((char*)&h,sizeof(h)))
	{
		if(strcmp(n,h.name)==0)
		{
			cout<<"\n\t\tRecord FOUND";
			cout<<"\n\n";
			cout<<"\t\tDetails of record:"<<endl;
			cout<<"\n\tName: "<<h.name;
			cout<<"\n\tNationality: "<<h.nationality;
			cout<<"\n\tDate of Arrival:"<<h.day<<"\t"<<h.month<<"\t"<<h.year;
			cout<<"\n\tNo. of person:"<<h.no_of_person;
			f=1;
			break;
		}
	}
	
	if(f==0)
	cout<<"\nRECORD DOES NOT EXISTS :";
	fi.close();
	system("PAUSE");
}

void modify()
{
	system("CLS");
	int a=0;
	char n[20];
	fstream fo;
	fo.open("hotel1.dat",ios::out|ios::in);
	cout<<"\t\tMODIFY";
	cout<<"\nEnter name of person whose record is to be modify: "; gets(n);
	
	while(fo.read((char*)&h,sizeof(h)))
	{
		if(strcmp(n,h.name)==0)
		{
			long p=fo.tellp()-sizeof(h);
			cout<<"\n\tEnter new detail";
			cout<<"\nEnter no_of_person: ";
			cin>>h.no_of_person;
			cout<<"\nEnter Name: ";
			gets(h.name);
			cout<<"\nEnter Address: ";
			gets(h.address);
			cout<<"\nEnter Nationality: ";
			gets(h.nationality);
			a=1;
			fo.seekp(p,ios::beg);
			fo.write((char*)&h,sizeof(h));
			break;
		}
	}

	if(a==0)
	cout<<"\nEMPTY RECORD";
	fo.close();
	system("PAUSE");
}

void delet()
{
	system("CLS");
	int f=0;
	char c;
	char n[30];
	fstream fi;
	fi.open("hotel1.dat",ios::in);
	fstream fo;
	fo.open("new.dat",ios::out);

	cout<<"\t\t\tDELETE";
	cout<<"\nEnter name of person whose record is to be deleted : ";
	gets(n);

	while(fi.read((char*)&h,sizeof(h)))
	{
		if(strcmp(n,h.name)==0)
		{
			f=1;
			cout<<"\nDETAIL OF PERSON: ";
			cout<<"\n NAME :" <<h.name<<"\n";
			cout<<"\n NATIONALITY :" <<h.nationality<<"\n";
			cout<<"\n ADDRESS :" <<h.address<<"\n";
			cout<<"\nDATE OF ARRIVAL :	"<<h.day<<"\t"<<h.month<<"\t" <<h.year;no_of_room++;
		}
		else
			fo.write((char*)&h,sizeof(h));
	}
	fi.close();
	fo.close();
	
	if(f==0)
	cout<<"\nRECORD DOES NOT EXISTS";
	remove("hotel1.dat");
	rename("new.dat","hotel1.dat");
	system("PAUSE");
}

int main()
{
	welcome();
	int c;
	char ch;
	system("CLS");
	cout<<"\t\t";
	top:
	cout<<"\n\n\t\tMAIN MENU\n\n";
	cout<<"\n\t\tPress:\n\t\t(1) Create";
	cout<<"\n\t\t(2) Check status";
	cout<<"\n\t\t(3) Delete a record";
	cout<<"\n\t\t(4) Modify a record";
	cout<<"\n\t\t(5) Search a record";
	cout<<"\n\t\t(6) Read all the records";
	cout<<"\n\t\t(7) Exit";
	cout<<"\n\n\n\t\t\t\tEnter your choice: ";
	cin>>c;

	switch(c)
	{
		case 1:
		create();
		break;
		
		case 2:
		initial();
		status();
		break;
		
		case 3:
		delet();
		break;

		case 4:
		modify();
		break;

		case 5:
		search();
		break;

		case 6:
		read();
		break;

		case 7:
		cout<<"\n\n\n";
		cout<<"\t\t\t\tPLEASE WAIT...";		  
		cout<<"\n\n\n";
		cout<<"\t\t\t\t   EXITING";
		system("PAUSE");
		exit(0);

		default:
		cout<<"\n\n\t\t\t\t!!Invalid choice!!";
		cout<<"\n\n\n";
	}
	
	cout<<"\n\nWant to continue(Y/N)";
	cin>>ch;
	
	if(ch=='y'||ch=='Y')
	goto top;
	else
	exit(0);
}
