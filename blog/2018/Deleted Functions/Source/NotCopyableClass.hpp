//
//  NotCopyableClass.hpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    One of the purposes of the deleted functions is to simplify a very old pattern used to avoid an unwanted copy of a class.
//
//    There are different scenarios where you want to avoid a copy of a class:
//    * the class represents (wraps) an operating system resource, like a low-level mutex. A resource that you can create again (a new mutex) but you cannot duplicate.
//    * the class (as a configuration one) is very huge and a copy operation can be truly expensive.
//    * the class belong to a factory, and you want to forbid unwanted uncontrolled copies of the items.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef NotCopyableClass_hpp
#define NotCopyableClass_hpp

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Old pattern (C++99)
//
//    The old way to accomplish it is:
//    1. Make copy constructor private
//    2. Make the assignment operator private
//    3. Do not provide the implementation
//    That said, if a copy of the class is done inside the code it will be detected:
//    * at compile time if the copy is done in function not member or not friend of the class
//    * during the linker phase if the copy is done inside class member function or class friend functions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Old_NotCopyableClass {
public:
    Old_NotCopyableClass() {}
    
    // other class members
    
private:
    Old_NotCopyableClass(const Old_NotCopyableClass& copy);
    Old_NotCopyableClass& operator=(Old_NotCopyableClass& copy);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    New Way (C++11)
//
//    The '= delete' appended to the end of a function declaration sign the function as non-existing, or more properly 'deleted'.
//    The construct allows detecting all the errors related to an unwanted copy of a class at compile time.
//
//    Please remember that all classes by default have a copy constructor and an assignment operator defined. Both simply made a copy of each class data member present in the source class instance to the instance destination of the copy/assignment operation.
//
//    So if you want to avoid unwanted copies, you need to delete the two functions above.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

class NotCopyableClass {
public:
    NotCopyableClass() {}
    NotCopyableClass(const NotCopyableClass& copy) = delete;
    NotCopyableClass& operator=(NotCopyableClass& copy) = delete;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Conclusions:
//    * it's a more concise way to avoid unwanted copies of the class (you don't need to check if the implementation is missing in the cpp counterpart file of the class)
//    * constructor and not allowed operation are declared one close to each other providing a more quick reading.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* NotCopyableClass_hpp */
