/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{

    bool rec(vector<vector<char>> &board, vector<vector<bool>> &visited,string & word, pair<int, int> start, string  &  curr)

    {

        if (curr != word.substr(0, curr.size()))
            return false;

        if (curr == word)
            return true;
        if ( start.first==board.size()||start.first<0||start.second<0||start.second==board[0].size())return curr==word ;
      
        if ( curr != word.substr( 0 , curr.size()))return false;
        if (visited[start.first][start.second])
            return false ;

       
        visited [ start.first][start.second]=true ;


    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    for ( auto i : dir)
      {
       string temp=curr  ; 
       temp+=board[start.first][start.second];
            if (rec(board, visited, word, {start.first + i.first, start.second + i.second}, temp))
                return true;
                temp.pop_back();
      }

        visited[start.first][start.second] = false;

        return false ; 
    }
public:
    bool exist(vector<vector<char>> &board, string & word)
    {
        int row =board.size();
        int col = board[0].size();

        string curr = "";
        for ( int i =0  ; i < row;i++)
            for  ( int j=0 ;j < col;j++)
               { vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

                if (  rec(board, visited, word, {i,j}, curr))return true;}
        return false;
    }
};
// @lc code=end
