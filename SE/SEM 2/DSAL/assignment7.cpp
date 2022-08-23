// Problem Statement :
// You have a business with several offices; you want to lease phone
// lines to connect them up with each other; and the phone company
// charges different amounts of money to connect different pairs of cities.
// You want a set of lines that connects all your offices with a minimum
// total cost. Solve the problem by suggesting appropriate data structures.

#include <iostream>
#define MAX 20;
#define inf 99999;
using namespace std;

class graph
{
    int cities[100][100];
    int spanning[100][100];
    int size;

public:
    graph()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cities[i][j] = 0;
                spanning[i][j] = 0;
            }
        }
    }

    graph(int m)
    {
        size = m;
    }

    int ret_size()
    {
        return size;
    }

    void add(int x, int y, int w)
    {
        cities[x][y] = w;
        cities[y][x] = w;
        cout << "\nData Added Successfully!!!" << endl;
    }

    void display()
    {
        cout << "\nYour coordinates" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (cities[i][j] != 0)
                {
                    cout << "( " << i << "," << j << " )"
                         << "----->" << cities[i][j] << endl;
                }
            }
        }
    }

    void prims()
    {
        // size = max vertices

        int cost[size][size];
        int u, v, min_distance, distance[size], from[size];
        int visited[size], no_of_edges, min_cost;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (cities[i][j] == 0)
                {
                    cost[i][j] = inf;
                }
                else
                {
                    cost[i][j] = cities[i][j];
                }

                spanning[i][j] = 0;
            }
        }

        distance[0] = 0;
        visited[0] = 1;

        for (int i = 1; i < size; i++)
        {
            distance[i] = cost[0][i];
            from[i] = 0;
            visited[i] = 0;
        }

        min_cost = 0;
        no_of_edges = size - 1;

        while (no_of_edges > 0)
        {
            min_distance = inf;
            for (int i = 1; i < size; i++)
            {
                if (visited[i] == 0 && distance[i] < min_distance)
                {
                    v = i;
                    min_distance = distance[i];
                }
            }

            u = from[v];
            spanning[u][v] = distance[v];
            spanning[v][u] = distance[v];
            no_of_edges--;
            visited[v] = 1;

            for (int i = 1; i < size; i++)
            {
                if (visited[i] == 0 && cost[i][v] < distance[i])
                {
                    distance[i] = cost[i][v];
                    from[i] = v;
                }
            }

            min_cost = min_cost + cost[u][v];
        }

        for (int i = 0; i < size; i++)
        {
            cout << "\nVertex " << i << " : ";
            for (int j = 0; j < size; j++)
            {
                cout << spanning[i][j] << "  ";
            }
        }

        cout << "\nCost is: " << min_cost << endl;
    }
};

int main()
{
    int v;
    cout << "\nHow many vertes are there: ";
    cin >> v;
    graph g(v);
    int choice, td;
    int cnt;
    while (1)
    {
        cout << "\n1.Enter the data \n2.Display Data \n3.Find Shotrest Path \n4.Exit" << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\nHow many data you want to add: ";
            cin >> td;
            cnt = 0;
            while (td != cnt)
            {
                cout << "\nValues should be between 0 and 20" << endl;
                int x, y, w;
                cout << "\nEnter the point as (X) and (Y) respectively." << endl;
                cin >> x >> y;
                if (x != y)
                {
                    if (x < g.ret_size() && y < g.ret_size())
                    {
                        cout << "\nEnter the weight: ";
                        cin >> w;
                        g.add(x, y, w);
                        cnt++;
                    }
                    else
                    {
                        cout << "\nEnter valid points!!!" << endl;
                    }
                }
                else
                {
                    cout << "\nCannot have same source and destination!!!" << endl;
                }
            }
        }
        if (choice == 2)
        {
            g.display();
        }
        if (choice == 3)
        {
            g.prims();
        }
        if (choice == 4)
        {
            break;
        }
    }

    return 0;
}
