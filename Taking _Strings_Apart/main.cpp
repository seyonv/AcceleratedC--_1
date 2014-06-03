//5.6 - Taking strings apart
//Might want to break a line of input into words, separated by whitespace

//Implement way to read an entire line of input and examine the words within that line
//--Write a function that takes a string and returns a vector<string> which contains entry for each word in inputted string
//function will define two indices(i & j) and we will locate a word by computing
//the vaues of i and j such that the word will be in the range [i,j)
//e.g. string s = "The fox ran". i is pointing at s[0]="T" and j is pointing at s[4]=" "

//in this case, passing by reference not because we need to modify
//but because passing by constant reference takes less memory than passing by value

//This code needs #include<cctype> which defines useful function for processing
//individual characters, including the isspace method


#include <iostream>
#include <ios>
#include <stdexcept>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
#include <algorithm>


using std::string; using std::vector;
using std::cin;    using std::cout;
using std::endl;


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

int main()
{
    string s;
    
    //read and split each line of input
    while (getline(cin,s))
    {
        vector<string> v = split(s);
        //write each word in v
        for (vector<string>::size_type i=0; i!=v.size(); ++i )
            cout<< v[i] <<endl;
    }
    return 0;
}


