//
//  main.cpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

#include <iostream>
// First Use Case
#include "NotCopyableClass.hpp"
// Second Case
#include "ForbidCallWithDifferentTypes.hpp"
// Test case on a class hierarchy
#include "SimpleHierarchy.hpp"

int main(int argc, const char * argv[]) {
    
    // First use case: avoid unwanted copies of a class instance
        // C99 way
        Old_NotCopyableClass oldNotCopyable;
        NotCopyableClass notCopyable;
    
        //  if uncommented those won't compile
        //Old_NotCopyableClass old2(oldNotCopyable); //Error: Calling a private constructor of class 'Old_NotCopyableClass'
        Old_NotCopyableClass oldNotAssigned;
        //oldNotAssigned = oldNotCopyable;  //Error: 'operator=' is a private member of 'Old_NotCopyableClass'

    // Second case: avoid unwanted C++ standard conversion in order to allow method calls.
        // In that example you can think about a class supposed to work on float only
        // and that want to force code float only due to some hardwarre constraints..
        // the first call to member function Print won't compile due to the deletion of the Print(double) overload
        // e.g: void Print(double d) = delete;
        ForbidCallWithDifferentTypes callWithDifferentTypes;
        //callWithDifferentTypes.Print(34.0);  //Error: Call to deleted member function 'Print'
        callWithDifferentTypes.Print((float)34.0); //that compiles
        callWithDifferentTypes.Print(34.0f);
        //callWithDifferentTypes.Print((double)34.0f); //Error: Call to deleted member function 'Print'

        //  following a post on stackoverflow post https://stackoverflow.com/questions/5513881/meaning-of-delete-after-function-declaration
        // I tested a template solution to forbid all kind of standard conversion if needed
        // it's a more concise way to allow just a type and do not worry about all conversion rules.
        // e.g:     template<typename T> void OnlyInt(T t) = delete;
        callWithDifferentTypes.OnlyInt(12);
        //callWithDifferentTypes.OnlyInt(12.0); // Error: Call to deleted member function 'OnlyInt'
        //callWithDifferentTypes.OnlyInt(12.f); // Error: Call to deleted member function 'OnlyInt'
        //callWithDifferentTypes.OnlyInt(12U); // Error: Call to deleted member function 'OnlyInt'

    //Test case: Deletion of methods in inherited classes
        SimpleHierarchy_Parent base;
        SimpleHierarchy_Inherited inherited;
        SimpleHierarchy_Parent* pbaseToInherited = &inherited;

        base.virtualMethod();
        base.memberFunction();

        inherited.virtualMethod();
        // memberFunction has been deleted, so a call to the function member of the inherited class is forbidden
        //inherited.memberFunction(); // Error: Attempt to use a deleted function

        pbaseToInherited->virtualMethod();
        // that, in any case, is calling the parent version of 'memberFunction' that is still defined.
        pbaseToInherited->memberFunction();
    
    // wait for an int...mainly for VStudio needs (it would close the console before reading it)
    std::cout << "Type an int to end the program: " << std::endl;
    int justAWait;
    std::cin >> justAWait;
    return 0;
}
