/*
	Problem Statement :
	Represent a given graph using adjacency list to perform DFS and BFS.
	Use the map of the area around the college as the graph.
	Identify the prominent landmarks as nodes and perform DFS and BFS on that.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int choice;

// Class Node
class Node{
	int data;
	Node* down;
	Node* next;

public:
	Node();
	Node(int);
	Node(const Node&);
	friend class Graph;
};

// Default Constructor
Node::Node(){
	data = 0;
	down = NULL;
	next = NULL;
}

// Parameterized Constructor
Node::Node(int d){
	data = d;
	down = NULL;
	next = NULL;
}

// Copy Constructor
Node::Node(const Node &obj){
	data = obj.data;
	down = obj.down;
	next = obj.next;
}

// class Graph
class Graph{
	Node *Head;
public:
	Graph();
	void insert_vertex();
	void insert_edge();
	void display_list();
	void bfs();
	void dfs();
};

// Default Constructor
// Set Head Node to NULL
Graph::Graph(){
	Head = NULL;
}

// Inserts the Vertex in Graph
// Exception Handling :
// 1. Also checks for unique Vertex in Graph
void Graph::insert_vertex(){
	while(1){
		cout<<"\nMenu."<<endl;
		cout<<"1. Add Vertex."<<endl;
		cout<<"2. Exit."<<endl;

		cout<<"\nEnter your choice : ";
		cin>>choice;

		if(choice == 1){
			cout<<"Enter vertex number : ";
			int vertex;
			cin>>vertex;
			if(Head == NULL){
				Head = new Node();
				Head->data = vertex;
			}
			else{
				Node *current = Head, *previous = current;
				bool flag = 0;
				while(current != NULL){
					if(current->data == vertex){
						flag = 1;
						break;
					}
					previous = current;
					current = current->down;
				}

				if(flag) cout<<"Vertex "<<vertex<<" is already present in Graph."<<endl;
				else {
					Node* new_node = new Node();
					new_node->data = vertex;
					previous->down = new_node;
					cout<<"Vertex "<<vertex<<" Inserted Successfully."<<endl;
				}
			}
		}

		else if(choice == 2){
			cout<<"Exit."<<endl;
			break;
		}

		// Invalid Choice
		else{
			cout << "Enter a valid choice." << endl;
		}
	}
}


// Inserts the Edge of Source Vertex
// Exception Handling :
// 1. Checks whether both Source and Destination Vertex Exist in Graph or Not
// 2. Insert only one edge between any Source and Destination Vertex.
void Graph::insert_edge(){
	while(1){
		cout<<"\nMenu."<<endl;
		cout<<"1. Insert Edges."<<endl;
		cout<<"2. Exit."<<endl;

		cout<<"\nEnter your choice : ";
		cin>>choice;

		if(choice == 1){
			Node* source_vertex = Head;
			int source;
			cout<<"Enter Source Vertex : ";
			cin>>source;

            // Checks whether Source Vertex Exist in Graph or Not
			bool source_flag = 0;
			while(source_vertex != NULL){
				if(source_vertex->data == source){
					source_flag = 1;
					break;
				}
				source_vertex = source_vertex->down;
			}

			if(source_flag){
				while(1){
                    cout<<"\nEnter Destination Vertices of Source Vertex "<<source<<endl;
					cout<<"1. Enter New Destination Vertex."<<endl;
					cout<<"2. Exit"<<endl;

					cout<<"Enter your choice : ";
					cin>>choice;

					if(choice == 1){
                        Node* destination_vertex = Head;
						int destination;
                        cout<<"Enter Vertex Number of Destination Vertex : ";
						cin>>destination;

                        // Checks whether Destination Vertex Exist in Graph or Not
                        bool destination_flag = 0;
						while(destination_vertex != NULL){
                            if(destination_vertex->data == destination){
                                destination_flag = 1;
                                break;
                            }
                            destination_vertex = destination_vertex->down;
						}

                        if(destination_flag){
                            Node *current = source_vertex, *previous = current;
                            bool already_present = 0;
                            while(current != NULL){
                                // current->data == destination ---> This will checks for unique edge between Source and Destination Vertex
                                // source != destination ---> This will allow a self loop or self edge of Source Vertex
                                if(current->data == destination and source != destination){
                                    already_present = 1;
                                    break;
                                }
                                previous = current;
                                current = current->next;
                            }
                            if(already_present) cout<<"This Edge is already Exist. Enter another Destination Vertex."<<endl;
                            else previous->next = new Node(destination), cout<<"Edge Inserted Successfully."<<endl;
                        }
                        else cout<<"Destination Vertex "<<destination<<" Not Found in Graph."<<endl;
					}

					else if(choice == 2){
						cout<<"Exit."<<endl;
						break;
					}

					// Invalid Choice
					else{
						cout << "Enter a valid choice." << endl;
					}
				}
			}
			else cout<<"Source Vertex "<<source<<" Not Found in Graph."<<endl;
		}

        else if(choice == 2){
            cout<<"Exit."<<endl;
            break;
        }

        // Invalid Choice
        else{
            cout << "Enter a valid choice." << endl;
        }
	}
}

// Display Adjacency list
void Graph::display_list(){
	Node* column = Head;
	while(column != NULL){
		Node* row = column->next;
		cout<<column->data<<" --> ";
		while(row != NULL){
			cout<<row->data<<" --> ";
			row = row->next;
		}
		cout<<"NULL"<<endl;
		column = column->down;
	}
}

void Graph::bfs(){
	int start;
	cout<<"Enter the start point for BFS Traversal : ";
	cin>>start;

	// Checking whether start vertex is present in graph or not
	Node *Visited, *current = Head, *previous = current;
	bool flag = 0;
	while(current != NULL){
		if(current->data == start){
			flag = 1;
			break;
		}
		current = current->down;
	}

	// If start vertex is present in graph
	if(flag){
		// Insert start vertex in Visited Linked List
		Visited = new Node(start);

		// Creating a queue for BFS
		queue <Node*> Q;

		// Insert the start vertex in visited linked list and enqueue in queue
		Q.push(current);

		cout<<"BFS traversal is : [ ";
		while(!Q.empty()) {
			// Dequeue a vertex from queue and print it
			Node* display = Q.front();
			cout<<display->data<<" ";
			Q.pop();

			// Get all adjacent vertices of the dequeued vertex display. 
			// If a adjacent vertex has not been visited, 
			// then insert vertex inside the visited linked list and enqueue it
			display = display->next;
			while(display != NULL){
				current = Visited, previous = Visited;
				flag = 0;
				while(current != NULL){
					if(current->data == display->data){
						flag = 1;
						break;
					}
					previous = current;
					current = current->next;
				}
				if(!flag){
					current = Head;
					while(current != NULL){
						if(current->data == display->data){
							break;
						}
						current = current->down;
					}
					Node* newnode = current;
					previous->next = new Node(display->data);
					Q.push(newnode);
				}
				display = display->next;
			}
		}
		cout<<"]"<<endl;
	}
	// If start vertex not present in graph
	else cout<<"Start Vertex "<<start<<" Not Found in Graph."<<endl;
}

void Graph::dfs(){
	int start;
	cout<<"Enter the start point for DFS Traversal : ";
	cin>>start;

	// Checking whether start vertex is present in graph or not
	Node *Visited = NULL, *current = Head, *previous = current;
	bool flag = 0;
	while(current != NULL){
		if(current->data == start){
			flag = 1;
			break;
		}
		current = current->down;
	}

	// If start vertex is present in graph
	if(flag){
		// Insert start vertex in Visited Linked List
		Visited = new Node(current->data);

		// Create a stack for DFS
		stack <Node*> S;

		// Insert the start vertex in visited linked list and push in stack
		S.push(current);

		cout<<"DFS traversal is : [ "<<current->data<<" ";
		while(!S.empty()) {
			// Pop a vertex from stack and print it
			Node* display = S.top();
			S.pop();

			// Stack may contain same vertex twice. 
			// So we need to print the popped item only
			// if it is not visited.
			current = Visited, previous = Visited;
			flag = 0;
			while(current != NULL){
				if(current->data == display->data){
					flag = 1;
					break;
				}
				previous = current;
				current = current->next;
			}
			if(!flag){
				cout<<display->data<<" ";
				previous->next = new Node(display->data);
			}

			// Get all adjacent vertices of the popped vertex display
			// If a adjacent vertex has not been visited, then push it to the stack.
			display = display->next;
			while(display != NULL){
				current = Visited;
				flag = 0;
				while(current != NULL){
					if(current->data == display->data){
						flag = 1;
						break;
					}
					current = current->next;
				}
				if(!flag){
					current = Head;
					while(current != NULL){
						if(current->data == display->data){
							break;
						}
						current = current->down;
					}
					Node* newnode = current;
					S.push(newnode);
				}
				display = display->next;
			}
		}
		cout<<"]"<<endl;
	}
	// If start vertex not present in graph
	else cout<<"Start Vertex "<<start<<" Not Found in Graph."<<endl;
}

int main() {

	// Creating Instance of Graph class
	Graph G;

	// Menu for Standard Operations on Dictionary
	while (1)
	{
		cout << "\n1. Insert Vertices." << endl;
		cout << "2. Insert Edges." << endl;
		cout << "3. Display List." << endl;
		cout << "4. BFS Traversal." << endl;
		cout << "5. DFS Traversal." << endl;
		cout << "6. Exit." << endl;

		int choice;
		// Reading choice from user
		cout << "Enter your choice from Above Menu : ";
		cin >> choice;
		cout << endl;

		// Insertion of Vertices in Graph
		if (choice == 1)
		{
			G.insert_vertex();
		}
		// Insertion of Edges in Graph
		else if (choice == 2)
		{
			G.insert_edge();
		}
		// Displaying Adjacency list
		else if (choice == 3)
		{
			G.display_list();
		}
		// BFS Traversal
		else if (choice == 4)
		{
			G.bfs();
		}
		// DFS Traversal
		else if (choice == 5)
		{
			G.dfs();
		}
		// Program Exit
		else if (choice == 6)
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