//8.2.1 - Algorithms and Iterators
/*
 The implementation of the more popular standard-library functions all include iterators
 Some containers support operations that others do not. This support translates into operations
 that some iterators support and others do not. For example, it is possible to access
 an element with a given index directly in a vector, but not in a list.
 Accordingly, if we have an iterator that refers to another element of that same vector, the design of the iterator
 makes it possible to obtain the iterator of that element by simply adding the difference between the elments' indices
 
 ALL ITERATORS USE THE ++ operator to refer to the next element of its container
 
 -Library defines FIVE ITERATOR CATEGORIES, each corresponding to a specific collection of iterator operations
 -Each standard library algorithm SAYS what category it expects for each iterator arguments
 */
