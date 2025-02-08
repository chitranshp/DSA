// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

/*
Approach1: Using two maps with ordered set to get min index in O(1)
If the index is already mapped to a number (i.e., if the index exists in the map or collection of numbers):
  Retrieve the previous number stored at the index (previousNumber).
  Remove the current index from the set of indices associated with the previous number in numberToIndices.
  If there are no more indices associated with the previous number, remove the entry for previousNumber in numberToIndices.

Time complexity: O(logn) (erase) per change operation and O(1) per find operation.
SC: O(n) for storing 

NOTE: 
1.  numberToIndex[number].emtpy() OR numberToIndex[number] will insert 'number' in minheap if it was not present originally. 
So, our map will get unnecessarily modified. So, to prevent this from happening prefer find() operation.
2. auto &it = ntoi[number] passes a reference to set - O(1)
   auto it = ntoi[number] creates a new copy of set using copy constructor - O(n)
*/

class NumberContainers {
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndex;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        unordered_map<int, int>::iterator it = indexToNumber.find(index);

        // If there is already some number at that index and that number is the same as number to be inserted
        if(it != indexToNumber.end() && it->second == number)
            return;

        if(it != indexToNumber.end())
        {
            int num = indexToNumber[index];
            numberToIndex[num].erase(index);

            // Ensure, if all indices of a number are replaced with other value then remove number from numberToIndex map
            if(numberToIndex[num].empty() == true)
                numberToIndex.erase(num);
        }

        indexToNumber[index] = number;
        numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        // We can skip checking if the indices set is empty or not as we took care of that it change methdo
        if(numberToIndex.find(number) != numberToIndex.end())
            return *numberToIndex[number].begin();

        return -1;
    }
};

/*
Approach2: Min heap with lazy update
Same as previous approach but instead of set, we can use a min heap priority queue. With set, we can remove index from numberToIndex map at the time of change only.
As any index can be found in O(1). But with pq, only min index can be checked in O(1). So, we don't update the indexes in numberToIndex at the time of change.
We only update indexToNumber and use this to find that any entry in numberToIndex has become stale or not. If it's found to be stale, we remove it and return the next smallest
non-stale index. If none are left, we return -1
TC -
Change: O(logn) for change operation(push in pq) 
Find - 
  Worst-case: O(m log n) (if m stale elements need to be removed)
  Amortized: O(log n) (since each stale element is removed only once)

SC - O(n)
*/

class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndex;
    
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        unordered_map<int, int>::iterator it = indexToNumber.find(index);
        if(it != indexToNumber.end() && it->second == number)
            return;

        indexToNumber[index] = number;
        numberToIndex[number].push(index);
        return;
    }
    
    int find(int number) {
        // Passing reference not copying entire pq
        auto& minheap = numberToIndex[number];   

        // numberToIndex[number].emtpy() will insert 'number' in minheap to check if it's empty or not. So, our map will get unnecessarily modified
        while(!minheap.empty())
        {
            int index = minheap.top();
            if(indexToNumber[index] == number)
                return index;

            minheap.pop();
        }

        return -1;
    }
};
