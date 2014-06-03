//8.2.7 - Iterator Ranges and off-the-end values
//The convention that algorithms take two arguments to specify ranges is universal
//first refers to the first element. second refers to one PAST the last element
//by doing this, we need only compare iterators for equality/inequaliy and do not need the notion
//of what it means for an iterator to be less than another.
//It also lets us indicate "out of range" and have loops of hte form


while (begin!=end)
{
    //do something with the element to whcih begin refers
    ++begin;
}

//EVERY container type is required to support an off-the-end value for its iterators
