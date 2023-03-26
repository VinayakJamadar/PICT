/* Problem Statement :
	Implement all the functions of a dictionary (ADT) using hashing and handle collisions
	using separate chaining using linked list.
	Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
	Keys must be unique.
	Standard Operations: Insert(key, value), Find(key), Delete(key) */

#include <bits/stdc++.h>
using namespace std;

// defining macro size as 10
#define size 10

// Class Node for Linked List
class Node
{

	string key;
	string value;
	Node *next;

public:
	// Default Constructor
	Node()
	{
		key = "";
		value = "";
		next = NULL;
	}
	// Parameterized Constructor
	Node(string k, string v)
	{
		key = k;
		value = v;
		next = NULL;
	}
	// Copy Constructor
	Node(Node &obj)
	{
		key = obj.key;
		value = obj.value;
		next = NULL;
	}

	// Making Dictionary class as friend class of Node
	// So that Dictionary class can access the private data members
	// and member functions of class Node.
	friend class Dictionary;
};

// class Dictionary
// Abstract Data Type Means hiding implementation from user.
// Here we Declaring Functions inside class
// and Defining them outside the class using
// Scope Resolution Operator ::
class Dictionary
{
	Node *Bucket_of_Roots[size];

public:
	Dictionary();
	int Hash_Function(string key);
	void Insert_Entry(string key, string value);
	void Display_Entries();
	void Find_Entry(string key);
	void Delete_Entry(string key);
};

// Default Constructor
// Here Root of all Buckets are set to NULL
Dictionary::Dictionary()
{
	for (int i = 0; i < size; i++)
	{
		Bucket_of_Roots[i] = NULL;
	}
}

// Hash Function
// Hash Function is (sum of ascii value of all characters of string) mod (size)
// f(key) = (sum of digit of key) % size
int Dictionary::Hash_Function(string key)
{
	char character;
	int sum = 0, length = key.length();
	for(int i = 0; i < length; i++){
		character = key[i];
		sum += character;
	}
	return sum % size;
}

// Inserting Entry in Dictionary(or HashTable)
void Dictionary::Insert_Entry(string key, string value)
{
	int Hash_Index = Hash_Function(key);
	Node *Entry = new Node(key, value);
	Node *Current = Bucket_of_Roots[Hash_Index], *Previous = Current;

	// Inserting first Node in Bucket
	if (Current == NULL)
	{
		Bucket_of_Roots[Hash_Index] = new Node(*Entry);
		cout << "Key Inserted Successfully." << endl;
		return;
	}

	while (Current != NULL)
	{
		// Key repeated
		if (key == Current->key)
		{
			cout << "This key is already present in Dictionary." << endl;
			return;
		}
		Previous = Current;
		Current = Current->next;
	}

	Previous->next = Entry;
	// Key Inserted
	cout << "Key Inserted Successfully." << endl;
}

// Finding or Searching Entry in Dictionary(or HashTable)
void Dictionary::Find_Entry(string key)
{
	int Hash_Index = Hash_Function(key);
	Node *Current = Bucket_of_Roots[Hash_Index];
	int comparisons = 0;
	while (Current)
	{
		comparisons++;
		// Key found
		if (key == Current->key)
		{
			cout << "Key Found" << endl;
			cout << "Key : " << Current->key << endl;
			cout << "Value : " << Current->value << endl;
			cout << "Comparisons : " << comparisons << endl;
			return;
		}
		Current = Current->next;
	}

	// Key not Found
	cout << "Key Not Found" << endl;
	cout << "Comparisons : " << comparisons+1 << endl;
}

// Displaying Entries from Dictionary(or HashTable)
void Dictionary::Display_Entries()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Bucket No. " << i << " -> ";
		Node *Current = Bucket_of_Roots[i];
		while (Current)
		{
			cout << "[ " << Current->key << " " << Current->value << " ] -> ";
			Current = Current->next;
		}
		cout << "[ -1 NULL ]" << endl;
	}
}

// Deleting Entry from Dictionary(or HashTable)
void Dictionary::Delete_Entry(string key)
{
	int Hash_Index = Hash_Function(key);
	Node *Current = Bucket_of_Roots[Hash_Index], *Previous = Current;
	while (Current)
	{
		// Key found
		if (key == Current->key)
		{
			cout << "Key " << Current->key << " is Deleted from Dictionary" << endl;
			if (Previous == Current)
				Bucket_of_Roots[Hash_Index] = Current->next;
			else
				Previous->next = Current->next;
			return;
		}
		Previous = Current;
		Current = Current->next;
	}

	// Key not Found
	cout << "Key Not Found" << endl;
}

int main()
{

	// Creating Instance of Dictionary class
	Dictionary D;

	string key;
	string value;

	// Menu for Standard Operations on Dictionary
	while (1)
	{
		cout << "\n1. Insert Entry." << endl;
		cout << "2. Find Entry." << endl;
		cout << "3. Display Entries." << endl;
		cout << "4. Delete Entry." << endl;
		cout << "5. Exit." << endl;

		int choice;
		// Reading choice from user
		cout << "Enter your choice from Above Menu : ";
		cin >> choice;
		cout << endl;

		// Insertion of Entry in Dictionary
		if (choice == 1)
		{
			cout << "Enter Key : ";
			cin >> key;
			cout << "Enter Value : ";
			cin >> value;
			D.Insert_Entry(key, value);
		}
		// Finding or Searching Entry in Dictionary
		else if (choice == 2)
		{
			cout << "Enter Key to be Searched : ";
			cin >> key;
			D.Find_Entry(key);
		}
		// Displaying all Entries from Dictionary
		else if (choice == 3)
		{
			cout << "**** Dictionary ****\n"<< endl;
			D.Display_Entries();
		}
		// Deleting Entry from Dictionary
		else if (choice == 4)
		{
			cout << "Enter Key to be Deleted : ";
			cin >> key;
			D.Delete_Entry(key);
		}
		// Program Exit
		else if (choice == 5)
		{
			cout << "Program Exit." << endl;
			break;
		}
		// Invalid Choice
		else
		{
			cout << "Enter a valid choice." << endl;
		}
	}

	return 0;
}