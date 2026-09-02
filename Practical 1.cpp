#include<iostream>
using namespace std;
struct Student
{

    char name[50];
    char address[50];
    long long int prn;
    float marks;
	
	public:
		void setData()
		{
			cout<<"Enter Student Details "<<endl;
			
			cout<<"Enter Student Name :";
			cin>>name;
			
			cout<<"Enter Student Address:";
			cin>>address;
			
			cout<<"Enter Student PRN :";
			cin>>prn;
			
			cout<<"Enter Student Marks :";
			cin>>marks;
			
		}
		void showData()
		{
			cout<<"=====STUDENT INFORMATION====="<<endl;
			
			cout<<"Student Name :"<<name<<endl;
			cout<<"Student Address :"<<address<<endl;
			cout<<"Student PRN :"<<prn<<endl;
			cout<<"Student Marks :"<<marks<<endl;
		}
};
int main()
{
	Student s[100];
	Student *ptr;
	ptr=s;
	
	int n;
    cout<<"\n Enter No Of Students :";
    cin>>n;
    
   for(int i=0 ; i<n ; i++)
      {
      	(ptr+i)->setData();
	  }
      for(int i=0 ; i<n ; i++)
      {
      	(ptr+i)->showData();
	  }

}

