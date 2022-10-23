//leetcode.com/problems/container-with-most-water



int maxArea(int* height, int heightSize)
{
    int first = 0, last = heightSize - 1;
    int currwater = 0;
    int maxwater = 0;
    
    for(int i = 0; i < heightSize; i++)
    {
        currwater = (last - first) * ((height[first] < height[last])? height[first]: height[last]);
        
        if(currwater > maxwater)
            maxwater = currwater;
        
        if(height[first] < height[last])
            first++;
        else
            last--;
    }
    return maxwater;
}
