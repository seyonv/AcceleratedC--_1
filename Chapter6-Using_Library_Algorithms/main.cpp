//CHAPTER 6 - USING LIBRARY ALGORITHMS
/*Every container provides companion iterator types that allows us to navigate
 through the container and examine its elements
 In general: can use the ++ operator to advance any type of iterator from one element to the next
 can use the * operator to deference and access the element associated with any type of iterator
 */

//Below two are equivalent
//1)


for (vector<string>::const_iterator it=bottom.begin(); it!=bottom.end(); ++it)
ret.push_back(*it);

//2)
ret.insert(ret.end(), bottom.begin(), bottom.end());

//GENERIC ALGORTIHM - algorithm that is not part of any particular kind of container
//but takes a cure from its arguments' types about how to access the data it uses
//normally they take iterators among their arugments

//E.g. copy algorithm takes three iterators copies all the elements in the range [begin,end) to
//a sequence of elements starting at out and extending as far as necessary
copy(begin, end, out);

//The above is equivalent to
while (begin!=end)
*out++ = *begin++;

//equivalent to

{
    *out = *begin;
    ++out;
    ++begin;
}

//ITERATOR ADAPTORS - function that yield iterators with properties that are related to their arguments in useful ways
//defined in <iterator>
//the most common iterator adaptor is back_inserter

//back_inserter takes a container as its argument and yields an iterator that, when used as a
//destination, appends values to the container
//E.g. back_inserter(ret) is an iterator that, when used as a destination, appends elements to ret

//This copies all of the elements of bottom(from begin to end) and appends them to the end of ret
//third parameter MUST be an iterator and therefore, cannot simply use ret as the 3rd parameter
copy(bottom.begin(), bottom.end(), back_inserter(ret));


