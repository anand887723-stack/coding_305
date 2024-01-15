
    void rec( string curr , int index, set<int> & pals, int stop)
    { 
    if ( index>=stop)
    {
          string temp = curr;
         string curr2= curr;
        reverse( curr.begin(), curr.end());
        temp+=curr;
        for ( int i =0 ; i<=9;i++)
        {
            
            string temp2 = curr2;
            temp2+=to_string(i);
           
            
        reverse( curr2.begin(), curr2.end());
        temp2+=curr2;
        pals.insert( stoi(temp2));
            
        }
        pals.insert( stoi(temp));
        return ; 
    }
    if ( index==0)
        for ( int i =1; i<=9;i++)
        {
            rec  ( curr+ to_string (i), index+1 , pals,stop);
        }
    else 
        for ( int i =0 ; i<=9;i++)
        {
            rec  ( curr+ to_string (i), index+1 , pals,stop);
        }

    }