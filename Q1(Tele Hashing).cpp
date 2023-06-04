#include<iostream>
#include<vector>
using namespace std;

struct Client {
	string name;
	int phoneNumber;
};

class hashTable {
	public:
		static const int size = 10;
		Client table[size];
		int collisions[size];
		
		//constructor
		hashTable() {
			for(int i = 0; i<size; i++) {
				collisions[i] = 0;
			}
		}
		
		//hash function
		int hash(int key) {
			return key % size;
		}
		
		//linear probing
		void linearProbing(Client c) {
			// created client's object
			int index = hash(c.phoneNumber);
			int count = 0;
			while(collisions[index] == 1) {
				index = (index+1)%size;
				count++;
			}
			table[index] = c;
			collisions[index] = 1;
			cout<<"\n Inserted "<<c.name<<"'s phone number after "<<count<<" number of collisions using linear probing.";
		}
		
		//quadratic probing
		void quadraticProbing(Client c) {
			int index = hash(c.phoneNumber);
			int count = 0;
			while(collisions[index] != 0 && collisions[index] != c.phoneNumber) {
				count++;
				index = (hash(c.phoneNumber) + count*count)%size; 
			}
			table[index] = c;
			collisions[index] = 1;
			cout<<"\n Inserted "<<c.name<<"'s phone number after "<<count<<" number of collisions using quadratic probing.";
		} 
		
		//search a number
		bool search(int num) {
			int index = hash(num);
			int count = 0;
			while(collisions[index] == 0) {
				if(table[index].phoneNumber == num) {
					cout<<"\n Found "<<table[index].name<<"'s phone number after "<<count<<" number of comparisons using linear probing.";
					return true;
				}
				index=(index+1)%size;
				count++;
			}
			cout<<"\n Number not found";
			return false;
		}
};

int main() {
	hashTable ht;
	int num;
	string name;
	int choice = 11;
	int choice2;
		
	while(choice != 0) {
		cout<<"\n 1) Insert Number \n 2) Search Number \n Press 0 to exit \n Enter Your choice: ";
		cin>>choice;
		
		switch(choice) {
			case 1:{
				cout<<"\n Enter your name: ";
				cin>>name;
				cout<<"\n ENter your num: ";
				cin>>num;
				cout<<"\n 1) Linear Probing \n 2) Quadratic Probing \n Enter your choice: ";
				cin>>choice2;
				
				if(choice2 == 1) {
					ht.linearProbing({name, num});
				} else if(choice2 == 2) {
					ht.quadraticProbing({name, num});
				} else {
					cout<<"\n Error! Invalid Option.";
				}
				break;
			}
			case 2:{
				cout<<"\n Enter your num: ";
				cin>>num;
				ht.search(num);
				break;
			}
			case 0:{
				cout<<"\n Exiting the program.";
				exit(0);
				break;
			}
			default:{
				cout<<"\n Error! Invalid choice.";
				break;
			}
		}
	}
	return 0;
}
