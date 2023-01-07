// https://leetcode.com/problems/gas-station/

class Solution {
public:
    /* This can be solved using brute force method in O(n^2) */
    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int tank = 0, j, cnt, n = gas.size();
        for(int i = 0; i < gas.size(); i++)
        {
            j = i;
            cnt = n;
            while(tank >= 0 && cnt)
            {
                tank = tank + gas[j % n] - cost[j % n];
                j++;
                cnt--;
            }

            if(cnt == 0 && tank >= 0)
                return i;
        }

        return -1;
    }
    */
    /*
    In the brute force solution, we notice few points.
    1. For a path to exist, the toal sum of gas all the stations must be greater then or equal to the overall total cost. 
    2. For two points A and B, if B is the first station A can't reach. Then any station between A and B can't reach B. Therefore, no need to consider those points cannot be the source for our required path.
    Proof:
    A->C1->C2->C3->....->Ck->B
    Let's assume A can't reach B      (i)
    If C3 can reach B and A can reach C3, then this violates our first assumption. Therefore, if A can't reach B(where B is the first node, A can't reach), then any of the nodes in between A and B also can't reach B.
    
    And from A can reach B or not reach B, we mean that on reaching B whether the fuel in tank >= 0 or not. If it is in -ve, then that station can't be reached.
    Therefore, instead of checking all stations, we can just first check whether the solution even exists or not. And secondly we check which is our source station. Since, we are guarranted there exists only one unique path at most.

    With this optimisation, the time complexity comes to O(n) and space complexity comes to O(1).
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int tank = 0, total_surplus_gas = 0, candidate_for_source = 0;
        for(int i = 0; i < cost.size(); i++)
        {
            total_surplus_gas = total_surplus_gas + gas[i] - cost[i];       //To check whether solution exists or not.
            tank = tank + gas[i] - cost[i];
            if(tank < 0)
            {
                tank = 0;                     //Reset tank for next station. Since, next will be treated as source.
                candidate_for_source = i + 1; //No nodes till now cannot be source. So, take next node as candidate for source
            }
        }
    
        return total_surplus_gas < 0? -1: candidate_for_source % gas.size();
    }
};
