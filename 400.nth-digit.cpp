/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
# define deb(x) cout<<#x<<"="<<x<<endl;
class Solution
{
public:
    vector<long long int> dig;

    int total(long long int num)
    {

        string str = to_string(num);
        int digits = str.size();
        long long int total = 0;
        total += (num - pow(10, digits - 1) + 1) * digits;
        // and then last of them to be preise
        // deb( total);

        if (digits > 1)
            total += dig[digits - 1];
        deb ( total);
        return total;
    }
    bool exclude(long long int mid, long long int n)
    {
        // so here we can check that to exclude this mid complete or not
        if ( n >=total ( mid-1)&& n< total ( mid))return true; 
        else return false;
    }
    int findNthDigit(int n)
    {

        if (n <= 9)
            return n;
        long long int n2= n;
        long long int low = 0;
        long long int high = 1e9;

        for (long long int i = 0; i <= 10; i++)
        {
            if (i == 0)
            {
                long long int curr = (i + 1) * 9LL *(long long int ) pow(10, i);
                dig.push_back(curr);
            }
            else
            {
                long long int curr = (i + 1) * 9LL * (long long int ) pow(10, i);
                curr += dig[i - 1];
                dig.push_back(curr);
            }
        }

        // deb ( dig[8]);
       

        while (high >= low)
        {

            long long int mid = low + (high - low) / 2;
            // deb ( total( mid));
            // deb (n);
            if (total(mid) < n2)
            {

                deb ( 1);
                low = mid + 1;
            }
            else if (total(mid) >n2)
            {

                deb ( 2);
                // then we have to check can we exclude that mid fully or not , before it check if it can be intermediate digit or not
                if (exclude(mid, n2))
                {
                    high = mid - 1;
                }
                else
                {

                    // we have to return the answer
                    int tofind = n2- total ( mid-1);
                    string temp = to_string ( mid);
                    char finder;
                    for ( int  i=0 ; i< tofind; i++)
                    {
                        finder = temp[i];

                    }
                    int x=finder -'0';
                    return x ;
                
                }
            }

            else

            {

                deb ( 3);
                // return the last digit of mid
                return mid % 10;
            }
            deb( "----");
        }


        return 0;

      
    }
};
// @lc code=end
