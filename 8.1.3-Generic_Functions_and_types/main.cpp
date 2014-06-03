//8.1.3. - Generic Functions and types
//Recall that the difficult part of designing and using templates is understanding the interaction between a template and the
//"appropriate types" that can be used within the template. One type dependency seen is in our definition of the template version
//of median. The types stored in the vectors that are passed to the median function must support addition and division, and these
//operations had better map to their NORMAL arithmetic meanings.

//Other type issues arise in the interactions between templates and type conversions. For example, when we called find
//to check whether students had done all their homework, we wrote

find(s.homework.begin(), s.homework.end(),0);
//in this case, homework is a vector<double> , but we told find to look for an int. But there is no consequence as we cam
//easily compare int and double values. But when we call accumulate...

accumulate(v.begin(),v.end(),0.0)
//we MUST use the double form, as the accumulate function uses the type of the third argument as the type of its accumulator

//When we called max
string::size_type maxlen=0;
maxlen = max(len, name.size());
//we noticed that it is ESSENTIAL that the type of len match exactly the type returned by name.size(), otherwise it won't compile
//Plausible implementation of the max function is shown below

template <class T>
T max(const T& left, const T& right)
{
    return left > right ? left : right;
}

//if we pass an int and a double, the impementation has no way to infer which argument to convert so that they are the same
//Therefore, passing an int and a double will FAIL at compile time