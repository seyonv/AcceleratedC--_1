//9.5 - Constructors

//Constructors are special member functions that define how objects are initialized
//will be synthesized by compile automatically if we do not define any. Constructors have the SAME NAME as the class itself

//1.If an object is of a class type that defines one or more constructors,
//then the appropriate constructor completely controls initialization of objects of that class
//2. If and object is of built-in type, then value-initializing it sets to zero and default initializing it gives it an undefined value
//3. Otherwise, the object can be only of a class type that does NOT define any constructors
//In that case, value- or default- initializing the object value or default initializes each of its data members. This initialization
//process will be recursive if any of the data members is of a class type with its own contructor

//So if we define a local Student_info variable, then the n and homework members will be automatically initialized to the empty string
//and vector respectively. as they are class objects with constructors

//We create two constructors: one that takes no arguments(creates empty Student_info object) and one that initializes it with a record stream


Student_info s;
Student_info s2(cin);

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
}

//DEFAULT CONSTRUCTOR - its' job is to ensure that its object's data members are properly initialized
//between the : and { are constructor initializers which tell the compiler to initialize the given members with the values in parentheses
//n and homework are implictly initialized
Student_info::Student_info(): midterm(0), final(0){}

//When we create a new class object
//1. The implementation allocates memory to hold the object
//2. It initializes the object using initial values as specified in the initializer list (and also those NOT specified in list)
//3. It executes the constructor body

//constructors exist to ensure that objects are created with their data members in a sensible state.

//constructor with arguments (has no explicit initializer so homework and n are initialized by the default constructor)
Student_info::Student_info(istream& is) {read(is);}

