/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary
{
public:
    vector<unordered_set<string>> words;
    WordDictionary()
    {

        words.resize(26);
    }

    void addWord(string word)
    {
        // here we are adding the string in the length of ther array
        int len = word.size();
        words[len].insert(word);
    }

    bool search(string word)
    {

        
        // first calculating the number of dots and the position of the dots in the string 
        // and making the cases for it 
        int firstdot = -1, seconddot = -1;
        bool onedot = false;
        int counter = 0;

        // using one for loop to find the index and count of dots
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                if (onedot == false)
                {
                    firstdot = i;
                    onedot = true;
                    counter++;
                }

                else
                {
                    seconddot = i;
                    counter++;
                    break;
                }
            }
        }



        int len = word.size();

        // if the number of dots is zero , we can just find in our data structrue , if the 
        // string is present or not 
        if (counter == 0)
        {

            if (words[len].find(word) != words[len].end())
                return true;
        }

        // if the number of dots is 1 , then we can generate the 26 different possibilities of that string 
        // and check if it is present in our data structure which will take of  o( 26) time
        else if (counter == 1)
        {

            for (char i = 'a'; i <= 'z'; i++)
            {
                word[firstdot] = i;
                if (words[len].find(word) != words[len].end())
                    return true;
            }
        }

        // if the numeber of dots is 2 , then we can use 2 for loops to generate all the possible strings 
        // that can be formed from replacing these dots and then check the string in our data structure which will  
        // take total of o ( 26*26) time 
        else
        {

            for (char i = 'a'; i <= 'z'; i++)
            {
                word[firstdot] = i;

                for (int j = 'a'; j <= 'z'; j++)
                {
                    word[seconddot] = j;
                    if (words[len].find(word) != words[len].end())
                        return true;
                }
            }
        }

        // if all three possiblities failed then we return false

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
