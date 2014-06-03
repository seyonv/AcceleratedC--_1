
//*******************************************************************************************************
//7.4 - Generating sentences
//Takes a description of a sentence structure - a grammar- and generates random sentences that
//meet that description. E.g. might describe a sentence as a noun and a verb and an object or noun and a verb, etc.
//E.g. Categories || Rules
//<noun>          || cat
//<noun>          || dog
//<noun-phrase>   || <noun>
//<verb>          || jumps
//<verb>          || runs
//<location>      || on the stairs
//<sentence>      || the <noun-phrase> <verb> <location>

//Program should FIRST find the rule for how to make a sentence & then resolve the first rule it encounters and resolve the rest
//Table containts two kinds of entries: categories, enclosed in <>, and ordinary words. Each category has one or more rules
//each ordinary words simply stands for itself
//Need a map that maps categories to the corresponding rules. Categories are stored as strings, but rules arem ore complex
//category sentence is associated with rule that has 3 categories and one ordinary word
//easiest way to manage multiple instances of the same key is to store each collection of rules in its OWN vector
//THEREFORE, grammar is stored in a map from string to vectors which themselves hold vector<string> (vector<vector<string> >)


#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stdexcept>

using std::string;      using std::map;
using std::cin;         using std::cout;
using std::endl;        using std::vector;
using std::istream;     using std::domain_error;
using std::logic_error;

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


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

int nrand(int n);
void gen_aux(const Grammar& g, const string& word, vector<string>& ret);

Grammar read_grammar(istream& in);
vector<string> gen_sentence(const Grammar& g);
vector<string> gen_sentence(const Grammar& g);
bool bracketed(const string& s);
void gen_aux(const Grammar& g, const string& word, vector<string>& ret);

//selecting a random element using standard libraries rand() function
//which takes no arguments and returns an random integer in the range [0,RAND_MAX), RAND_MAX is fixed largest integer
//must reduce this range to [0,n)

//will partition the available random numbers into n equal-sized buckets, perhaps with some numbers left over
//Then we can computer a random number, figure out which bucket it falls, and return that bucket's number
//function returns a random integer in range [0,n)
int nrand(int n)
{
    if (n<=0||n>RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX/n;
    int r;
    do r=rand()/bucket_size; //integer division truncates the result
    while (r>=n);
    
    return r;
}

//Read from an input stream and return the corresponding grammar (map<string, Rule_collection>)
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;
    
    //read the input
    while (getline(in,line))
    {
        //split the input into words
        vector<string> entry = split(line);
        
        //if entry is empty, then it's a blank line and we disregard it
        if (!entry.empty())
            //CONSTRUCT A NEW, UNNAMED RULE by copying the elements from entry
            //entry[0] is a string(the CATEGORY) and ret[entry[0]] is a Rule_collection(vector<Rule>) which is being appended to
            //push all element from the 2nd to the end, the 1st element is the category
            ret[entry[0]].push_back(Rule (entry.begin()+1, entry.end()) );
    }
    return ret;
};


//Generating the sentence - input will be grammar and output will be vector<string>, the sentence
//must initially find a rule that corresponds to sentence. And will build output in pieces
//not by concatenating them, but by pushing them onto an empty vector using push_back

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g,"<sentence>",ret); //auxillary function that will act as sentence generator
    return ret;
}

//Note that gen_aux will need to determien whether a word represents a category and it will
//do so by checking if ht word has angle brackets around it
bool bracketed(const string& s)
{
    return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
}

//The job of gen_aux is to expand the input string that it is given as its second argument, by looking up that string in the
//grammar that is its first parameter and placing its output into the third parameter (given as ret)

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if(!bracketed(word)){
        ret.push_back(word);
    }
    else
    {
        //locate the rule that corresponds to word
        //cannot use g(word) because if it doesn't exist, it will try to create a newkey
        //and this will crash as grammar is a constant map. g.find(word) looks for the iterator that refers to the element word
        //and if none exist, it returns g.end()
        Grammar::const_iterator it=g.find(word);
        
        //now it points to an element of the map g, which is a pair that can be accessed by dereferencing
        if(it==g.end())
            throw logic_error("empty rule");
        
        //fetch the set of possible rules
        const Rule_collection& c=it->second; //(*it).second - All the rules corresponding to a category are stored here
        
        //from which we select a rule at random. Remember that Rule is vector<string>
        const Rule& r=c[nrand(c.size())];
        
        //recursively expand the selected rule
        for (Rule::const_iterator i=r.begin(); i!=r.end(); ++i)
            gen_aux(g, *i, ret);
    }
    
}



int main()
{
    //generate the sentence. Recall the ret is returned, which is where the words are pushed onto
    vector<string> sentence = gen_sentence(read_grammar(cin));
    
    //write the first word, if any
    vector<string>::const_iterator it=sentence.begin();
    if (!sentence.empty())
    {
        cout<<*it;
        ++it;
    }
    
    //write the rest of the words, each preceded by a space
    while (it!=sentence.end())
    {
        cout<<" "<<*it;
        ++it;
    }
    
    cout<<endl;
    return 0;
}

