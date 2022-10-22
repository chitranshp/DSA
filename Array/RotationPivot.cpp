//https://practice.geeksforgeeks.org/problems/rotation4723/0

class Solution{
public:	
	int findKRotation(int arr[], int n) 
	{
	    int low = 0, high = n - 1, mid;
	    
	    while(low < high)
	    {
	        mid = low + (high - low)/2;
	        
	        if(arr[mid] > arr[high])
	            low = mid + 1;
	        else
	            high = mid;
	    }
	    
	    return low;
	}

};
