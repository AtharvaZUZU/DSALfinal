#include<iostream>
using namespace std;
struct node
{
        string data;
        node* child[10];
        int count;
};
class csbook
{
public:
        node* root;
        csbook()
        {
                root=NULL;
        }
    void create();
    void display();
};
void csbook::create()
{
        int i,j,k;
        root=new node;
 cout<<"Enter the book name \n";
 cin>>root->data;
 cout<<"How many chapters \n";
 cin>>root->count;

 for(i=1;i<=root->count;i++)
 {
         cout<<"Enter the chapter name \n";
         root->child[i]=new node;
     cin>>root->child[i]->data;
     cout<<"How many sections \n";
     cin>>root->child[i]->count;


     for(j=1;j<=root->child[i]->count;j++)
     {
         cout<<"Enter the sections name \n";
         root->child[i]->child[j]=new node;
         cin>>root->child[i]->child[j]->data;
          cout<<"How many sub-sections \n";
     cin>>root->child[i]->child[j]->count;
     
     
      for(k=1;k<=root->child[i]->child[j]->count;k++)
     {
         cout<<"Enter the sub-sections name \n";
         root->child[i]->child[j]->child[k]=new node;
         cin>>root->child[i]->child[j]->child[k]->data;
     }
 }
}
}
void csbook::display()
{
        int i,j,k;

 cout<<"the book name : "<<root->data<<"\n";
 for(i=1;i<=root->count;i++)
 {
   cout<<"the chapter "<<i<<" : "<<root->child[i]->data<<"\n";

     for(j=1;j<=root->child[i]->count;j++)
     {
         cout<<"the sections "<<i<<" : "<<root->child[i]->child[j]->data<<"\n";
     
     for(k=1;k<=root->child[i]->child[j]->count;k++)
     {
         cout<<"the sub-sections "<<i<<" : "<<root->child[i]->child[j]->child[k]->data<<"\n";
     }
}
}
}
int main()
{
        csbook p;
        char ans;
    int ch;
    do
    {
   cout<<"-----------MAIN MENU------------ \n";
   cout<<"1.for create \n";
   cout<<"2.for display \n";
   cin>>ch;
   switch(ch)
   {
   case 1 :
           p.create();
           break;
   case 2 :
           p.display();
           break;
   }
   cout<<"Do u want to continue";
   cin>>ans;
    }
    while(ans=='y'||ans=='Y');
    return 0;
}
