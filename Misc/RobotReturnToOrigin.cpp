// https://leetcode.com/problems/robot-return-to-origin/description/ 

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        
        for(int c = 0; c < moves.size(); c++)
        {
            switch(moves[c])
            {
                case 'L':
                    j--;
                    break;
                case 'R':
                    j++;
                    break;
                case 'U':
                    i--;
                    break;
                case 'D':
                    i++;
                    break;
            }
        }

        return i == 0 && j == 0;
    }
};