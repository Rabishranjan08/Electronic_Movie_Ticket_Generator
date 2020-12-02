
#include<iostream>
#include<fstream>

using namespace std;

class ticket
{
public:
int ticket_no,d,m,y,sheet_no,hall_no,hour,min,time,people;
float price;
char movie_name[20];
ticket()
{
 ticket_no=0;
}
void get_data();
void save_data();
void read_data();
void show_data();
void get_ticket_no();
void ticket_validation();
}t;

void ticket::get_data()
{
 t.ticket_no++;
 cout<<"Enter movie name"<<endl;
  cin>>t.movie_name;
 cout<<"Enter movie price"<<endl;
  cin>>t.price;
 cout<<"Enter date: dd mm yyyy"<<endl;
 cin>>t.d>>t.m>>t.y;
 cout<<"enter Sheet Number"<<endl;
 cin>>t.sheet_no;
 cout<<"enter Hall Number"<<endl;
 cin>>t.hall_no;
 cout<<"enter Hour/ Minute "<<endl;
 cin>>t.hour>>t.min;
 cout<<"enter Number of People"<<endl;
 cin>>people;

 save_data();
// getche();
}
void ticket::save_data()
{
fstream fout;
fout.open("file",ios::app);
//cout<<"File Created";
fout.write((char*)&t,sizeof(t));
fout.close();
}

void ticket::read_data()
{
// system("cls");  clrscr();
cout<<"Showing all the tickets: \n"<<endl;
ifstream fin;
fin.open("file",ios::in);
//cout<<"File Created";
while(fin.read((char*)&t,sizeof(t)))
 show_data(); //cout<<"Name is: "<<t.movie_name;
fin.close();
}
void ticket::show_data()
{
 cout<<"Ticket id: "<<ticket_no<<endl;
 cout<<"Movie Name: "<<movie_name<<endl;
 cout<<"Ticket Price: "<<price<<endl;
 cout<<"No of People: "<<people<<endl;
 cout<<"Hall number :"<<hall_no<<endl;
 cout<<"Time: "<<hour<<" "<<min<<endl;
 cout<<"Date: "<<d<<" "<<m<<" "<<y<<endl;
 cout<<"******************************"<<endl;
}

void ticket::get_ticket_no()
{
ifstream fin;
fin.open("file",ios::in);

 while(fin.read((char*)&t,sizeof(t)))
  { }
 fin.close();
}

void ticket::ticket_validation()
{
 int num,found=0;
 cout<<"Enter ticket Number: "<<endl;
  cin>>num;
 ifstream fin;
fin.open("file",ios::in);

while(fin.read((char*)&t,sizeof(t)))
 {
  if(ticket_no==num)
    {
      cout<<"Ticket Found: "<<endl; 
      found=1; show_data(); break; }
 }
if(found==0)
  cout<<"Ticket Not Found: "<<endl;
fin.close();
}

/* * * * * * * * * * * * * * * *    M A I N     B O D Y  * * * * * * * * * * *  * * * */

int main()
{
int ch;
t.get_ticket_no();
do
{
cout<<"1. Book Ticket"<<endl;
cout<<"2. Show All ticket Booking"<<endl;
cout<<"3. Validate Ticket: "<<endl;
cout<<"4. Exit"<<endl;
cout<<"Enter Your choice: "<<endl;
cin>>ch;
switch(ch)
 {
  case 1:t.get_data();
	 break;
  case 2:t.read_data();
	 break;
  case 3:t.ticket_validation();
	 break;
  case 4://exit(0);
 	 break;
  default: cout<<"\nNot A Valid Choice\nEnter Another Choice\n\n"<<endl;
 }
}while(ch!=4);

return 0;
}
