#pragma once

#include "Visitor.h"
#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"
#include <iostream>

using namespace std;

class LookVisitor : public Visitor {
public:
    // lookvisitor default constructor
    LookVisitor(); 
    // lookvisitor destructor
    ~LookVisitor();
    // lookvisitor visitCow for look method
    void visitCow(Cow* aCow);
    // lookvisitor visitSheep for look method
    void visitSheep(Sheep* aSheep);
    // lookvisitor visitPig for look method
    void visitPig(Pig* aPig); 
};

