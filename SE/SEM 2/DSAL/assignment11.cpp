#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int *heap, *arr;
    int size;

public:
    Heap()
    {
        size = 0;
        heap = new int(size);
        arr = new int(size);
    }
    void create()
    {
        cout << "Enter size of Heap : ";
        cin >> size;
        heap = new int(size);
        arr = new int(size);

        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i + 1 << " element of heap : ";
            cin >> heap[i];
        }
    }
    void insert()
    {
        size++;
        cout << "Enter " << size << " element of heap : ";
        cin >> heap[size - 1];
    }
    void display_unsorted()
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << "]" << endl;
    }
    void display_sorted()
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
    void sort()
    {
        int run = size, swap;
        for (int i = 0; i < size; i++)
        {
            arr[i] = heap[i];
        }

        while (run)
        {
            // max heapify
            for (int i = 0; i < run/2; i++)
            {
                int left = i * 2 + 1, right = i * 2 + 2;
                if ((left < run) and (arr[i] < arr[left]))
                {
                    swap = arr[left], arr[left] = arr[i], arr[i] = swap;
                }
                if ((right < run) and (arr[i] < arr[right]))
                {
                    swap = arr[right], arr[right] = arr[i], arr[i] = swap;
                }
            }
            cout << "\nMaxheap : ";
            display_sorted();
            cout << endl;
            swap = arr[0];
            arr[0] = arr[run - 1];
            arr[run - 1] = swap;
            cout << "After Swapping : ";
            display_sorted();
            run--;
        }

        cout << "\nHeap Sorted Array : ";
        display_sorted();
    }
};

int main()
{
    Heap hp;
    int choice;

    while (1)
    {
        cout << "\n1.Create Heap - " << endl;
        cout << "2.Insert element in Heap - " << endl;
        cout << "3.Display Heap - " << endl;
        cout << "4.Heap Sort - " << endl;
        cout << "5.Exit - " << endl;

        cout << "\nEnter your Choice : ";
        cin >> choice;

        if (choice == 1) hp.create();
        else if(choice == 2) hp.insert();
        else if (choice == 3) hp.display_unsorted();
        else if (choice == 4) hp.sort();
        else if (choice == 5)
        {
            cout << "\nProgram Exit" << endl;
            break;
        }
        else
        {
            cout << "Enter a valid choice" << endl;
        }
    }

    return 0;
}