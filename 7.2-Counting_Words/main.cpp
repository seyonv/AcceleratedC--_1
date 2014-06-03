//7.2 - COUNTING WORDS
//Pair is a simple data structure that holds two elements (first and second)
//Each element in a amap is really a pair, first element contains KEY, second element contains associated VALUE

#include<iostream>
#include<map>
#include<string>

using std::string; using std::map;
using std::cin; using std::cout;
using std::endl;

int main()
{
    string s;
    map<string, int> counters; //store each word an associated counter
    
    //read the input, keeping track of each word and how often we see it & when we encounter a word for the first time,
    //the map automatically creates a new element with that key(value-initialized to 0 for int)
    while (cin >>s)
        ++counters[s];
    
    //output the words and associated counts
    for (map<string,int>::const_iterator it=counters.begin(); it!=counters.end(); ++it)
    {
        //recall the it->first means (*it).first where first and second refer to the attributes string and int respectively
        cout<< it ->first << "\t" << it->second <<endl;
    }
    
    return 0;
}
