#pragma once

#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"
#include <iostream>

using namespace std;

class Visitor {
public:
	Visitor();
	~Visitor();
	virtual void visitCow(Cow* aCow) = 0;
	virtual void visitSheep(Sheep* aSheep) = 0;
	virtual void visitPig(Pig* aPig) = 0;
};

