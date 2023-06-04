/*---------------------------------------------------------------------------------------------------------------------------------------------------------------
10. Consider a scenario for Hospital to cater services to different kinds of patients as 
a) Serious (top priority),
b) non-serious (medium priority),
c) General Checkup (Least priority).
Implement the priority queue to cater services to the patients.*/

#include <iostream>
using namespace std;

class priority
{
    int p[10];
    string a[10];

    public:
    void input(int n)
    {
        for(int i=0;i<n;i++)
    {
        cout<<"enter name of patient: "<<endl;
        cin>>a[i];
        cout <<"enter the priority of patient (1-Serious... || 2-Non-Serious... || 3-General Checkup...)"<<a[i]<<" : " <<endl;
        cin>>p[i];
    }
    } 

    void sort(int n)
    {
        for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        if(p[j]>p[j+1])
        {
            int temp1 = p[j];
                p[j] = p[j+1];
                p[j+1] = temp1;
            
            string temp2 = a[j];
                a[j] = a[j+1];
                a[j+1] = temp2;
            

        }
    }
    }

    void display(int n)
    {
        for(int i=0;i<n;i++)
    {

        cout<<a[i]<<" \t\t";
        cout<<p[i]<<" \t\t";

        if(p[i]==1)
        {
            cout<<"icu"<<" ";
        }
        else if(p[i]==2)
        {
            cout<<"special"<<" ";
        }
        else
        {
            cout<<"general"<<" ";
        }
        cout<<endl;
    }
    }

};

int main()
{
    priority h;
    int n;
    cout <<"enter the number of patients : " <<endl;
    cin>>n;

    h.input(n);
    h.sort(n);

    cout<<"The patients on priority  basis are: "<<endl;
    cout<<endl;
    cout<<"patient name\t"<<"priority \t"<< "ward "<<endl;
    cout<<endl;
    h.display(n);
}
