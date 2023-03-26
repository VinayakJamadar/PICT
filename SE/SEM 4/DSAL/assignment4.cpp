/* Problem Statement :
	Consider telephone book database of N clients. Make use of a hash table implementation
	to quickly look up client's telephone number. Make use of two collision handling
	techniques and compare them using number of comparisons required to find a set
	of telephone numbers (use linear probing with replacement and without replacement) */

#include <iostream>
#include <string.h>
using namespace std;

// typedef of long long int as lli
typedef long int li;

// defining macro size as 10
#define size 100

// class HashEntry
class HashEntry{
	li telephone_no;
	string name;

public:
	// Default Constructor
	HashEntry(){
		telephone_no = 0;
		name = "";
	}
	// Parameterized Constructor
	HashEntry(li t_no, string n){
		telephone_no = t_no;
		name = n;
	}

	// Copy Constructor
	HashEntry(HashEntry &obj){
		telephone_no = obj.telephone_no;
		name = obj.name;
	}
	// Making HashTable class as friend class of HashEntry
	// So that HashTable class can access the private data members
	// and member functions of class HashEntry.
	friend class HashTable;
};

// class HashTable
class HashTable{

	HashEntry H[size];

public:

	// Hash Function
	int HashFunc(li t){
		int sum = 0;
		while(t){
			sum += (t%10);
			t /= 10;
		}

		return sum % size;
	}

	// Insert using linear probing without replacement
	void insert_wor(li key, string value){
		int hash_index = HashFunc(key), count = 0;
		HashEntry entry;
		entry.telephone_no = key;
		entry.name = value;

		while(H[hash_index].telephone_no){
			hash_index = (hash_index+1)%size;
			count++;
		}

		H[hash_index] = entry;
		cout<<"Collision : "<<count<<endl;
		display();
	}

	// Insert using linear probing with replacement
	void insert_wr(li key, string value){
		int hash_index = HashFunc(key), count = 0;
		HashEntry entry;
		entry.telephone_no = key;
		entry.name = value;

		// If Bucket is Empty
		if(H[hash_index].telephone_no == 0){
			H[hash_index] = entry;
		}
		// If Bucket is not Empty and Entry inside the Bucket is not at its correct Hash Index
		else if(hash_index != HashFunc(H[hash_index].telephone_no)){
			HashEntry wrong_entry = H[hash_index];
			H[hash_index] = entry;
			while(H[hash_index].telephone_no){
				hash_index = (hash_index+1)%size;
				count++;
			}
			H[hash_index] = wrong_entry;
		}
		// If Bucket is not Empty and Entry inside the Bucket is at its correct Hash Index
		else{
			while(H[hash_index].telephone_no){
				hash_index = (hash_index+1)%size;
				count++;
			}
			H[hash_index] = entry;
		}

		cout<<"Collision : "<<count<<endl;
		display();
	}

	// Display all Entries of HashTable
	void display(){
		cout<<"\n***Entries***\n"<<endl;
        for (int i = 0; i < size; i++)
        {
            if(H[i].telephone_no){
				cout<<"Bucket : "<<i<<endl;
				cout<<"Telephone No : "<<H[i].telephone_no<<endl;
				cout<<"Name : "<<H[i].name<<"\n"<<endl;
            }
        }
		cout<<"*************"<<endl;
	}

	// Search Entry in HashTable
	void search(li key){
		int hash_index = HashFunc(key), original_hash_index = hash_index, count = 1;
		while(H[hash_index].telephone_no != key){
			hash_index = (hash_index+1)%size;
			count++;
			if(hash_index == original_hash_index){
				cout<<"This Entry is not Found in Table."<<endl;
				return ;
			}
		}

		cout<<"Comparisons : "<<count<<endl;
		cout<<"Bucket No : "<<hash_index<<endl;
		cout<<"Telephone No : "<<H[hash_index].telephone_no<<endl;
		cout<<"Name : "<<H[hash_index].name<<"\n"<<endl;
	}
};

int main() {

	HashTable HT_wor; // HashTable for linear probing without replacement
	HashTable HT_wr; // HashTable for linear probing with replacement

	int entries = 0;

	li telephone_no;
	string name;

	// Menu for Operations of Telephone Database
	while (1)
	{
		cout<<"\n1. Create Entry."<<endl;
		cout<<"2. Search Entry."<<endl;
		cout<<"3. Exit."<<endl;

		int choice;
		// Reading choice from user
		cout<<"Enter your choice from Above Menu : ";
		cin>>choice;

		if(choice == 1){
			// Exception Handling if Total Entries become greater than size of HashTable
			entries++;
			if(entries > size){
				cout<<"You can only Create "<<size<<" Entries."<<endl;
				continue;
			}
			cout<<"Enter Telephone Number : ";
			cin>>telephone_no;
			cout<<"Enter Name : ";
			cin>>name;

			// Insertion of Entry in HashTable with linear probing without Replacement
			cout<<"\nLinear probing Without Replacement\n"<<endl;
			HT_wor.insert_wor(telephone_no, name);

			// Insertion of Entry in HashTable with linear probing with Replacement
			cout<<"\nLinear probing With Replacement\n"<<endl;
			HT_wr.insert_wr(telephone_no, name);
		}
		else if(choice == 2){
			if(entries == 0){
				cout<<"Entries are not Yet Created."<<endl;
				continue;
			}
			cout<<"Enter Telephone Number to be Searched : ";
			cin>>telephone_no;

			// Search of Entry in HashTable with linear probing without Replacement	
			cout<<"\nLinear probing Without Replacement\n"<<endl;
			HT_wor.search(telephone_no);

			// Search of Entry in HashTable with linear probing with Replacement				
			cout<<"\nLinear probing With Replacement\n"<<endl;
			HT_wr.search(telephone_no);
		}
		else if (choice == 3){
			cout << "Program Exit." << endl;
			break;
		}
		else{ // Invalid Choice
			cout<<"Enter a valid choice."<<endl;
		}
	}

	return 0;
}