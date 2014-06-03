//Palindromes - determine whether a word is a palindrome

bool is_palindrome(const string& s)
{
    //rbegin returns an interator that starts with the last element in the container
    //equal function compares two sequencs to determine whether they contatin equal values
    //the first two iterators specify the first sequence and the third iterator
    //specifies the starting point of the second sequence. It is assumed that the
    //sequences are the same size, so no fourth parameter is needed
    
    return equal(s.begin(), s.end(), s.rbegin());
    //will compare first character in s with last character in s and will move inwards and compare again
}