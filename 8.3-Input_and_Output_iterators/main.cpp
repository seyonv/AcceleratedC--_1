//8.3- - Input and Output iterators
//input and output iterators are separate categories from forward iterators as not all iterators are
//associated with containers. For example, if c is a container that supports push_back, then
//back_inserter(c) is an output iterator that meets no other iterator requirements

//The standard library provides iterators that can be bound to input and output streams. (e.g. istream and ostream)
//For input streams, * will yield the value at the current position in the input
//and for output streams, * will let us write to the corresponding ostream

//the input stream iterator is an input-iterator type named istream_iterator
//PROGRAM STARTS HERE

vector<int> v;

//reads ints from the standard input and appends them to v
//second argument creates a default(empty) istream_iterator<int> which is not bound to any file
//any argument that reaches the eof or is in an error state will appear to be equal to the default value
copy(istream_iterator<int>(cin), istream_iterator<int>(),back_inserter(v));

// ** When we read from a stream, we always say the type of value that we expect to read

//for writing, we use the ostream_iterator
copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

