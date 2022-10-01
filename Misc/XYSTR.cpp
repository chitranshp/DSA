// https://www.codechef.com/JUNE20B/problems/XYSTR

#include <iostream>
using namespace std;

int main()
{
	int cnt = 0, t;
	cin>>t;
	string str;
    while(t--)
    {
        cin>>str;
        cnt = 0;
        for(int i = 0; i < str.size() - 1; i++)
        {
            if(str[i] != str[i+1])
            {
                cnt += 1;
                i++;
            }
        }
        cout<<cnt<<endl;
        str.clear();
    }
	return 0;
}