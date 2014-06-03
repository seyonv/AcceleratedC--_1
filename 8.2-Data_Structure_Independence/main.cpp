//8.2 - Data Structure Independence
//The median function implemented above generalizes across types that a vector may contain
//but we may want the function to deal with values stored in ANY kind of data structure, like a list or a string
//ALSO, we would like to be able to act on part of a container as opposed to having to use the whole container
//--For example ,the standard library uses iterators to allow us to call find on any contigious part of any container

//find(c.begin(),c.end(),val);

//why are we not allowed to say c.find(val) though?
//this would meann that we're calling find as a member of whatever type c has and that the type of c would have to define
//find as a member.

//A subtle reason for generic functions to take iterator arguments instead of container arguments directly is that it's
//possible for iterators to access elemetns that aren't in the container at all, in the ordinary sense
//E.g. rbegin function yields an iterator that grants access to the passed container's elments in reverse order