//8.2.6 - Random Access
// some functions need to be able to jump around in a container, such as the Binary search algortihm


template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const&X x)
{
    while (begin<end)
    {
        //find the midpoint of the range
        Ran mid = begin + (end-begin)/2;
        //see which part of the range contains x; keep looking only in that part
        if (x<*mid)
            end = mid;
        else if (*mid < x)
            begin = mid+1;
        else
            return true; //this means *mid ==x
        
        
    }
    return false;
}

/*this function relies on ability to do arithmetic on iterators
 If p and q are such iterators and n is an integer  then the list of requirements, beyond bidirectional iterators are shown below
 
 p+n,p-n,n+p
 p-q
 p[n](equivalent to *(p+n))
 p<q,p>q,p<=q,p>=q
 
 Then it is a RANDOM ACCESS ITERATOR
 //E.g. The sort function needs Random access iterators. The vector and string iterators are random-access iterators
 
 */
