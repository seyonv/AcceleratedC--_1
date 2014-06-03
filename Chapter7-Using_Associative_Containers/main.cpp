//CHAPTER 7: USING ASSOCIATIVE CONTAINERS
//sequential containers are elements that remain in the sequence we choose for them
//Write a program that determines whether any element of a container contains the value 42, using sequential containers
//then there are two plausible strategies. 1. Inspect every element until we find 42 or run out of elements
//2. Keep the container in the appropriate order and deviese a fast algorithm (but this is difficult)
//Efficient, easy to implement option is to use associative containers

//Associative container: automatically arrange elements into a sequence
//that depends on the values of the elements themselves rather than the way we inserted them
//key, value format. E.g. If student's name is key, can efficiently find students by name
//for vectors however, the closest thing to a key is the integer index, but this is NOT really a key
//as inserting or deleting an element, not at the end, results in a change of the index

// **(Data structure that stores KEY/VALUE pairs is most common ) - ASSOCIATIVE ARRAY
//most common kind of associative array is a MAP, defined in the <map> header
//similar to vector, but index need not be an integer and may be a string or any other type of value
//on ASSOCIATIVE CONTAINERS, CANNOT use algorithms that change the contents of containers