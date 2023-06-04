#include<iostream>
using namespace std;

class Heap{
	int n;
	int *minHeap, *maxHeap;
	
	public:
		void get();
		
		void displayMin() {
			cout<<"\n Minimum Number is: "<<maxHeap[0];
		}
		
		void displayMax() {
			cout<<"\n Maximum number is: "<<minHeap[0];
		}
		
		void upAdjust(bool, int);
};

void Heap::get() {
	cout<<"\n Enter the number of entries you want: ";
	cin>>n;
	
	int k;
	minHeap = new int[n];
	maxHeap = new int[n];
	
	cout<<"\n Enter the number: ";
	for(int i = 0; i<n; i++) {
		cin>>k;
		minHeap[i] = k;
		upAdjust(0, i);
		maxHeap[i] = k;
		upAdjust(1, i);
	}
}

void Heap::upAdjust(bool m, int l) {
	int s;
	if(!m) {
		while(minHeap[(l-1)/2] < minHeap[l]) {
			s = minHeap[l];
			minHeap[l] = minHeap[(l-1)/2];
			minHeap[(l-1)/2] = s;
			l = (l-1)/2;
			
			if(l == -1) {
				break;
			}
		}
	} else {
		while(maxHeap[(l-1)/2] > maxHeap[l]) {
			s = maxHeap[l];
			maxHeap[l] = maxHeap[(l-1)/2];
			maxHeap[(l-1)/2] = s;
			l = (l-1)/2;
			
			if(l == -1) {
				break;
			}
		}
	}
}

int main() {
	int choice;
Heap h;
	
	do{
			
	cout<<"\n 1. Min Heap number";
	cout<<"\n 2. Max Heap number";
	cout<<"\n 3.  Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
		
	switch(choice) {
		case 1:{
			h.get();
			h.displayMin();
			break;
		}
		case 2:{
			h.get();
			h.displayMax();
			break;
		}
		case 3:{
			exit(0);
			break;
		}
		default:{
			cout<<"\n Error! Invalid choice";
			break;
		}
	}
	}while(choice != 3);
	return 0;
}

