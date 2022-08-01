#pragma once

#include "Visitor.h"
#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"
#include <iostream>

using namespace std;

class MakeSoundVisitor : public Visitor {
public:
    // soundvisitor constructor
    MakeSoundVisitor();
    // soundvisitor destructor
    ~MakeSoundVisitor();
    // soundvisitor visitCow
    void visitCow(Cow* aCow);
    // soundvisitor visitSheep
    void visitSheep(Sheep* aSheep);
    // soundvisitor visitPig
    void visitPig(Pig* aPig);
};

