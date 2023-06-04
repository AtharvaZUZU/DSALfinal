/*--------------------------------------------------------------------------------------------------------------------------------------------------

6. There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city. 
Use adjacency list representation of the graph or use adjacency matrix representation of the graph. 
Check whether the graph is connected or not. Justify the storage representation used.*/

#include <iostream>
using namespace std;

class graph
{
	
int a[5][5],flag;
string c[5];

public:

void city(int n)
{
cout<<"Enter the names of cities : "<<endl;
for(int i=0;i<n;i++)
{
cout << i+1 << " . City Name : ";
cin>>c[i];
}
}

void time(int n)
{
cout<< "Enter time taken to travel from city to city "<< endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
cin>>a[i][j];
}
}
}

void ajd_mat(int n)
{
cout<<"adjacency matrix : "<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}
}

void connected(int n)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if( a[i][j] != a[j][i])
{
	flag = 0;
}

}
}

if (flag ==0)
{
cout<<"The graph is not connected"<<endl;
}

else
{
cout<<"The graph is connected"<<endl;
}
}
};


int main()
{
int n;
cout<<"Enter the number of Cities : "<<endl;
cin>>n;	

graph g;

g.city(n);
g.time(n);
g.ajd_mat(n);
g.connected(n);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}
