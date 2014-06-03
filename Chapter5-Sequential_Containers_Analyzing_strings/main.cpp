//CHAPTER 5 - USING SEQUENTIAL CONTAINERS AND ANALYZING STRINGS
//want to know if students have failed a course. Therefore, we want to extrac the data from the student_info vector
//and store it in a new vector. Also want to remove the data from the original vector so it onlt
//contains information of students who have passed and push it onto another vector


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

//Inferior implementation
//There are two records of each student record
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    Vector<Student_info> pass, fail;
    
    for(vector<Student_info>::size_type i=0; i<!=students.size(); ++i)
        if (fgrade(students[i]))
            fail.push_back(students[i]));
        else
            pass.push_back(students[i]));
    
    students = pass;
    return fail;
    
    
}


//In order to solve this problem of using extra memory
//one way is to eliminate pass entirely and just use a single local variable named fail
//As we go through the original Student_info vector, will remove it if its a failing grade
//and keep it if it's a passing grade

//NOTE*: Regardless of the solution below, there is still a problem of run time
//which is O(N^2)
//Vectors are optimized for fast random access but it is expensive to insert or delete elements
//that are NOT at the end of a vector

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i=0;
    
    //it would be incorrect to do size = students.size() and then i!=size
    //because this size would remain constant even as records are being deleted
    //therefore. must constantly reevaluate the size of the students vector
    //
    while (i!=students.size())
    {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin()+i);
        }
        else
            ++i;
        
        //important to note that if a failing grade is encountered
        //you don't increment i as the element would be erased and everything pushed bacl
    }
    
    return fail; //return vector<Student_info> fail
}

//ITERATORS (most obvious form of an iterator is a pointer)
//Look at the container operations that extract_fails actually uses
//First, it uses the index i to fetch values from the students vector (accesses it sequentially)
//iterator is a value that
//1. identifies a container and an element in the container
//2.lets us examine the value stored in that element
//3. provides operations for moving between elements in the container
//4.Restricts the available operations in ways that correspond to twhat the container can handle efficiently



//Using index for iteration
for (vector<Student_info>::size_type i=0; i!=students.size(); ++i)
cout<<students[i].name <<endl;

//Equivalent way using iterators
for (vectir<Student_info>::const_iterator iter = students.begin(); iter!=students.end(); ++iter)
{
    //the parentheses are needed to override normal operator precedence
    //(*iter).name is equal to iter -> name
    cout <<iter->name <<endl;
}

//Every standard container, like vector, defines two associated iterator types
//container-type is the container type like vector<Student_info>
//1. container-type::const_iterator (use if you only need read access)
//2. container-type::iterator (use if you want to change the value stored in the container)

// **students.begin() and students.end() return a value of the ITERATOR type

//reimplement extract_fails function using iterators

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter= students.begin(); //type is iterator as we want to modify students
    while(iter!=students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter=students.erase(iter);
            
            //calling erase invalidates every iterator after the pointer erased including students.end()
            //erase returns an interator positioned on an element that follows the one erased
        }
        else
            +iter;
    }
    
    return fail;
}

//erasing or inserting an element from a vector that is not at the end is costly
//because every element after it must be moved backward/forward
