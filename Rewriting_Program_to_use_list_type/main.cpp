//REWRITING PROGRAM TO USE LIST TYPE

//Because the code now uses iterators, we have removed the reliance on indices
//rewrite program using a data structure that deletes elements efficiently within the container

//Lists are slower for random access, but are optimized for fast insertion and deletion ANYWHERE in the container
//however if program only deletes elements from the end, then vectors will outperform lists

//like a vector, the list type is a template and must define the object type
//that a list holds by naming it in angle brackets

//**NOTE: The implementations of ++iter and students.erase() are different if using list or vector
//but they have the same effect


list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter!=students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter=students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

//Lists have their own sort function and we must call it as shown below
list<Student_info> students;

students.sort(compare); //same compare function as for vectors(customize for particular application though)


