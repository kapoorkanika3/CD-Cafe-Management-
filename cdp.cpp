#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int ch,k,m;
int con;
char name[30],add[60],issdate[10];
char cdname[30];
void introduction();
void choice();
void mainmenu();
int finrec();
void display();
int readfile();

class menu
{
public:
	void introduction();
	void choice();
	void mainmenu();
	int finrec();
	int readfile();
	void detail();
	
};
	
void menu:: introduction()
{
   cout<<"\t\t\t\t*****WELCOME TO CD CAFE*****\n\n"<<endl;
   cout<<"\t\tTERMS AND CONDITIONS:"<<endl;
   cout<<"\n1.one member can issue one cd at a time."<<endl;
   cout<<"\n2.member should return cd within 15 days otherwise fine will be applied."<<endl;
   cout<<"\nPress key 1 to continue:"<<endl;
   cin>>k;
   if(k==1)
   {
   void choice();
   }
}
void menu::choice()
{
  system("cls");
  cout<<"\n**********************************";
  cout<<"\n\t CD CAFE";
  cout<<"\n**********************************";
  cout<<"\n1.MOVIES\n2.MUSIC\n3.EXIT";
  cout<<"\nEnter your choice:";
  cin>>m ;
  switch (m)
  {
    case 1:
    {
     system("cls");
	 cout<<"\n***ADVANCE PAYMENT WILL BE OF Rs200***";
	 break;
   }
   case 2:
   {
   	   system("cls");
       cout<<"\n***ADVANCE PAYMENT WILL BE OF Rs100***";
       break;
   }
   case 3:
   {
       exit(0);
   }
   default:
   {
      cout<<"\n INVALID INPUT";
   }
  }
}


void menu :: detail()
{

  	 system("cls");
    cout<<"\t\t\t\t****ADD RECORDS****\n\n";
   cout<<"\nENTER NAME:";
  scanf(" %[^\n]s",name);
    cout<<"\nENTER EMAIL ID:";
  cin>>add;
  cout<<"\n ENTER CONTACT NUMBER:";
  cin>>con;
  cout<<"\nENTER NAME OF THE CD:";
  scanf(" %[^\n]s",cdname);
  cout<<"\n ENTER DATE OF ISSUE:";
  cin>>issdate;
  
}
class bill:public menu
{
   public:
   	void display()
   	{
   	system("cls");
   	cout<<"\t\t\t\t****RECORD****\n\n";
   	cout<<"\nNAME:"<<name<<endl;
    cout<<"EMAIL:"<<add<<endl;
    cout<<"CONTACT:"<<con<<endl;
    cout<<"NAME OF CD:"<<cdname<<endl;
    cout<<"ISSUE DATE:"<<issdate<<endl;
    cout<<"Kindly Return CD Before 15 Days"<<endl;
    cout<<"THANK YOU!!!!!!!"<<endl;
    cout<<"VISIT AGAIN."<<endl;
   		
	  }
};
   	
   int menu:: finrec()
   {
   	if(!name)
   	{
   		cout<<"\n file not found";
   		return 0;
    }
    else
    {
	
   ofstream ofile;
   ofile.open("cddata.txt",ios::app);
   
   ofile<<"\n";
   ofile<<"NAME:"<<name<<endl;
   ofile<<"EMAIL:"<<add<<endl;
   ofile<<"CONTACT:"<<con<<endl;
   ofile<<"CD NAME:"<<cdname<<endl;
   ofile<<"ISSUE DATE:"<<issdate<<endl;
   ofile.write((char *)this,sizeof(*this ));
   
   ofile.close();
   return 1;
   }
}
int menu::readfile()
{
	char str[100];
	ifstream ifile;
	ifile.open("cddata.txt");
	ifile.seekg(0,ios::beg);
	ifile.read((char *)this,sizeof(*this));
	
	while(!ifile)
	{
	      bill();
		ifile.read((char*)this,sizeof(*this));
	}
	ifile.close();
}





int main()
{

//menu m;
bill b;
b.introduction();
b.choice();
while(1)
{


cout<<"\n********************************"<<endl;
cout<<"\n\t\tMENU"<<endl;
cout<<"\n********************************"<<endl;
cout<<"\n1.ADD RECORD\n2.DISPLAY RECORD\n3.EXIT"<<endl;
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
	
  case 1:
  b.detail();
  b.display();
  b.finrec();
  b.readfile();
  break;
  
  
  case 2:
  	{
     std::ifstream file("cddata.txt");
	if(file.is_open())
	std::cout<<file.rdbuf();
	file.close();
     break;
  }
  
  case 3:
  	exit(0);
  	
  	default:
  		{
   cout<<"\nINVALID INPUT:";
  }
}
 	
}
return 0;
}
