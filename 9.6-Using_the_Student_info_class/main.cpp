//9.6 - Using the Student_info class


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;
    
    //read and store data
    while (record.read(cin))
    {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    //alphabetize the student records
    sort(students.begin(), students.end(), compare);
    
    //write the names and grades
    for (vector<Student_info>::size_type i=0;
         i!=students.size(); ++i)
    {
        cout <<students[i].name() //this and the next line changed
        <<string(maxlen+1-students[i].name().size(),' ');
        
        try
        {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) <<final_grade;
            << setprecision(prec) <<end;
        }
        
        catch (domain_error e)
        {
            cout <<e.what() <<endl;
        }
        
        
    }
    return 0;
}
