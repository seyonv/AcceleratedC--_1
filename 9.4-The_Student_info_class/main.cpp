//9.4 - The Student_info class

class Student_info{
public:
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
    
    std::istream& read(std::istream&);
    double grade() const;
    
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

istream& Student_info::read(istream& in)
{
    in>>name>>midterm>>final;
    read_hw(in,homework);
    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm,final, homework);
}

