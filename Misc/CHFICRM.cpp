//https://www.codechef.com/JUNE20B/problems/CHFICRM


#include <iostream>
#include <map>
using namespace std;

int main() {
	int t, n, num;
	int cntfive , cntten;
	bool flag = true;
	scanf("%d", &t);
	while(t--)
	{   
	   flag = true;
	   if(t > 100)
	    t = 100;
	   scanf("%d", &n);
	   if(n > 1000)
	    n = 1000;
	   cntfive = 0;
	   cntten = 0;
	   for(int i = 0; i < n; i++)
	   {
	       scanf("%d", &num);
	       if(num == 5)
	       {
	           cntfive++;
	       }
	       else if(num == 10 && cntfive >= 1)
	       {
	           cntfive--;
	           cntten++;
	       }
	       else if(num == 15)
	       {
	            if(cntten >= 1)
	            {
	                cntten--;
	            }
	            else if(cntfive >= 2)
	            {
	                cntfive = cntfive -2;
	            }
	            else
	            {
	                flag = false;
	            }
	       }
	       else
	       {
	           flag = false;
	       }
	       if(cntfive < 0 or cntten < 0)
	       {
	           flag = false;
	       }
	   }
	   
	   if (flag == true)
	    printf("YES\n");
	   else
	    printf("NO\n");
	}
	return 0;
}