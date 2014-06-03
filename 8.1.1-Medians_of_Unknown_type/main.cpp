//8.1.1. - MEDIANS OF UNKNOWN TYPE
//The language feature that implements generic functions is called template function
//Templates allows us to write a SINGLE definition for a family of functions-or types- that behave SIMILARLY
//,except for differences that we can attribute to the types of their template parameters

//Template parameters allow us to write programs in terms of common behavior, even though we do not
//know the specific types that correspond to the template paramaters when we define the template
//We DO know the types when we use a template and that knowledge is available when we compile and link our program

//e.g. before we created a function with the ability to calculate the median of a vector<double>
//but there is no reason to restrict the function to vector<double>. We can take the median of vectors of other types as well
//by using template functions

//says we're defining a template function and that the function will take a "type parameter"
//type paraemters are like function parameters. They define names that can be used within the scope of the function
//however, type parameters refer to types, not variables. Therfore, whenever T appears in the function, the implementation
//will assume that T names a type. When we call median, the implementation will bind T to a type determined during compilation
//E.g. say we call median(vi) where vi is a vector<int> object. The implementation INSTANTIATES our code
//as if we had written a specific version of median that took a vector<int> and returned an int

template <class T>
T median(vector<T> v)
{
    //typename is there to tell the implementation that vector<T>::size_type is the name of a type. (this is a MUST)
    //even though the implementation does not yet know what type T represents
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size==0)
        throw domain_error("median of an empty vector");
    
    sort(v.begin(),v.end());
    vec_sz mid=size/2;
    
    //e.g. when evaluting true case, we have to know the type of v's elements in order to know the types of v[mid] and v[mid-1]
    //These types in turn, determine the type of the + and / operators
    return size % 2==0 ? (v[mid]+v[mid-1])/2 : v[mid];
}