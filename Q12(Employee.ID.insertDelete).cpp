#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class employee
{
	public:
		
	int emp_id;
	char name[30];
	int salary;
	char designation[30];
	
	void getData()
	{
		cout<<"\nEnter Employee Id :";
		cin>>emp_id;
		cout<<"\nEnter Employee Name :";
		cin>>name;
		cout<<"\nEnter Employee Designation:";
		cin>>designation;
		cout<<"\nEnter Employee salary :";
		cin>>salary;
	}
};
int main()
{
	employee emp;
	ifstream fin;
	ofstream fout;
	int choice,flag,result;
	char str[30] ;
	
	do{
		cout<<"\n********MENU*********";
		cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
		cout<<"\nEnter choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:fout.open("Emp.txt",ios::app);
			       emp.getData();
		           fout<<"\n"<<emp.emp_id<<"\t"<<emp.name<<"\t"<<emp.designation<<"\t"<<emp.salary;
		           fout.close();
			       break;
			case 2:fin.open("Emp.txt");
        	       if(fin==0)
        	       {
        	       	  cout<<"\nAdd Record First !!!";
        	       	  break;
				   }
				   fout.open("Temp.txt");
				   cout<<"\nEnter name for delete record : ";
				   cin>>str;
				   flag=0;
				   while(1)
				   {
				   	  fin>>emp.emp_id>>emp.name>>emp.designation>>emp.salary;
			   	    
				   	  result=stricmp(emp.name,str);
				   	  if(result==0)
				   	     flag=1;
				   	  else
				   	     fout<<"\n"<<emp.emp_id<<"\t"<<emp.name<<"\t"<<emp.designation<<"\t"<<emp.salary;
				   	  
				   	  if(fin.eof())
				   	     break;
				   }
				   if(flag==0)
				      cout<<str<<" Record Not Found !!!";
				   else
				      cout<<str<<" Record Deleted !!!";
				      
				    fin.close();
				    fout.close();
				    remove("Emp.txt");
				    rename("Temp.txt","Emp.txt");
			       break;
			case 3:fin.open("Emp.txt");
			       if(fin==0)
        	       {
        	       	  cout<<"\nAdd Record First !!!";
        	       	  break;
				   }
				   cout<<"\nEmp_ID\tName\tDesignation\tSalary";
				   while(1)
				   {
				   	  fin>>emp.emp_id>>emp.name>>emp.designation>>emp.salary;
		     
				   	  cout<<"\n"<<emp.emp_id<<"\t"<<emp.name<<"\t"<<emp.designation<<"\t"<<emp.salary;
				   	  
				   	  if(fin.eof())
				   	     break;
				   	  
				   }
				   fin.close();
			       break;
			case 4:cout<<"\nThanks for using !!!";
			       break;
		    default:cout<<"\nInvalid Choice !!!";
			        break;   	
		}
		
	}while(choice!=4);
	
	return 0;
}
