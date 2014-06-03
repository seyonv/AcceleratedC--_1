
//Finding URLS(Uniform Resource Locators) that are embedded in a string

//Might use a function by creating a single string that holds the entire contents of a document and search for all urls
//URL is a sequence of characters of the form
//protocol-name://resource-name where protocol name consists of only letters and resource name is alphanumeric+special characters

//iterate through, looking for the characters ://, if found then look backward to find protocol-name
//and forward to find the resource-name


vector<string> find_urls(const string& s)
{
    vector<string> ret; //vector into which we store the URL's
    typedef string::const_iterator iter;
    iter b=s.begin(), e = s.end();
    
    //look through the entire input
    while (b!=e)
    {
        //look for one or more letters followed by ://
        b=url_beg(b,e);
        
        //if we found it
        if (b!=e)
        {
            
            //get the rest of the URL
            iter after=url_end(b,e);
            
            //remember the URL
            ret.push_back(string(b,after));
            
            //advance b and check for more URLs on this line
            b = after;
            
        }
        return ret;
    }
    
    //url_beg will be responsible for identifying whether a valid URL is present
    //AFTER the calls to url_beg and url_end the iterator b denotes the beginning o a URL
    //and the iterator after denotes the position one past the last character in the URL
    
    //e.g. randomhttp://www.google.com b=url_beg(b,e) points to the r, and after=url_end(b,e) point to the space after m in com
    //while e= s.end() points to the end of the string and beg points to the h in http
    
    //must then increment the value of b to look for the next URL. Therefore set b to be one past the end of the URL
    //which is where after is
    
    string::const_iteratator
    url_end(string::const_iterator b, string::const_iterator e)
    {
        //stops if it finds an element for which the predicate (not_url_char) yields true
        return find_if(b,e,not_url_char);
        
    }
    bool not_url_char(char c)
    {
        //characters, in addition to alphanumerics, that can appear in a URL
        //local vairables that are declared to be STATIC are preserved across invocations of the function
        //Thus, we will construct and initialize the string url_ch only on the first call to not_url_char
        //all subsequent calls will use the object that the first call created
        static const string url_ch="~;/?:@=&$-+.+!*'(),";
        
        //isalnum(c), defined in <cctype>, returns true if c is an alphanumeric character
        //find looks for the predicate (third argument) within the sequence defined by the first two arguments, iterators))
        //find returns an iterator denoting the first occurence of the value in the given sequence if the value is found
        //if the value is not found, it returns the second argument (in this case url_ch.end() )
        
        //by precedence, != is evaluated before ||
        return !(isalnum(c)|| find(url_ch.begin(),url_ch.end(),c) != url_ch.end()) ;
    }
    
    //For simplicity, assume that one or more letters precede and suceede the :/// separator
    //This functions returns iterator pointing to beginning of valid protocol
    //b is current location to start searching from and e is the absolute endpoint of the string
    string::const_iterator
    url_beg(string::const_iterator b, string::const_iterator e)
    {
        static const string sep="://";
        
        typedef string::const_iterator iter;
        
        //i marks where the separator(://) is found
        iter i=b;
        
        //search takes two pairs of iterators. The first pair denotes the sequence in which we are looking
        //the second pair denotes the sequence that we wish to locate. It returns interator to first occurence if it passes
        //if search fails, it returns the second iterator (which is e).
        while ((i=search(i,e,sep.begin(),sep.end())) != e)
        {
            //Now a separator has been found and must make sure the separator isn't at the beginning or end of the line
            if (i!=b && i+sep.size()!=e)
            {
                ///beg marks the beginning of the protocol name, which is ":"
                iter beg = i;
                
                //make sure the separator isn't at the beginning or end of the line
                while (beg!=b && isalpha(beg[-1]))
                    --beg;
                
                //is there at least one appropriate character before and after the separator
                //i[sep.size()] = *( i+sep.size() )
                
                if (beg!=i && !not_url_char(i[sep.size()]))
                    return beg;
            }
            i+=sep.size();
        }
        return e; //no valid separator found, therefore return e
    }
