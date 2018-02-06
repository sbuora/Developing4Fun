//
//  SimpleHierarchy.hpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Let's see how the deletion applies to virtual function and non virtual function in a class hierarchy
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SimpleHierarchy_hpp
#define SimpleHierarchy_hpp

class SimpleHierarchy_Parent {
public:
    virtual void virtualMethod();
    void memberFunction();
};

class SimpleHierarchy_Inherited : public SimpleHierarchy_Parent {
public:
    // You cannot delete a virtual function
    // virtual void virtualMethod() = delete; // Error: Deleted function 'virtualMethod' cannot override a non-deleted function
    virtual void virtualMethod();
    void memberFunction() = delete;
};

#endif /* SimpleHierarchy_hpp */
