//6.2 - COMPARING GRADING SCHEMES
//Two grading schemes
//1. Average of all homeworks, zero mark for homeworks not turned in
//2. Median of only assignments that the student actually submitted
//Read all the student records, separating the students who did all the homework from the others
//Apply each fo the grading schemes to all the students in each group and report the median grade of each group

//function checkes whether student did all the homework

bool did_all_hw(const Student_info& s)
{
    //recall  that if 0 is not found in the sequence given by the first two iterators, then the 2nd argument is returned
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end())
    
}

vector<Student_info> did, didnt;
Student_info student;

//read all the records, separating them into the corresponding vector, did or didn't
while (read(cin,student))
{
    if (did_all_hw(student))
        did.push_back(student);
        else
            didnt.push_back(student);
            
            }


//check that both groups are non-empty
if (did.empty())
{
    cout<<"No student compeleted all the homework!" <<endl;
    return 1;
    }
    if (didnt.empty())
    {
        cout<<"Every student completed all the homework!"<<endl;
        return 1;
    }
    
    //ANALYZE THE GRADES
    //Three analyses to perform, which each have two parts (analyze both vectors, did and didnt separately)
    //Output routine should take five arguments
    //1. The stream on which to write the output
    //2. A string that represents the name of the analysis
    //3. The function to use for the analysis
    //4 & 5. Two arguments, each of which is one of the vectors that we want to analyze
    //E.g. Assume the fist analysis is done by a function called median_analysis, then would output using the function below
    //write_analysis(cout, "median", median_analysis, did, didnt);
    
    
    
    //the transform function takes three iterators and a function. The first two iterators specify the range to transform
    //The third iterator is the destination into which to put the result of running the function
    //The fourth argument is a function that transform applies to each element of the input sequence
    //to obtain the corresponding element of the output sequence of the output sequence
    
    //back_inserter, which is an iterator adaptor, takes a container as its argument and yields an iterator that, when used as a
    //destination, appends values to the container
    //E.g. back_inserter(ret) is an iterator that, when used as a destination, appends elements to ret
    
    double median_analysis(const vector<Student_info>& students)
    {
        vector<double> grades;
        
        //The function grade is applied to every element in the range students.begin() to students.end()
        //and this is appended to the end of the grades vector
        transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
        
        return median(grades);
    }
    
    //The above transform function may not work because there are several overloaded version of the grade function
    //and because it has no arguments, the compiler doesn't know which one to call.
    //Another problem is that the grade function will throw an exception if any student did no homework at all
    
    //Write an auxillary function to change this
    double grade_aux(const Student_info& s)
    {
        try {
            return grade(s);
        }
        catch (domain_error)
        {
            return grade(s.midterm, s.final, 0);
        }
    }
    
    // ** NOW JUST REPLACE grade in the transform function with grade_aux
    
    //define the write_analysis function
    
    void write_analysis(ostream& out,
                        const string& name,
                        double analysis(const vector<Student_info>&),
                        const vector<Student_info>& did,
                        const vector<Student_info>& didnt)
    {
        out <<name <<" : median(did) = "<<analysis(did)
        <<", median(didnt) = "<<analysis(didnt)<<endl;
        
    }
    
    
    int main()
    {
        //students who did and didn't do their homework
        vector<Student_info> did, didnt;
        
        //read the student records and partition them
        Student_info student;
        while (read(cin,student))
        {
            if (did_all_hw(student))
                did.push_back(student);
            else
                didnt.push_back(student);
            
        }
        
        //verify that the analyses will show us something
        if (did.empty())
        {
            cout<<"No student did all the homework!"<<endl;
            return 1;
            
        }
        if (didnt.empty()
            {
                cout<<"Every student did all the homework!"<<endl;
                return 1;
            }
            
            //do the analyses
            write_analysis(cout, "median",median_analysis, did, didnt);
            write_analysis(cout, "average",aveage_analysis, did, didnt);
            write_analysis(cout, "median of homework turned in",optimistic_median_analysis, did, didnt);
            
            return 0;
            }
            
            
            //Write the average function to use for average_analysis
            double average(const vector<double>& v)
            {
                //accumulate is defined in the <numeric> library
                //The accumulate function adds the values in range denoted by the first two arguments, starting with the
                //the value given by the third argument (which also gives the resulting type, e.g. 0.0 will make accumulate return a double
                return accumulate(v.begin(),v.end(),0.0)/v.size();
            }
            
            double average_grade(const Student_info& s)
            {
                return grade(s.midterm,s.final, average(s.homework))
            }
            
            double average_analysis(const vector<Student_info>& students)
            {
                vector<double> grades;
                
                //recall that tranform applies the average_grade function to every element between students.begin() and students.end()
                //and appends this to the end of the grade vector (which is where the iterator returned by back_inserter(grades) points to
                transform(students.begin(), students.end(),
                          back_inserter(grades), average_grade);
                
                return median(grades);
            }
            
            //Calculating optimistic_median_analysis(median of homework's turned in (nonzero homework's)
            double optimistic_median(const Student_info& s)
            {
                vector<double> nonzero;
                //extracts nonzero vectors from the homework vector and appends them to  (vector<double> nonzero)
                remove_copy(s.homework.begin(), s.homework.end(),
                            back_inserter(nonzero),0);
                
                if (nonzero.empty())
                    return grade(s.midterm,s.final,0);
                else
                    return grade(s.midterm, s.final,median(nonzero));
            }
            
            
            //two-pass solution
            vector<Student_info>
            extract_fails(vector<Student_info>& students)
            {
                vector<Student_info> fail;
                //remove_copy_if uses the predicate as a test and calls the function, which will then return true or false
                //and if it returns true, then the element will be "removed", meaning appended to the fail vector
                remove_copy_if(students.begin(), students.end(),
                               back_inserter(fail),pgrade);
                
                //"remove" elements corresponding to failing grades
                //what remove_if does is it copies elements that do NOT satisfy the predicate(passing grades)
                //to the beginning of the sequence and it returns an iterator that refers to one past the last
                //element that it did NOT "remove"
                //E.g. [p,p,f,f,p,f,p] -> [p,p,p,p,p,f,p] and return_if points to the fifth p while students.end() points
                //to the space after the last p
                //RESULT, afters students.erase. is only passing records
                students.erase(remove_if(students.begin(), students.end(),
                                         fgrade), students.end());
                return fail;
            }
            
            bool pgrade(const Student_info& s)
            {
                return !fgrade(s);
            }
            
            //SINGLE-PASS SOLUTION (For large inputs, this solution is essentially TWICE as fast as the double-pass one)
            //The previous solution calculates the grade for every element in students twice, once from remove_copy_if
            //and once from remove_copy
            //The algorithm partition takes a sequence and rearranges its elements so that the ones that satisfy a predicate PRECEDE
            //the ones that don't satisfy it. It returns an iterator pointing to the first element that fails the predicate
            
            //However MUST use stable_partition which keeps the same order within each half(e.g. alphabetic arrangement)
            
            vector<Student_info>
            extract_fails(vector<Student_info>& students)
            {
                vector<Student_info>::iterator iter=stable_partition(students.begin(),students.end(),pgrade);
                vector<Student_info> fail(iter,students.end()); //vector consisting of all failing elements
                
                students.erase(iter,students.end());
                return fail;
            }