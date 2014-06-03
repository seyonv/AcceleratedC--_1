//COMPILATION OF A C++ PROGRAM
/*Steps: 1. Preprocessing, 2. Compilation, 3. Linking
 1.Preprocessing ( the preprocessor takes a c++ source code file and deals with the #includes, #defines and other
 preprocessor directives.
 
 -It works on one C++ source file (.cpp) at a time by  replacing #include directives with the content of their
 respective files, doing replacement of macros (#define), etc.
 -it works on a stream of preprocessing tokens, and macro substitution is defined as replacing tokens by other tokens
 -After all this, it produces a single output that is a stream of tokens resulting from the transformation described above
 -It also adds some special markers that tell the compiler where each line came in from so that it can use those to produce
 sensible error messages
 
 2. Compilation (compiler takes the preprocessor's output and produces a single object file from it)
 
 -compilation step is performed on each output of the preprocessor and involves parsing the C++ source code
 and producing a single object file. This object file contains the compiled code(in binary form) of the symbols
 defined in the input. Symbols in object files are referred to by name
 
 -also calls assembler before converting to object file
 
 -object files can refer to symbols that are not defined. This is the case when you use a declaration and don't
 provide a definition for it. The compiler doesn't mind this and will happily produce the object file as long as the
 source code is well-formed
 
 -At this point, compilers usually let you stop compilation. This is useful as you compile files individually
 and if you change one file, you do NOT need to recompile everything
 
 -The produced object files can be put in special archives called static libraries, for easier reusing later on
 and at THIS stage, '"regular" compiler errors are  reported
 
 3. Linking(the linker takes the object files produced by the compiler and produces either a library or an executable file
 
 -The linker is what produces the final compilation output from the object files the compiler produced. This output can either
 be a shared(or dynamic) library or an executable
 -It links all the object files by replacing the references to undefined symbols contained within them with the correct addresses
 Each of these symbols can be defined in other object files or in libraries. If they are defined in libraries other than the
 standard library, than you need to tell the linker about them.
 -At this stage, the most common errors are missing definitions or duplicate definitions. The former means that either the
 definitions don't exist(i.e. they are not written), or that the object files or libraries where they reside were not given
 to the linker
 */