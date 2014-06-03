//8.2.4 - Sequential read-write access
//Suppose we want to be able to read and write the elements of a sequence, but only sequentially
//Example of a library function that does so is replace, from the <algorithm> header
//within range beg to end, replace all instances of x with y

template <class For,class X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg!=end)
    {
        if (*beg==x)
            *beg=y;
        ++beg;
    }
}

//FORWARD ITERATOR - and it must support
//*it(for both reading and writing)
//++it and it++ (but not --it or it--)
//it==j and it!=j (where j has the same type as it)
//it->member (as a synonym for (*it).member)

