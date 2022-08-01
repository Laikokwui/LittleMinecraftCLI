#include "LookVisitor.h"

// lookvisitor default constructor
LookVisitor::LookVisitor() {}

// lookvisitor destructor
LookVisitor::~LookVisitor() {}

// lookvisitor visitCow for look method
void LookVisitor::visitCow(Cow* aCow) {
    cout << aCow->getName() << " is looking at you!" << '\n';
}

// lookvisitor visitSheep for look method
void LookVisitor::visitSheep(Sheep* aSheep) {
    cout << aSheep->getName() << " is looking at you!" << '\n';
}

// lookvisitor visitPig for look method
void LookVisitor::visitPig(Pig* aPig) {
    cout << aPig->getName() << " is looking at you!" << '\n';
}

