// https://www.codechef.com/JUNE20B/problems/PRICECON

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, n, clip, temp, loss ;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>clip;
	    loss = 0;
	    for(int i = 0; i < n; i++)
	    {
	        cin>>temp;
	        if (temp > clip)
	        {
	            loss = loss + temp - clip;
	            temp = temp - clip;
	        }
	    }
	    cout<<loss<<endl;
	 }
	return 0;
}