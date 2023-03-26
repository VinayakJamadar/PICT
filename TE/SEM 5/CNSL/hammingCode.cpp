#include<bits/stdc++.h>
using namespace std;

void calculateRnValues(map<int, string>& rn, vector<int>& vec, int& len){
	for (int i = 0; i < len; i++){
		if(vec[i] == -1) cout<<"r"<<len-i<<"\t";
		else cout<<vec[i]<<"\t";
	}
	cout<<"\n"<<endl;
	map<int, string>::iterator itr;
	for (itr = rn.begin(); itr != rn.end(); itr++)
	{
		int oneCount = 0;
		itr->second = "";
		for (int j = len-itr->first; j >= 0; j-=itr->first*2)
		{
			int k = 0;
			while((j-k) >= 0 and k < itr->first)
			{
				if(vec[j-k] != -1){
					itr->second += vec[j-k]+48;
					if(vec[j-k] == 1) oneCount++;
				}
				k++;
			}
		}
		cout<<"r"<<itr->first<<" = take "<<itr->first<<" and drop "<<itr->first<<" = "<<itr->second<<" = ";
		if(oneCount%2) {
			cout<<"odd = 1"<<endl;
			itr->second = "1";
			vec[len-itr->first] = 1;
		}
		else {
			cout<<"even = 0"<<endl;
			itr->second = "0";
			vec[len-itr->first] = 0;
		}
	}
}

int main(){
	// Reading Hamming Code
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
    map<int, string>::iterator i;
    for (i = rn.begin(); i != rn.end(); i++)
    {
        vec[len-i->first] = -1;
    }

    int index = 0;
    for (int j = 0; j < len; j++)
    {
        if(vec[j] == 0) vec[j] = (str[index]-48), index++;
    }

    cout<<"\nArray Before Finding the Values of Rn's"<<endl;
    calculateRnValues(rn, vec, len);
    cout<<"\nArray After Finding the Values of Rn's"<<endl;
    calculateRnValues(rn, vec, len);

    // Checking whether all the rn values are 0 (i.e Even) or not
    bool flag = true;
    for (i = rn.begin(); i != rn.end(); i++)
    {
        if(i->second == "1") flag = false;
    }

    // If all the rn values are 0 --> then Data is Transmitted
    // Else --> then Data is Not Transmitted
    cout<<"\nResult : ";
    if(flag) cout<<"Data is Transmitted"<<endl;
    else cout<<"Data is Not Transmitted"<<endl;
    return 0;
}