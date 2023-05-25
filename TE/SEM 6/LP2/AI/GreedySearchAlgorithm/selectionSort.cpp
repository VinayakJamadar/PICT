#include <bits/stdc++.h>
using namespace std;

void swaps(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection(int A[], int n) {
    for (int i = 0; i < n; i++)
    {
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[idx] > A[j])
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swaps(&A[i], &A[idx]);
        }
    }
}
void display(int A[], int n)
{
    cout << "\nSorting - ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of Element - ";
    cin >> n;
    int A[n];
    cout << "\nEnter the Elements - \n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Selection(A, n);
    display(A, n);
    return 0;
}