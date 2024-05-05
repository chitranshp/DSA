// https://leetcode.com/problems/compare-version-numbers/description
// Tow pointer approach will have a worst case TC of O(max(m, n))

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m = version1.size(), n = version2.size(), num1, num2;
        int len = max(m, n);
      
        while(i < m || j < n) {
            num1 = 0;
            num2 = 0;
             while(i < m && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while(j < n && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if(num1 < num2) {
                return -1;
            }
            else if(num1 > num2) {
                return 1;
            }
            else {
            // Either we are at end of one or both string OR we are at '.' in one/both string
                i++;
                j++;
            }
        }
        
        return 0;   // Both are equal
    }
};
