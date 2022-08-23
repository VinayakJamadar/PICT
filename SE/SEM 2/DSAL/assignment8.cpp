// Problem Statement
// Topological Sorting

#include <queue>
#include <iostream>
using namespace std;


//  Queue Data Structure
template <typename X>
class Queue
{
    class Qnode
    {
        X data;
        Qnode *next;

    public:
        Qnode(X x)
        {
            data = x;
            next = NULL;
        }

        friend class Queue;
    };

    Qnode *front, *rear;
    int cnt;

public:
    Queue()
    {
        cnt = 0;
        front = rear = NULL;
    }

    int empty()
    {
        if (cnt == 0)
        {
            return 0;
        }
        return 1;
    }

    void push(X x)
    {
        Qnode *temp = new Qnode(x);
        if (rear == NULL)
        {
            front = rear = temp;
            cnt++;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            cnt++;
        }
    }

    void pop()
    {
        if (cnt == 0)
        {
            cout << "\nQueue is empty!!!" << endl;
        }
        else
        {
            Qnode *temp = front;
            front = temp->next;
            delete temp;
            cnt--;
        }
    }

    X Front()
    {
        return front->data;
    }

    void display()
    {
        Qnode *temp = front;
        while (temp != nullptr)
        {
            cout << " | " << temp->data << " | ";
            temp = temp->next;
        }
    }
};

class graph
{
    int G[100][100];
    int IND[100];
    int B[100];
    int size;

public:
    graph(int m)
    {
        size = m;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                G[i][j] = 0;
            }
        }
    }

    void insert(int x, int y)
    {
        if (G[y][x] == 0)
        {
            G[x][y] = 1;
        }
        else
        {
            cout << "\nNo cycles in graph" << endl;
        }
    }

    int indegree(int node)
    {
        int in_cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (G[i][node] == 1)
            {
                in_cnt++;
            }
        }
        return in_cnt++;
    }

    void display()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << G[i][j] << "   ";
            }
            cout << endl;
        }
    }

    void top_sort()
    {
        queue<int> q;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            IND[i] = indegree(i);
            if (IND[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            B[j++] = k;

            for (int i = 0; i < size; i++)
            {
                if (G[k][i] == 1)
                {
                    G[k][i] = 0;
                    IND[i] = IND[i] - 1;
                    if (IND[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            cout << B[i] << "  |  ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "\nEnter total vertex in graph: ";
    cin >> size;
    graph g(size);
    int choice;
    while (true)
    {
        cout << "\n1.Add Edges \n2.Display Adjacency Matrix.\n3.Topological Sort" << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int cnt = 0;
            int td;
            cout << "\nHow many edges you want to add : ";
            cin >> td;
            while (td != cnt)
            {
                int x, y;
                cout << "\nEnter the point as source and destination of "<< cnt+1 << " edge : ";
                cin >> x >> y;
                g.insert(x, y);
                cnt++;
            }
        }
        else if (choice == 2)
        {
            g.display();
        }
        else if (choice == 3)
        {
            g.top_sort();
        }
        else if(choice == 4) break;
        else cout<<"Enter a Valid Choice"<<endl;
    }

    return 0;
}
