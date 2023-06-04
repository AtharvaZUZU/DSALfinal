#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
	ofstream fout;
	char name[30],ph[15],str[30];
	int choice,result,flag;
    
    do{
    	
    	cout<<"\n\n\n\n$$$$ MENU $$$$"; 
		cout<<"\n1.Add record"; 
        cout<<"\n2.Delete record"; 
        cout<<"\n3.Display all"; 
        cout<<"\n4.Exit"; 
        
        cout<<"\n\nEnter Choice ? ";
        cin>>choice;
        
        switch(choice)
        {
        	case 1:fout.open("Record.txt",ios::app);
        	       cout<<"\nEnter name & phone number : ";
        	       cin>>name>>ph;
        	       fout<<"\n"<<name<<"\t"<<ph;
        	       cout<<"\nInserted Record !!";
        	       fout.close();
        	       break;
        	case 2:fin.open("Record.txt");
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
				   	  fin>>name>>ph;
			   	    
				   	  result=stricmp(name,str);
				   	  if(result==0)
				   	     flag=1;
				   	  else
				   	     fout<<"\n"<<name<<"\t"<<ph;
				   	     
				   	  if(fin.eof())
				   	     break;
				   }
				   if(flag==0)
				      cout<<str<<" Record Not Found !!!";
				   else
				      cout<<str<<" Record Deleted !!!";
				      
				    fin.close();
				    fout.close();
				    remove("Record.txt");
				    rename("Temp.txt","Record.txt");
			       break;
			case 3:fin.open("Record.txt");
			       if(fin==0)
			       {
			       	  cout<<"\nAdd record First !!!";
			       	  break;
				   }
				   cout<<"\nName\tPhone_no\n";
				   while(1)
				   {
				   	  fin>>name>>ph;
		     
				   	  cout<<"\n"<<name<<"\t"<<ph;
				   	  
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
