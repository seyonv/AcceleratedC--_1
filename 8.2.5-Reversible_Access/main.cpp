//8.2.5 - Reversible Access
//Some functions need to get at a container's elements in reverse order. The most straightforward
//example of such a function is reverse, which the standard library defines in the <algorithm> header

template <class Bi> void reverse (Bi begin, Bi end)
{
    while (begin!=end)
    {
        --end;
        if (begin!=end)
            swap(*begin++,*end); //equivalent to swap(*begin,*end); *begin++
    }
}

//in this algortihm we march (end), backward from the end of the vector and (beg) forward from the beginning
//exchanging elements as we go
//If a type meets all the requirements of a forward iterator AND it supports --, then it is a BIDIRECTIONAL ITERATOR
