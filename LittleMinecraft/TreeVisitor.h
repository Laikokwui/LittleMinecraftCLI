#pragma once

#include <iostream>
#include <string>

template <class T>
class TreeVisitor {
public:
	virtual ~TreeVisitor() {}
	virtual void postOrderVisit(const T& aData) const {}
	virtual void preOrderVisit(const T& aData) const {}
	virtual void inOrderVisit(const T& aData) const {}

	virtual void visit(const T& aData) const {
		std::cout << aData << " ";
	}
};

template <class T>
class PostOrderVisitor : public TreeVisitor<T> {
public:
	virtual void PostOrderVisit(const T& aData) const {
		TreeVisitor<T>::visit(aData);
	}
};

template <class T>
class PreOrderVisitor : public TreeVisitor<T> {
public:
	virtual void PreOrderVisit(const T& aData) const {
		TreeVisitor<T>::visit(aData);
	}
};

template <class T>
class InOrderVisitor : public TreeVisitor<T> {
public:
	virtual void InOrderVisit(const T& aData) const {
		TreeVisitor<T>::visit(aData);
	}
};
