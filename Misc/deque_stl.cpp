/* https://www.hackerrank.com/challenges/deque-stl/problem */

#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int i = 0 ,j;
    deque<int> deq(k);
    for( i = 0; i < k ; i++)
    {
        j = 0;
        while(!deq.empty() && arr[i] >= arr[deq.back()])
            deq.pop_back();
        deq.push_back(i);
    }
    for (; i < n; ++i) 
    {
        cout << arr[deq.front()] << " "; 

        while ((!deq.empty()) && deq.front() <= i - k) 
            deq.pop_front();  

        while ((!deq.empty()) && arr[i] >= arr[deq.back()]) 
            deq.pop_back(); 

        deq.push_back(i); 
    }
    cout<< arr[deq.front()]; 
    cout<<"\n";

}

int main(){
  
	int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
