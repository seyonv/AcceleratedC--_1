//*******************************************************************************************************
//8.2.2 - Sequential read-only access
//implement find. Result is either first iterator iter, whose corresponding element is x (*iter==x) or end if no such iterator exists

template <class In, class X>
In find(In begin, IN end, const X&x)
{
    while (begin!=end && *begin!=x)
        ++begin;
    return begin;
}


//alternative implementation of find
template <class In, class X> In find(In begin, In end, const X&x)
{
    if (begin==end||*begin==x)
        return begin;
    begin++;
    return find(begin,end,x);
}

//CONCLUSION - an iterator that offers sequential read-only access to elements of a sequence
//should support ++ (both prefix and postfix), ==, !=, and unary *
//There is one operator that such an iterator ought to support and that is ->, (e.g. iter->member equals (*iter).member)
//if a type supports all these operations, it is called an INPUT ITERATOR