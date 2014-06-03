//8.2.3 - Sequential write-only access
//Use iterators to write elements of a sequence - Example (copy function)
//PROGRAM STARTS HERE

template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin!=end)
        *dest++ = *begin++; //corresponds to *dest = *begin; ++dest; ++begin;
    return dest;
}

//the function takes three iterators, the first two denote the sequence from which to copy
//and the third denotes the beginning of the destination sequence.
//The function operates by advancing being through the container until it reaches end, copying each
//element into dest as it goes

//Must be able to evaluate *dest=value and dest++. Also, if it is an iterator, then


*it=x;
++it;
++it;
*it=y;

//This is problematic because there is a space in the output sequence and if we wish to use an iterator exculsively for output,
//then there is an implicit requirement that we not execute ++it more than once between assignments
//If a function uses a type in a way that meets these requirements, we call it an OUTPUT ITERATOR


