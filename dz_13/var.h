#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 80

using namespace std;

class var
{
	char* value = nullptr;
	int len = 0;

	bool isStr(const var& i);
	int lenDef(const char* str);
	void set(const char* str);
	void clear();

public:
	var();
	var(int val);
	var(double val);
	var(const char* val);
	var(const var& val);
	
	friend ostream& operator<< (ostream& out, const var& obj);

	char operator[] (int i) const;

	operator int () const;
	operator double () const;
	operator char* () const;

	var operator= (int val);
	var operator= (double val);
	var operator= (const char* val);
	var operator= (const var& val);

	var operator+ (int val);
	var operator+ (double val);
	var operator+ (const char* val);
	var operator+ (const var& val);

	var operator- (int val);
	var operator- (double val);
	var operator- (const var& val);

	var operator+= (int val);
	var operator+= (double val);
	var operator+= (const char* val);
	var operator+= (const var& val);

	var operator-= (int val);
	var operator-= (double val);
	var operator-= (const var& val);

	var operator* (int val);
	var operator* (double val);
	var operator* (const char* val);
	var operator* (const var& val);

	var operator/ (int val);
	var operator/ (double val);
	var operator/ (const char* val);
	var operator/ (const var& val);

	var operator*= (int val);
	var operator*= (double val);
	var operator*= (const char* val);
	var operator*= (const var& val);

	var operator/= (int val);
	var operator/= (double val);
	var operator/= (const char* val);
	var operator/= (const var& val);

	bool operator> (int val);
	bool operator> (double val);
	bool operator> (const char* val);
	bool operator> (const var& val);

	bool operator< (int val);
	bool operator< (double val);
	bool operator< (const char* val);
	bool operator< (const var& val);

	bool operator<= (int val);
	bool operator<= (double val);
	bool operator<= (const char* val);
	bool operator<= (const var& val);

	bool operator>= (int val);
	bool operator>= (double val);
	bool operator>= (const char* val);
	bool operator>= (const var& val);

	bool operator== (int val);
	bool operator== (double val);
	bool operator== (const char* val);
	bool operator== (const var& val) const;

	bool operator!= (int val);
	bool operator!= (double val);
	bool operator!= (const char* val);
	bool operator!= (const var& val) const;
};

