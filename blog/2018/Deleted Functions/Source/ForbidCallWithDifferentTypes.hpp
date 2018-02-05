//
//  ForbidCallWithDifferentTypes.hpp
//  DeletedFunctions
//
//  Created by Stefano on 05/02/2018.
//  Copyright © 2018 Developing4Fun. All rights reserved.
//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Another use case of the Function deletion is to avoid automatic cast during member function invocation
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ForbidCallWithDifferentTypes_hpp
#define ForbidCallWithDifferentTypes_hpp

class ForbidCallWithDifferentTypes {
public:
    void Print(double d) = delete;
    void Print(float f);
    // commented out, code left for your test
    // void Print(int i);
};

#endif /* ForbidCallWithDifferentTypes_hpp */
