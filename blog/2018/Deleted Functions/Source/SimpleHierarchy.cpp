//
//  SimpleHierarchy.cpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

#include "SimpleHierarchy.hpp"
#include <iostream>

void SimpleHierarchy_Parent::virtualMethod() { std::cout << "base class virtual method" << std::endl; }
void SimpleHierarchy_Parent::memberFunction() { std::cout << "base class member function" << std::endl; }

void SimpleHierarchy_Inherited::virtualMethod() { std::cout << "inherited class virtual method" << std::endl; }

