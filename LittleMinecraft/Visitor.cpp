#include "Visitor.h"

Visitor::Visitor() {}

Visitor::~Visitor() {}

// Sheep accept function
void Sheep::accept(Visitor& aVisitor) {
	aVisitor.visitSheep(this);
}

// Cow accept function
void Cow::accept(Visitor& aVisitor) {
	aVisitor.visitCow(this);
}

// Pig accept function
void Pig::accept(Visitor& aVisitor) {
	aVisitor.visitPig(this);
}

