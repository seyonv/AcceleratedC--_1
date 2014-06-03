//8.1.2 - Template instantiation
//When we call median on behalf of a vector<int>, the implementation will effectively create and compile an instance of the
//function that replaces every use of T by int
//if we also call median for a vector<double>, then the implemetnation will again infer the types from the call

//For C++ implementations that follow the traditional edit-compile-link mode, instantiation often happens not at compile
//time, but at link time


//If you write your own templates, most current implementations require that in order to instantiate a template, the definition of the
//template, not just the declaration, has to be accessible to the implementation. Generally, this requirement implies access to the
//source files that define the template, as well as the header file
