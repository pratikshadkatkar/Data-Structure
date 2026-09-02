#include<iostream>
#include<string>
using namespace std;
struct Employee
{
	int id;
    string name;
	float salary;
	Employee *Next;
};

    Employee *head=NULL;
    void insertEmployee()
    {
    	Employee *newNode=new Employee;
    	
    	cout<<"Enter Employee ID :";
    	cin>>newNode->id;
    	
    	cout<<"Enter Employee Name :";
    	cin>>newNode->name;
    	
    	cout<<"Enter Employee Salary :";
    	cin>>newNode->salary;
    	
    	newNode->Next=NULL;
    	
    	if(head==NULL)
    	{
    		head=newNode;
		}
		else
		{
			Employee *temp=head;
			while (temp->Next != NULL)
            temp = temp->Next;
            temp->Next = newNode;
    
		}
		cout<<"\n Employee inserted successfully" ;
		
	}
void deleteEmployee()
{
    if (head == NULL)
	 {
        cout << "List is empty \n";
        
    }
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Employee* temp = head;
    Employee* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->Next;
    }
    if (temp == NULL) {
        cout << "Employee not found\n";
        return;
    }

    if (prev == NULL)
        head = head->Next;
    else
        prev->Next = temp->Next;

    delete temp;
    cout << "Employee deleted successfully\n";
}
void searchEmployee()
{
	if (head==NULL)
	{
		cout<<"list is empty \n";
	}
	int id;
	cout<<"Enter Employee id to search :";
	cin>>id;
	
	Employee* temp =head;
	while(temp !=NULL){
	
	 if (temp->id == id) {
           
            cout << "ID: " << temp->id << endl;
            cout << "name: " << temp->name<<endl;
			cout << "salary: "<< temp->salary<<endl;
		}
		temp=temp->Next;
        }
        
}
void displayEmployees()
{
	if(head==NULL)
	{
		cout<<"No Employee Record Available\n";
		
	}
	Employee* temp = head;

    cout << "\nEmployee Records\n";
    cout << "-----------------------------\n";

    while (temp != NULL) {
        cout << "ID     : " << temp->id << endl;
        cout << "Name   : " << temp->name << endl;
        cout << "Salary : " << temp->salary << endl;
        cout << "-----------------------------\n";

        temp = temp->Next;
    }
}

int main()
{
	
    int choice;

    do {
        cout << "\n===== Employee Record Management =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employee\n";
        cout <<"Exit\n";
        cout <<"Enter Your Choice :";
        cin>>choice;
        switch (choice) {
            case 1:
                insertEmployee();
                break;
            case 2:
            	deleteEmployee();
            	break;
            case 3:
            	searchEmployee();
            	break;
            case 4:
            	displayEmployees();
            	break;
            case 5:
            	cout<<"Program exited :";
            	break;
            default:
            	cout<<"Invalid Choice :";
    }
}
    while(choice!=5);

}

