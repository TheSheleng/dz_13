#include "var.h"

bool var::isStr(const var& i)
{
	char buffer[BUFFER_SIZE + 1];
	snprintf(buffer, sizeof(buffer), "%g", atof(i));

	if (lenDef(i) != lenDef(buffer)) return true;
	else return false;
}

int var::lenDef(const char* str)
{
	int len = 0;
	while (str[len]) len++;
	return len;
}

void var::set(const char* str)
{
	clear();

	len = lenDef(str);
	value = new char[len + 1];

	for (int i = 0; i <= len; i++)
		value[i] = str[i];
}

void var::clear()
{
	if (value != nullptr)
	{
		delete[] value;
		value = nullptr;
		len = 0;
	}
}

var::var()
{
	set("0");
}

var::var(int val)
{
	*this = val;
}

var::var(double val)
{
	*this = val;
}

var::var(const char* val)
{
	set(val);
}

var::var(const var& val)
{
	set(val);
}

char var::operator[](int i) const
{
	return value[i];
}

var::operator int() const
{
	return atoi(value);
}

var::operator double() const
{
	return atof(value);
}

var::operator char* () const
{
	return value;
}

var var::operator=(int val)
{
	char buffer[BUFFER_SIZE + 1];
	snprintf(buffer, sizeof(buffer), "%i", val);
	*this = buffer;

	return *this;
}

var var::operator=(double val)
{
	char buffer[BUFFER_SIZE + 1];
	snprintf(buffer, sizeof(buffer), "%g", val);
	*this = buffer;

	return *this;
}

var var::operator=(const char* val)
{
	set(val);

	return *this;
}

var var::operator=(const var& val)
{
	if (*this != val) set(val);
	return *this;
}

var var::operator+(int val)
{
	return var(atoi(*this) + val);
}

var var::operator+(double val)
{
	return var(atof(*this) + val);
}

var var::operator+(const char* val)
{
	char* arr = new char[len + lenDef(val) + 1];

	for (int i = 0; i < len; i++)
		arr[i] = value[i];
	for (int i = 0; i <= lenDef(val); i++)
		arr[i + len] = val[i];

	var temp = arr;
	delete[] arr;
	return temp;
}

var var::operator+(const var& val)
{
	if (isStr(*this) || isStr(val)) return var(*this + (char*)val);
	else return var(*this + (double)val);
}

var var::operator-(int val)
{
	return var(atoi(*this) - val);
}

var var::operator-(double val)
{
	return var(atoi(*this) - val);
}

var var::operator-(const var& val)
{
	return var(*this - (double)val);
}

var var::operator+=(int val)
{
	set(var(atoi(*this) + val));
	return *this;
}

var var::operator+=(double val)
{
	set(var(atof(*this) + val));
	return *this;
}

var var::operator+=(const char* val)
{
	set(*this + val);
	return *this;
}

var var::operator+=(const var& val)
{
	if (isStr(*this) || isStr(val)) set(*this + (char*)val);
	else set(*this + (double)val);

	return *this;
}

var var::operator-=(int val)
{
	set(var(atoi(*this) - val));
	return *this;
}

var var::operator-=(double val)
{
	set(var(atof(*this) - val));
	return *this;
}

var var::operator-=(const var& val)
{
	set(*this - (double)val);
	return *this;
}

bool var::operator==(const var& val) const
{
	for (int i = 0; i < len; i++)
		if (value[i] != val[i]) return false;
	return true;
}

bool var::operator!=(const var& val) const
{
	for (int i = 0; i < len; i++)
		if (value[i] == val[i]) return false;
	return true;
}

ostream& operator<<(ostream& out, const var& obj)
{
	return out << (char*)obj;
}
