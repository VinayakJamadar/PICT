#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter Hamming Code : ";
    cin>>str;

    int m = str.length(), r = 0, num = 1;

    map<int, string> rn;
    while(num < (m+r+1)){
        rn[num] = "";
        num *= 2;
        r++;
    }

    int len = m+r;
    vector<int> vec(len, 0);

    // Assigning -1 for rn positions
    for (auto &&i : rn)
    {
        vec[len-i.first] = -1;
    }
    
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if(vec[i] == 0) vec[i] = (str[index]-48), index++;
    }

    for (int itr = 0; itr < 2; itr++)
    {
        if (itr) cout<<"\nArray After Finding the Values of Rn's"<<endl;
        else cout<<"\nArray Before Finding the Values of Rn's"<<endl;
        for (int i = 0; i < len; i++)
        {
            if(vec[i] == -1) cout<<"r"<<len-i<<"\t";
            else cout<<vec[i]<<"\t";
        }
        cout<<"\n"<<endl;
        
        for (auto &&i : rn)
        {
            int oneCount = 0;
            for (int j = len-i.first; j >= 0; j-=i.first*2)
            {
                int k = 0;
                while((j-k) >= 0 and k < i.first)
                {
                    if(vec[j-k] != -1){
                        i.second += vec[j-k]+48;
                        if(vec[j-k] == 1) oneCount++;
                    }
                    k++;
                }
            }
            cout<<"r"<<i.first<<" = take "<<i.first<<" and drop "<<i.first<<" = "<<i.second<<" = ";
            if(oneCount%2) {
                cout<<"odd = 1"<<endl;
                i.second = "1";
                vec[len-i.first] = 1;
            }
            else {
                cout<<"even = 0"<<endl;
                i.second = "0";
                vec[len-i.first] = 0;
            }
        }
    }
    
    bool flag = true;
    for (auto &&i : rn)
    {
        if(i.second == "1") flag = false;
    }
    
    cout<<"\nResult : ";
    if(flag) cout<<"Message Transmitted"<<endl;
    else cout<<"Message Not Transmitted"<<endl;
    return 0;
}