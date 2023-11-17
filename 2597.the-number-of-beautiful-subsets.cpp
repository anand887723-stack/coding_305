class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int counter = 0;
        if (nums.size() == 1)
            return true;

        int count = 0;
        for (int i = n - 1; i >= 1; i--)
        {

            if (i == n - 1)

            {

                if (nums[i] >= nums[i - 1])
                {
                    continue;
                }
                else
                {
                    nums[i] = nums[i - 1];
                    counter++;
                }

                continue;
            }
            if (nums[i] >= nums[i - 1])
            {
                continue;
            }
            else
            {

                if (nums[i] != nums[i + 1])
                {
                    nums[i] = nums[i + 1];

                    if (nums[i] >=nums[i - 1])
                    {
                        counter++;
                        continue;
                    }
                    else
                        return false;
                }
                else
                {

                  
                  nums[i-1]=nums[i];
                }
            }
        }

        return counter <= 1;
    }
};