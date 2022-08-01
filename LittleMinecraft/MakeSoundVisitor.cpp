#include "MakeSoundVisitor.h"

// soundvisitor constructor
MakeSoundVisitor::MakeSoundVisitor() {}

// soundvisitor destructor
MakeSoundVisitor::~MakeSoundVisitor() {}

// soundvisitor visitCow
void MakeSoundVisitor::visitCow(Cow* aCow) {
    cout << "Moo~ - " << aCow->getName() << '\n';
}

// soundvisitor visitSheep
void MakeSoundVisitor::visitSheep(Sheep* aSheep) {
    cout << "Meh~ - " << aSheep->getName() << '\n';
}

// soundvisitor visitPig
void MakeSoundVisitor::visitPig(Pig* aPig) {
    cout << "Oink~ - " << aPig->getName() << '\n';
}

