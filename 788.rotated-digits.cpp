/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution
{
public:
    int rotatedDigits(int n)
    {
        unordered_set<int> digits;
        unordered_set<int> possible;

        for (int i = 0; i <= min(9, n); i++)
        {
            if (i == 1 || i == 8 || i == 0)
            {
                possible.insert(i);
                // no this will go to that type for checking bro
            }
            else if (i == 2 || i == 5 || i == 9 || i == 6)
            {
                digits.insert(i);
            }
        }

        for (int i = 10; i <= n; i++)
        {
            string curr = to_string(i);
            char last = curr.back();
            int lastdig = last - '0';
            int rem = i / 10;


            
            if (lastdig == 2 || lastdig == 5 || lastdig == 9 || lastdig == 6)
            {
                if (possible.find(rem) != possible.end() || digits.find(rem) != digits.end())
                    digits.insert(i);
            }

            else if (lastdig == 0 || lastdig == 1 || lastdig == 8)
            {

                if (digits.find(rem) != digits.end())
                {
                    digits.insert(i)
                }
                else if (possible.find(rem) != possible.end())
                {
                    possible.insert(i);
                }
            }
        }

        return digits.size();

        // we just need to find the psum in general or we can find at last and give the answer
    }
};
// @lc code=end
