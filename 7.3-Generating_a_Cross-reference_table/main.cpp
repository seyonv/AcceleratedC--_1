//7.3 -Generating a Cross-reference table
//This table indiciates where each word occurs in the input
//Changes are that now, instead of reading a word at a time, we'll read a line at a time
//and associate line number with words as well as break each line into its constituent word
//INSTEAD of using split directly,  will use it as a parameter  to the cross reference function
//e.g. could pass find_url to the cross-reference function to see where URLS appear in the input


//As before, will uses map with keys(distinct words from input) but values are a set of vectors that track line numbers
//on which each word appears. Therefore, we map from string to vector<int>


#include<iostream>
#include<map>
#include<vector>
#include<string>

using std::string; using std::map;
using std::cin;    using std::cout;
using std::endl;   using std::vector;
using std::istream;

vector<string> split(const string& s)
{
    vector<string> ret; //ret is the vector of strings that is being returned
    typedef string::size_type string_size; //string_size is a synonym for string::size_type
    string_size i=0;
    
    //invariant: we have processed characters [original value of i, i)
    while (i!=s.size())
    {
        //characters in range are all spaces (could be more than one space in a row)
        while (i!=s.size() && isspace(s[i]))
            ++i;
        
        //find end of next word
        //make j skip over to start of next word
        string_size j=i;
        
        //invariant: none of the characters in range [original j, current j) is a space
        while (j!=s.size() && !isspace(s[j]))
            ++j;
        
        //if we found some nonwhitespace characters
        if (i!=j)
        {
            //copy from s starting at i and taking j-1 chars
            ret.push_back(s.substr(i,j-1));
            i=j; //start from the first whitespace after the word
        }
    }
    return ret;
}

//must write vector<int> > and not >> because the compiler needs that space
//find_words defines a function parameter which captures ouur intent to pass to xref, the function to use to split the input into words
//saying "=split" means that we have a DEFAULT ARGUMENT and callers can omit this parameter. If they include it, it is overwritten
//e.g. If the user calls xref(cin), then split is used to find words. If the user calls xref(cin,find_urls) then find_urls is used
//to find words

//parameters are input stream and function used to split the input into words
//CREATE AND RETURN A MAP OF ALL WORDS AND THE CORRESPONDING LINE NUMBERS THEY APPEAR ON
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    
    //read the next line - get line reads from in and stores in line until the delim character or newline character ("\n") is found
    while (getline(in,line))
    {
        ++line_number;
        //break the input lint into words, presumably when given a string, the find_words function does this and returns vector<string>
        vector<string> words = find_words(line);
        
        //remember that each word occurs on the current line
        //iterator it denotes an element of words, and so *it is one of the words in the input line and we use this word to index
        //our map. The value is a vector<int> which holds the line numbers on which this word has appeared so far
        for (vector<string>::const_iterator it=words.begin(); it!= words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    
    return ret;
    
};
//when we insert a new string key into the map (value-initialization), it will be associated with
//an empty vector<int>. The call to push_back will append the current line number to this initially empty vector

int main()
{
    //call xref using split by default
    map<string, vector<int> > ret = xref(cin);
    
    //write the results
    for (map<string, vector<int> >::const_iterator it=ret.begin(); it!=ret.end(); ++it)
    {
        //write the wrod
        cout<<it->first<<" occurs on line(s): ";
        
        //followed by the corresponding line numbers
        vector<int>::const_iterator line_it = it ->second.begin();
        cout<<*line_it; //write the first line numebr
        
        ++line_it;
        //write the rest of the line numbers, if any
        while (line_it!=it->second.end())
        {
            cout<<", "<<*line_it;
            ++line_it;
        }
        
        //write a new line to separate each word from the next
        cout <<endl;
        
    }
    return 0;
}
