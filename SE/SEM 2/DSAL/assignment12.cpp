#include <iostream>
#include <fstream>
// #include <stdio.h>
using namespace std;

class student
{
public:
    int roll;
    string division, name, address;
    ifstream fin;
    ofstream fout;
    fstream fm;
    int n;
    char fname[20];

    void create()
    {
        int i;
        student s;
        cout << "Enter the name of file:- ";
        cin >> fname;
        fm.open(fname, ios::out);
        cout << "Enter no. of records:- ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "\nEnter Details of "<<i+1<<"th Student."<<endl;
            cout << "Enter the roll no:- ";
            cin >> s.roll;
            cout << "Enter the name:- ";
            cin >> s.name;
            cout << "Enter division:- ";
            cin >> s.division;
            cout << "Enter address:- ";
            cin >> s.address;
            fm.write((char *)&s, sizeof(s));
        }
        fm.close();
    }
    void display()
    {
        int i;
        student s;
        fin.open(fname);

        for (i = 0; i < n; i++)
        {
            fin.read((char *)&s, sizeof(s));
            cout << "\n"
                    << s.roll << "\t" << s.name << "\t" << s.division << "\t" << s.address;
        }
        fin.close();
        cout<<endl;
    }
    void insert()
    {
        student s1, s2;
        int roll;
        cout << "Enter the Details of Student."<<endl;
        cout << "Enter the roll no:- ";
        cin >> roll;
        int flag = 0;
        fin.open(fname);
        for (int i = 0; i < n; i++)
        {
            fin.read((char *)&s1, sizeof(s1));
            if (s1.roll == roll)
            {
                flag = 1;
                break;
            }
        }
        if (!flag){
            fout.open(fname, ios::app);
            s2.roll = roll;
            cout << "Enter the name:- ";
            cin >> s2.name;
            cout << "Enter the division:- ";
            cin >> s2.division;
            cout << "Enter the address:- ";
            cin >> s2.address;
            fout.write((char *)&s2, sizeof(s2));
            n++;
        }
        else {
            cout<<"This roll no is already present in Records."<<endl;
        }
        fout.close();

    }
    void search(int key)
    {
        student s;
        int flag = 0, i;
        fin.open(fname);
        for (i = 0; i < n; i++)
        {
            fin.read((char *)&s, sizeof(s));
            if (s.roll == key)
            {
                cout << "\nRecord is present their corresponding details are:\nRoll no: ";
                cout << s.roll << "\nName: " << s.name << "\nDivision: " << s.division << "\nAddress: " << s.address;
                flag = 1;
            }
        }
        if (flag == 0)
            cout << "\nRoll no " << key << "is not present in your records";
        fin.close();
    }
    void deletem(int key)
    {

        student s;
        int flag = 0, i;
        fin.open(fname);
        fout.open("temp.txt", ios::out);

        for (i = 0; i < n; i++)
        {
            fin.read((char *)&s, sizeof(s));
            if (s.roll == key)
            {
                cout << "\nRecord deleted successfully";
                flag = 1;
            }
            else
            {
                fout.write((char *)&s, sizeof(s));
            }
        }
        if (flag == 0)
            cout << "\nRoll no " << key << "is not present in the record";
        else
            n--;
        fin.close();
        fout.close();
        remove(fname);
        rename("temp.txt", fname);
    }
};
int main()
{
    int ch, x;
    student obj;

    while (ch != 6)
    {
        cout << "\n***** MENU *****" << endl
                << "\n1.Create\n2.Display\n3.Insert\n4.Search\n5.Delete\n7.Exit\nEnter your choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.insert();
            break;
        case 4:
            cout << "Enter roll no. to search:- ";
            cin >> x;
            obj.search(x);
            break;
        case 5:
            cout << "Enter roll no. to delete:- ";
            cin >> x;
            obj.deletem(x);
            break;
        case 6:
            cout << "Program Exit"<<endl;
            break;
        default:
            cout << "Enter division valid choice....."<<endl;
            break;
        }
    }

    return 0;
}