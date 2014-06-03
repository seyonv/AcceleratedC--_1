//8.4 - Using Iterators for flexibility
//can improve the split function by generalizing and not specifying input as vector<string>
//can also specfiy split to take an output iterator instead of returning a value.


template <class Out>
void split(const string& str, Out os)
{
    typedef string::const_iterator iter;
    iter i = str.begin();
    
    while (i!=str.end())
    {
        //ignore the leading blanks
        i = find_if(i,str.end(), not_space);
        
        //find the end of next word
        iter j = find_if(i,str.end(),space);
        
        //copy the characters in [i,j)
        if (i!= str.end())
            *os++ = string(i,j); //writes the word we just found and increments os
        
        i=j;
    }
}