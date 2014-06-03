//Chapter 8 - Writing Generic functions
//whenever we've written a function so far, we've know the types of the function's paramaters & return value
//However, we used a library function called find, which takes two iterators and a value as arguments
//we can use the same find function to find values of any appropriate type in any kind of container
//THEREFORE, we do NOT know what find's argument or result types will be until we see it.
//Such a function is called a GENERIC FUNCTION. But how do we let someone know whether it will work with particular arguments?

///E.g. If a function has parameters x and y, and computes x+y, then the mere existence of that computation
//implicitly requires that x and y have types for which x+y is defined.

//By its' nature, generic function are abstract. If they were written to solve specific problems, then they
//wouldn't be abstract

