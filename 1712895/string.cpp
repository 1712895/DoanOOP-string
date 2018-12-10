#include"string.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
using namespace std;
myString::myString()
{ 
	capPhatDong = 100;
	str = new char[capPhatDong];
	stringLength = 0;
	str[0] = '\0';
}
myString::myString(myString &a)
{
	stringLength = a.stringLength;
	capPhatDong = stringLength + 100;
	str = new char[capPhatDong];
	for (size_t i = 0; i < stringLength; i++)
	{
		str[i] = a.str[i];
	}
	str[stringLength] = '\0';
}
myString::myString(myString &a, size_t pos, size_t len)
{
	if (len + pos > a.stringLength)
	{
		stringLength = a.stringLength - pos;
		capPhatDong = stringLength + 100 ;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a.str[pos + i];
		}
		str[stringLength] = '\0';
	}
	else
	{
		stringLength = len;
		capPhatDong = stringLength+100;
		str = new char[capPhatDong];
		for (size_t i = 0; i < len; i++)
		{
			str[i] = a.str[pos + i];
		}
		str[len] = '\0';
	}
}
myString::myString(char* x)
{
	size_t lenx = 0;
	while (x[lenx] !='\0')
	{
		lenx++;
	}
	stringLength = lenx;
	capPhatDong = stringLength + 100  ;
	str = new char[capPhatDong];
	for (size_t i = 0; i < lenx; i++)
	{
		str[i] = x[i];
	}
	str[stringLength] = '\0';
}
myString::myString(char*x, size_t n)
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	if (n < lenx)
	{
		stringLength = n;
		capPhatDong = stringLength + 100;
		str = new char[capPhatDong];
		for (size_t i = 0; i < n; i++)
		{
			str[i] = x[i];
		}
		str[n] = '\0';
	}
	else
	{
		stringLength = lenx;
		capPhatDong = stringLength+100;
		str = new char[capPhatDong];
		for (size_t i = 0; i < lenx; i++)
		{
			str[i] = x[i];
		}
		str[lenx] = '\0';
	}
}
myString::myString(size_t n, char x)
{
	stringLength = n;
	capPhatDong = stringLength + 100;
	str = new char[capPhatDong];
	for (size_t i = 0; i < n; i++)
	{
		str[i] = x;
	}
	str[n] = '\0';
}
ostream& operator<<(ostream& out, const myString &string)
{
	out << string.str;
	return out;
}
istream& operator >> (istream& in, myString &string)
{
	while (in >> string.str)
	{
		if (string.length() == string.capPhatDong || string.length() > string.capPhatDong)
		{
			char*a = NULL;
			string.capPhatDong =string.length() +  50;
			a = new char[string.capPhatDong];
			a[string.length()] = '\0';
			for (size_t i = 0; i < string.stringLength; i++)
			{
				a[i] = string.str[i];
			}
	
			string.str = NULL;
			string.str = new char[string.capPhatDong];
			string = a;
			
			delete []a;
		}

		return in;
	}
}
myString ::~myString()
{
	if (str != NULL)
	{
		delete[]str;
	}
}
size_t myString::length()
{
	stringLength = 0;
	while (str[stringLength] != '\0')
	{
	stringLength++;
	}
	return stringLength;
}
size_t myString::length() const
{
	/*stringLength = 0;
	while (str[stringLength] != '\0')
	{
		stringLength++;
	}*/
	length();
	return stringLength;
}
myString& myString::operator=(const myString &string)
{
	stringLength = string.stringLength;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}
	for (size_t i = 0; i < stringLength; i++)
	{
		str[i] = string.str[i];
	}
	str[stringLength] = '\0';
	return *this;
	}
