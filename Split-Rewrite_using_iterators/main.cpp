//Rewrite split using iterators



bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}





vector<string> split(const string& str)
{
	vector<string> ret;
	typedef string::const_iterator iter;
    
	iter i=str.begin();
    
	while (i!=str.end())
	{
		//find_if(b, e, p)
		//test each element in [b, e) against the predicate p. Stops when it finds
        //an element for which the predicate yields true
        
		//ignore leading blanks
		i= find_if(i,str.end(), not_space);
        
		//find end of next word
		iter j=find_if(i,str.end(),space);
        
		//copy the characters in [i,j)
		if (i!=j)
		{
			ret.push_back(string(i,j));
			i=j; //start from the whitespace after the word
		}
        
	}
}

