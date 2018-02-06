//
//  ForbidCallWithDifferentTypes.cpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

#include "ForbidCallWithDifferentTypes.hpp"
#include <iostream>

void ForbidCallWithDifferentTypes::Print(float f) {
    std::cout << "float: " << f << std::endl;
}

// code left for reader tests
//void ForbidCallWithDifferentTypes::Print(int i) {
//    std::cout << "integer: " << i << std::endl;
//}

void ForbidCallWithDifferentTypes::OnlyInt(int i) {
    std::cout << "only Int: " << i << std::endl;
}

