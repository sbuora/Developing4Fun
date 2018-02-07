#!/bin/bash
mkdir -p ./build
#gcc build
gcc \
./Source/main.cpp \
./Source/ForbidCallWithDifferentTypes.cpp \
./Source/NotCopyableClass.cpp \
./Source/SimpleHierarchy.cpp \
-lstdc++ \
-o ./build/DeletedFunction
#g++ build
g++ \
-std=c++0x \
./Source/main.cpp \
./Source/ForbidCallWithDifferentTypes.cpp \
./Source/NotCopyableClass.cpp \
./Source/SimpleHierarchy.cpp \
-o ./build/DeletedFunction++