myString& myString::operator=(const char*x)
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	stringLength = lenx;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}
	for (size_t i = 0; i < lenx; i++)
	{
		str[i] = x[i];
	}
	str[lenx] = '\0';
	return *this;
}
myString& myString::operator=(const char x)
{
	stringLength = 1;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}
	
	str[0] = x;
	str[1] = '\0';
	return *this;
}
size_t myString::size() const 
{
	return length();
}
size_t myString::capacity()const
{
	return capPhatDong;
}
size_t myString::max_size()const
{
	return 4294967294;
}
void myString::resize(size_t n)
{
	str[n + 1] = '\0';
}
void myString::resize(size_t n, char x)
{
	if (n < length() && n==length())
	{
		resize(n);
	}
	else
	{
		for (size_t k = length(); k < n; k++)
		{
			str[k] = x;
		}
		str[n] = '\0';
	}
}
void myString::clear()
{
	for (size_t i = 0; i < length(); i++)
	{
		str[i] = '\0';
	}
}
bool myString::empty()
{
	if (length() == 0)return true;
	return false;
}
const char& myString::operator[](size_t pos)const
{
	return str[pos];
}
char& myString::operator[](size_t pos)
{
	return str[pos];
}
char& myString::at(size_t pos)
{
	return str[pos];
}
const char& myString::at(size_t pos) const
{
	return str[pos];
}
char& myString::back()
{
	return str[length()-1];
}
const char& myString::back() const
{
	return str[length() - 1];
}
char& myString::front()
{
	return str[0];
}
const char& myString::front() const
{
	return str[0];
}
myString& myString::operator+=(const myString& string)
{
	
	if ((stringLength + string.stringLength) > capPhatDong || (stringLength + string.stringLength) == capPhatDong )
	{
		char*a = NULL;
		capPhatDong = stringLength + string.stringLength + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete []str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	for (size_t i = 0; i < string.stringLength; i++)
	{
		str[stringLength + i] = string.str[i];
	}
	stringLength = stringLength + string.stringLength;
	str[stringLength] = '\0';
	return *this;
}
myString& myString::operator+=(const char *x)
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	if ((stringLength + lenx) > capPhatDong || (stringLength +lenx) == capPhatDong)
	{
		char*a = NULL;
		capPhatDong = stringLength + lenx + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete[]str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	for (size_t i = 0; i < lenx; i++)
	{
		str[stringLength + i] = x[i];
	}
	stringLength = stringLength + lenx;
	str[stringLength] = '\0';
	return *this;
}
myString& myString::operator+=(char x)
{
	if ((stringLength + 1) > capPhatDong || (stringLength + 1) == capPhatDong)
	{
		char*a = NULL;
		capPhatDong = stringLength + 1 + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete[]str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	str[stringLength] = x;
	str[stringLength + 1] = '\0';
	stringLength = stringLength + 1;
	return *this;
}
myString& myString::append(const myString& string)
{
	return *this += string;
}
myString& myString::append(const myString& string, size_t subpos, size_t sublen)
{

	if ((stringLength +sublen) > capPhatDong || (stringLength + sublen) == capPhatDong)
	{
		char*a = NULL;
		capPhatDong = stringLength + sublen + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete[]str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	for (size_t i = 0; i < sublen; i++)
	{
		str[stringLength + i] = string.str[subpos+i];
	}
	stringLength = stringLength +sublen;
	str[stringLength] = '\0';
	return *this;
}
myString& myString::append(const char* s)
{
	return *this += s;
}
myString& myString::append(const char* x, size_t n)
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	if ((stringLength + lenx) > capPhatDong || (stringLength + lenx) == capPhatDong)
	{
		char*a = NULL;
		capPhatDong = stringLength + lenx + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete[]str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	if (n > lenx||n==lenx) { 
		return *this+=x; 
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			str[stringLength + i] = x[i];
		}
		stringLength = stringLength + n;
		str[stringLength] = '\0';
		return *this;
	}
}
myString& myString::append(size_t n, char c)
{
	if ((stringLength + n) > capPhatDong || (stringLength + n) == capPhatDong)
	{
		char*a = NULL;
		capPhatDong = stringLength + n + 50;
		a = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			a[i] = str[i];
		}
		delete[]str;
		str = NULL;
		str = new char[capPhatDong];
		for (size_t i = 0; i < stringLength; i++)
		{
			str[i] = a[i];
		}
		delete []a;
	}
	for (size_t i = 0; i < n; i++)
	{
		str[stringLength + i] = c;
	}
	stringLength = stringLength + n;
	str[stringLength] = '\0';
	return *this;
}
void myString::push_back(char c)
{
	*this += c;
}
myString& myString::assign(const myString& string)
{
	return *this = string;
}
myString& myString::assign(const myString& string, size_t subpos, size_t sublen)
{
	if (sublen > (string.stringLength-subpos))
	{
		sublen = string.stringLength-subpos;
		
	}
	stringLength = sublen;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}
	for (size_t i = 0; i < sublen; i++)
	{
		str[i] = string.str[subpos+i];
	}
	str[sublen] = '\0';
	return *this;
}
myString& myString::assign(const char* s)
{
	return *this = s;
}
myString& myString::assign(const char* x, size_t n)
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	stringLength = lenx;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}
	if (n > lenx || n == lenx)
	{
		return assign(x);
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			str[i] = x[i];
		}
		str[n] = '\0';
		return *this;
	}
}
myString& myString::assign(size_t n, char c)
{
	stringLength = n;
	if (stringLength == capPhatDong || stringLength > capPhatDong)
	{
		capPhatDong = stringLength + 50;
		str = new char[capPhatDong];
	}

		for (size_t i = 0; i < n; i++)
		{
			str[i] = c;
		}
		str[n] = '\0';
		return *this;
}
myString& myString::insert(size_t pos, const myString& string)
{
	myString veSau;
	veSau.assign(*this, pos, stringLength);
	myString veTruoc;
	veTruoc.assign(*this, 0, pos);
	*this = veTruoc;
	*this += string;
	return *this+=veSau;
}
myString& myString::insert(size_t pos, const myString& string, size_t subpos, size_t sublen)
{
	myString veSau;
	veSau.assign(*this, pos, stringLength);
	myString veGiua;
	veGiua.assign(string, subpos, sublen);
	myString veTruoc;
	veTruoc.assign(*this, 0, pos);
	*this = veTruoc;
	*this += veGiua;
	return *this += veSau;
}
myString& myString::insert(size_t pos, const char* s)
{
	myString veSau;
	veSau.assign(*this, pos, stringLength);
	myString veTruoc;
	veTruoc.assign(*this, 0, pos);
	*this = veTruoc;
	*this += s;
	return *this += veSau;
}
myString& myString::insert(size_t pos, const char* s, size_t n)
{
	myString veSau;
	veSau.assign(*this, pos, stringLength);
	char *x = new char[n+1];
	for (size_t i = 0; i < n; i++)
	{
		x[i] = s[i];
	}
	x[n] = '\0';
	myString veTruoc;
	veTruoc.assign(*this, 0, pos);
	*this = veTruoc;
	*this += x;
	delete[]x;
	return *this += veSau;
}
myString& myString::insert(size_t pos, size_t n, char c)
{
	myString veSau;
	veSau.assign(*this, pos, stringLength);
	myString veGiua;
	veGiua.assign(n, c);
	myString veTruoc;
	veTruoc.assign(*this, 0, pos);
	*this = veTruoc;
	*this += veGiua;
	return *this += veSau;
}
myString& myString::erase(size_t pos, size_t len)
{
	myString veDau;
	veDau.assign(*this, 0, pos);
	myString veGiua;
	veGiua.assign(*this, pos, len);
	myString veSau;
	veSau.assign(*this, pos+len, stringLength);
	*this = veDau;
	return *this += veSau;
}
myString& myString::replace(size_t pos, size_t len, const myString& string)
{
	myString veTruoc;
	veTruoc.append(*this, 0, pos);
	myString veSau;
	veSau.append(*this, len + pos, stringLength);
	*this = veTruoc;
	*this += string;
	return *this += veSau;
}
myString& myString::replace(size_t pos, size_t len, const myString& string, size_t subpos, size_t sublen)
{
	myString veTruoc;
	veTruoc.append(*this, 0, pos);
	myString veGiua;
	veGiua.append(string, subpos, sublen);
	myString veSau;
	veSau.append(*this, len + pos, stringLength);
	*this = veTruoc;
	*this += veGiua;
	return *this += veSau;
}
myString& myString::replace(size_t pos, size_t len, const char* s)
{
	myString veTruoc;
	veTruoc.append(*this, 0, pos);
	myString veSau;
	veSau.append(*this, len + pos, stringLength);
	*this = veTruoc;
	*this += s;
	return *this += veSau;
}
myString& myString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	myString veTruoc;
	veTruoc.append(*this, 0, pos);
	myString veGiua;
	veGiua.append(s, n);
	myString veSau;
	veSau.append(*this, len + pos, stringLength);
	*this = veTruoc;
	*this += veGiua;
	return *this += veSau;
}
myString& myString::replace(size_t pos, size_t len, size_t n, char c)
{
	myString veTruoc;
	veTruoc.append(*this, 0, pos);
	myString veGiua;
	veGiua.append(n,c);
	myString veSau;
	veSau.append(*this, len + pos, stringLength);
	*this = veTruoc;
	*this += veGiua;
	return *this += veSau;
}
void myString::swap(myString& str)
{
	myString temp;
	temp = str;
	str = *this;
	*this = temp;
}
void myString::pop_back()
{
	myString temp;
	temp = *this;
	temp.assign(temp, 0, temp.length() - 1);
	*this = temp;
}
const char* myString::data() const
{
	return str;
}
char* myString::data()
{
	return str;
}
size_t myString::copy(char* s, size_t len, size_t pos ) const 
{
	if (stringLength < pos + len)
	{
		return stringLength - pos;
	}
	return pos + len;
}
size_t myString::find(const myString& string, size_t pos ) const
{
	size_t n = pos;
	size_t m =0;
	size_t len = string.stringLength;     
    while (str[n] != '\0') {
		if (str[n] == string.str[m]) {    
										  
			while (str[n] == string.str[m] && str[n] != '\0') {
				n++;
				m++;
			}

			
			if (m == len/* && (str[n] == ' ' || str[n] == '\0')*/) {
				
				
				return n - len;
			}
		}
		else {
			while (str[n] != ' ') {       
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0; 
	}
	return -1;
}
size_t myString::find(const char* x, size_t pos ) const
{
	size_t n = pos;
	size_t m = 0;
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	while (str[n] != '\0') {
		if (str[n] == x[m]) {

			while (str[n] == x[m] && str[n] != '\0') {
				n++;
				m++;
			}


			if (m == lenx/* && (str[n] == ' ' || str[n] == '\0')*/) {


				return n - lenx;
			}
		}
		else {
			while (str[n] != ' ') {
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0;
	}
	return -1;
}
size_t myString::find(const char* x, size_t pos, size_t k) const
{
	size_t n = pos;
	size_t m = 0;
	myString string;
	string.append(x, k);
	size_t lenx = string.stringLength;
	while (str[n] != '\0') {
		if (str[n] == string.str[m]) {

			while (str[n] == string.str[m] && str[n] != '\0') {
				n++;
				m++;
			}


			if (m == lenx/* && (str[n] == ' ' || str[n] == '\0')*/) {


				return n - lenx;
			}
		}
		else {
			while (str[n] != ' ') {
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0;
	}
	return -1;
}
size_t myString::find(char c, size_t pos ) const
{
	size_t i = pos;
	while (str[i] != '\0')
	{
		if (str[i] == c)return i;
		i++;
	}
	return -1;
}
size_t myString::rfind(const myString& string, size_t pos) const
{
	size_t n = pos;
	size_t m = 0;
	size_t i = 0;
	vector<size_t> index;
	size_t len = string.stringLength;
	while (str[n] != '\0') {
		if (str[n] == string.str[m]) {

			while (str[n] == string.str[m] && str[n] != '\0') {
				n++;
				m++;
			}


			if (m == len/* && (str[n] == ' ' || str[n] == '\0')*/) {
				index.push_back(n - len);
			}
		}
		else {
			while (str[n] != ' ') {
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0;
	}
	if (index.size() != 0)
		return index.back();
	return -1;
}
size_t myString::rfind(const char* x, size_t pos ) const
{
	size_t n = pos;
	size_t m = 0;
	size_t lenx = 0;
	vector<size_t> index;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	while (str[n] != '\0') {
		if (str[n] == x[m]) {

			while (str[n] == x[m] && str[n] != '\0') {
				n++;
				m++;
			}


			if (m == lenx/* && (str[n] == ' ' || str[n] == '\0')*/) {


				index.push_back( n - lenx);
			}
		}
		else {
			while (str[n] != ' ') {
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0;
	}
	if (index.size() != 0)
		return index.back();
	return -1;
}
size_t myString::rfind(const char* x, size_t pos, size_t k) const
{
	size_t n = pos;
	size_t m = 0;
	vector<size_t> index;
	myString string;
	string.append(x, k);
	size_t lenx = string.stringLength;
	while (str[n] != '\0') {
		if (str[n] == string.str[m]) {

			while (str[n] == string.str[m] && str[n] != '\0') {
				n++;
				m++;
			}


			if (m == lenx/* && (str[n] == ' ' || str[n] == '\0')*/) {


				index.push_back(n - lenx);

			}
		}
		else {
			while (str[n] != ' ') {
				n++;
				if (str[n] == '\0')
					break;
			}
		}

		n++;
		m = 0;
	}
	if (index.size() != 0)
	{
		return index.back();
	}
	return -1;
}
size_t myString::rfind(char c, size_t pos) const
{
	size_t i = pos;
	vector<size_t> index;
	while (str[i] != '\0')
	{
		if (str[i] == c)index.push_back( i);
		i++;
	}
	if (index.size() != 0)
	{
		return index.back();
	}
	return -1;
}
size_t myString::find_first_of(const myString& string, size_t pos)const
{
	size_t *index = new size_t[string.stringLength];
		for (size_t i =0; i < string.stringLength; i++)
	{
		index[i] = find(string.str[i],pos);
		
	}
		size_t min = index[0];
		for (size_t i = 1; i < string.stringLength; i++)
		{
			if (min > index[i])
			{
				min = index[i];
			}
		}
		delete[]index;
		if (min > 0 || min == 0)
		{
			return min;
	}
	return -1;
}
size_t myString::find_first_of(const char* x, size_t pos )const
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[lenx];
	for (size_t i = 0; i < lenx; i++)
	{
		index[i] = find(x[i],pos);
	}
	size_t min = index[0];
	for (size_t i = 1; i <lenx; i++)
	{
		if (min > index[i])
		{
			min = index[i];
		}
	}
	delete[]index;
	if (min > 0 || min == 0)
	{
		return min;
	}
	return -1;
}
size_t myString::find_first_of(const char* x, size_t pos, size_t n)const
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[n];
	for (size_t i = 0; i < n; i++)
	{
		index[i] = find(x[i], pos);
	}
	size_t min = index[0];
	for (size_t i = 1; i <n; i++)
	{
		if (min > index[i])
		{
			min = index[i];
		}
	}
	delete[]index;
	if (min > 0 || min == 0)
	{
		return min;
	}
	return -1;
}
size_t myString::find_first_of(char c, size_t pos )const
{
	return find(c, pos);
}
size_t myString::find_last_of(const myString& string, size_t pos )const
{
	size_t *index = new size_t[string.stringLength];
	for (size_t i = 0; i < string.stringLength; i++)
	{
		index[i] = rfind(string.str[i], pos);

	}
	size_t max = index[0];
	for (size_t i = 1; i < string.stringLength; i++)
	{
		if (max < index[i])
		{
			max = index[i];
		}
	}
	delete[]index;
	if (max > 0 || max == 0)
	{
		return max;
	}
	return -1;
}
size_t myString::find_last_of(const char* x, size_t pos)const
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[lenx];
	for (size_t i = 0; i < lenx; i++)
	{
		index[i] = rfind(x[i], pos);
	}
	size_t max = index[0];
	for (size_t i = 1; i <lenx; i++)
	{
		if (max < index[i])
		{
			max = index[i];
		}
	}
	delete[]index;
	if (max > 0 || max == 0)
	{
		return max;
	}
	return -1;
}
size_t myString::find_last_of(const char* x, size_t pos, size_t n)const
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[n];
	for (size_t i = 0; i < n; i++)
	{
		index[i] = rfind(x[i], pos);
	}
	size_t max = index[0];
	for (size_t i = 1; i <n; i++)
	{
		if (max < index[i])
		{
			max = index[i];
		}
	}
	delete[]index;
	if (max > 0 || max == 0)
	{
		return max;
	}
	return -1;
}
size_t myString::find_last_of(char c, size_t pos)const
{
	return rfind(c, pos);
}
myString myString::substr(size_t pos, size_t len)const
{
	myString string;
	string.assign(*this, pos, len);
	return string;
}
int myString::compare(const myString& string)const
{
	size_t leny;
	if (stringLength > string.stringLength)
	{
		leny = string.stringLength;
	}
	else
	{
		leny = stringLength;
	}
	for (size_t i = 0; i < leny; i++)
	{
		if (str[i] > string.str[i])
		{
			return 1;
		}
		if (str[i] < string.str[i])
		{
			return -1;
		}
	}
	if (stringLength > string.stringLength)
	{
		return 1;
	}
	if (stringLength < string.stringLength)
	{
		return -1;
	}
	if (stringLength == string.stringLength)
	{
		return 0;
	}
}
int myString::compare(size_t pos, size_t len, const myString& string, size_t subpos, size_t sublen)const
{
	myString stringing;
	stringing.assign(*this, pos, len);
	myString stringed;
	stringed.assign(string, subpos, sublen);
	return stringing.compare(stringed);
}
int myString::compare(size_t pos, size_t len, const myString& str)const
{
	return compare(pos, len, str, 0, 0);
}
int myString::compare(const char* s)const
{
	myString string;
	string.assign(s);
	return compare(string);
}
int myString::compare(size_t pos, size_t len, const char* s)const
{
	myString string;
	string.assign(*this, pos, len);
	return string.compare(s);
}
int myString::compare(size_t pos, size_t len, const char* x, size_t n)const
{
	size_t lenx = 0;
	size_t leny = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	if (stringLength > n)
	{
		leny = n;
	}
	else
	{
		leny = stringLength;
	}
	for (size_t i = 0; i <len; i++)
	{
		if (str[i] > x[i])
		{
			return 1;
		}
		if (str[i] < x[i])
		{
			return -1;
		}
	}
	if (stringLength > n)
	{
		return 1;
	}
	if (stringLength < n)
	{
		return -1;
	}
	if (stringLength == n)
	{
		return 0;
	}
}
myString operator+(const myString& lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	string.append(rhs);
	return string;
}
myString operator+ (const myString& lhs, const char*   rhs)
{
	myString string;
	string.append(lhs);
	string.append(rhs);
	return string;
}
myString operator+ (const char*   lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	string.append(rhs);
	return string;
}
myString operator+ (const myString& lhs, char rhs)
{
	myString string;
	string.append(lhs);
	string.append(1, rhs);
	return string;
}
myString operator+ (char lhs, const myString& rhs)
{
	myString string;
	string.append(1,lhs);
	string.append(rhs);
	return string;
}
bool operator== (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator== (const char*   lhs, const myString& rhs)
{
	if (rhs.compare(lhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator== (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator!= (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return false;
	}
	return true;
}
bool operator!= (const char*   lhs, const myString& rhs)
{
	if (rhs.compare(lhs) == 0)
	{
		return false;
	}
	return true;
}
bool operator!= (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return false;
	}
	return true;
}
bool operator<  (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == -1)
	{
		return true ;
	}
	return false;
}
bool operator<  (const char*   lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	if (string.compare(rhs) == -1)
	{
		return true;
	}
	return false;
}
bool operator<  (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == -1)
	{
		return true;
	}
	return false;
}
bool operator<= (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator<= (const char*   lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	if (string.compare(rhs) == -1 || string.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator<= (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator>  (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == 1)
	{
		return true;
	}
	return false;
}
bool operator>  (const char*   lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	if (string.compare(rhs) == 1)
	{
		return true;
	}
	return false;
}
bool operator>  (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == 1)
	{
		return true;
	}
	return false;
}
bool operator>= (const myString& lhs, const myString& rhs)
{
	if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator>= (const char*   lhs, const myString& rhs)
{
	myString string;
	string.append(lhs);
	if (string.compare(rhs) == 1 || string.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
bool operator>= (const myString& lhs, const char*   rhs)
{
	if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}
void swap(myString& x, myString& y)
{
	x.swap(y);
}
void myString::reserve(size_t n)
{
	myString string;
	string.assign(n,'+');
	*this = string;
}
istream& getline(istream& is, myString& string)
{
	return is.getline(string.data(), string.max_size());
}
istream& getline(istream& is, myString& string, char delim)
{
	return is.getline(string.data(), string.max_size(),delim);
}
size_t myString::find_first_not_of(const myString& string, size_t pos )const
{
	size_t *index = new size_t[stringLength];
	for (int i = 0; i < stringLength; i++)
	{
		index[i] = 0;
	}
	for (size_t i = 0; i < stringLength; i++)
	{
		for (size_t j = 0; j < string.stringLength; j++)
		{
			if (str[i] == string.str[j])
			{
				index[i] = 1;
			}
		}
	}
	myString a;
	for (int i = 0; i < stringLength; i++)
	{
		if (index[i] == 0)
		{
			a.append(1, str[i]);
		}
	}
	delete[]index;
	return find_first_of(a, pos);
}
size_t myString::find_first_not_of(const char* x, size_t pos )const
{
	size_t lenx=0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[stringLength];
	for (int i = 0; i < stringLength; i++)
	{
		index[i] = 0;
	}
	for (size_t i = 0; i < stringLength; i++)
	{
		for (size_t j = 0; j < lenx; j++)
		{
			if (str[i] == x[j])
			{
				index[i] = 1;
			}
		}
	}
	myString a;
	for (int i = 0; i < stringLength; i++)
	{
		if (index[i] == 0)
		{
			a.append(1, str[i]);
		}
	}
	delete[]index;
	return find_first_of(a, pos);
}
size_t myString::find_first_not_of(const char* s, size_t pos, size_t n)const
{
	if (n > stringLength)
	{
		return find_first_not_of(s, pos);
}
	else
	{
		size_t *index = new size_t[stringLength];
		for (int i = 0; i < stringLength; i++)
		{
			index[i] = 0;
		}
		for (size_t i = 0; i < stringLength; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (str[i] == s[j])
				{
					index[i] = 1;
				}
			}
		}
		myString a;
		for (int i = 0; i < stringLength; i++)
		{
			if (index[i] == 0)
			{
				a.append(1, str[i]);
			}
		}
		delete[]index;
		return find_first_of(a, pos);
	}
}
size_t myString::find_first_not_of(char c, size_t pos)const
{
	myString a;
	a.assign(1, c);
	return find_first_not_of(a, pos);
}
size_t myString::find_last_not_of(const myString& string, size_t pos )const
{
	size_t *index = new size_t[stringLength];
	for (int i = 0; i < stringLength; i++)
	{
		index[i] = 0;
	}
	for (size_t i = 0; i < stringLength; i++)
	{
		for (size_t j = 0; j < string.stringLength; j++)
		{
			if (str[i] == string.str[j])
			{
				index[i] = 1;
			}
		}
	}
	myString a;
	for (int i = 0; i < stringLength; i++)
	{
		if (index[i] == 0)
		{
			a.append(1, str[i]);
		}
	}
	delete[]index;
	return find_last_of(a, pos);
}
size_t myString::find_last_not_of(const char* x, size_t pos )const
{
	size_t lenx = 0;
	while (x[lenx] != '\0')
	{
		lenx++;
	}
	size_t *index = new size_t[stringLength];
	for (int i = 0; i < stringLength; i++)
	{
		index[i] = 0;
	}
	for (size_t i = 0; i < stringLength; i++)
	{
		for (size_t j = 0; j < lenx; j++)
		{
			if (str[i] == x[j])
			{
				index[i] = 1;
			}
		}
	}
	myString a;
	for (int i = 0; i < stringLength; i++)
	{
		if (index[i] == 0)
		{
			a.append(1, str[i]);
		}
	}
	delete[]index;
	return find_last_of(a, pos);
}
size_t myString::find_last_not_of(const char* s, size_t pos, size_t n)const
{
	if (n > stringLength)
	{
		return find_last_not_of(s, pos);
	}
	else
	{
		size_t *index = new size_t[stringLength];
		for (int i = 0; i < stringLength; i++)
		{
			index[i] = 0;
		}
		for (size_t i = 0; i < stringLength; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (str[i] == s[j])
				{
					index[i] = 1;
				}
			}
		}
		myString a;
		for (int i = 0; i < stringLength; i++)
		{
			if (index[i] == 0)
			{
				a.append(1, str[i]);
			}
		}
		delete[]index;
		return find_last_of(a, pos);
	}
}
size_t myString::find_last_not_of(char c, size_t pos )const
{
	myString a;
	a.assign(1, c);
	return find_last_not_of(a, pos);
}
MyIterator myString::begin()
{
	return MyIterator(str);
	
}
MyIterator myString::end()
{
	return MyIterator(str + length());
}
const_MyIterator myString::begin() const
{
	return str;
}
const_MyIterator myString::end() const
{
	
	return (str + stringLength);
}
MyIterator_reserve  myString::rbegin()
{
	return MyIterator_reserve(str+length()-1);

}
MyIterator_reserve  myString::rend()
{
	return MyIterator_reserve(str - 1);
}
const_MyIterator_reserve myString::rbegin() const
{
	return str + stringLength - 1;
}
const_MyIterator_reserve myString::rend() const
{
	return str - 1;
}
