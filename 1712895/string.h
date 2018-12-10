#pragma once
#ifndef _string
#define _string 
#include<fstream>
#include<vector>
#include<iterator>
using namespace std;
class MyIterator 
{
	char* p;
public:
	MyIterator(char* x=0) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() { ++p; return *this; }
	MyIterator operator++(int) { MyIterator tmp(*this); operator++(); return tmp; }
	bool operator==(const MyIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const MyIterator& rhs) const { return p != rhs.p; }
	char& operator*() { return *p; }
};
class  const_MyIterator
{
	char* p;
public:
	const_MyIterator(char* x = 0) :p(x) {}
	const_MyIterator(const const_MyIterator& mit) : p(mit.p) {}
	const_MyIterator& operator++() { ++p; return *this; }
	const_MyIterator operator++(int) { const_MyIterator tmp(*this); operator++(); return tmp; }
	bool operator==(const const_MyIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const const_MyIterator& rhs) const { return p != rhs.p; }
	char& operator*() { return *p; }
};
class MyIterator_reserve 
{
	char* p;
public:
	MyIterator_reserve(char* x = 0) :p(x) {}
	MyIterator_reserve(const MyIterator_reserve& mit) : p(mit.p) {}
	MyIterator_reserve& operator++() { --p; return *this; }
	MyIterator_reserve operator++(int) { MyIterator_reserve tmp(*this); operator++(); return tmp; }
	bool operator==(const MyIterator_reserve& rhs) const { return p == rhs.p; }
	bool operator!=(const MyIterator_reserve& rhs) const { return p != rhs.p; }
	char& operator*() { return *p; }
};
class const_MyIterator_reserve
{
	char* p;
public:
	const_MyIterator_reserve(char* x = 0) :p(x) {}
	const_MyIterator_reserve(const const_MyIterator_reserve& mit) : p(mit.p) {}
	const_MyIterator_reserve& operator++() { --p; return *this; }
	const_MyIterator_reserve operator++(int) { const_MyIterator_reserve tmp(*this); operator++(); return tmp; }
	bool operator==(const const_MyIterator_reserve& rhs) const { return p == rhs.p; }
	bool operator!=(const const_MyIterator_reserve& rhs) const { return p != rhs.p; }
	char& operator*() { return *p; }
};
static const size_t npos = -1;

class  myString 
{
private:
	char* str = NULL;
	size_t stringLength;
	size_t capPhatDong;
public:
	 myString ();
	 myString(myString &a);
	 myString(myString &a, size_t pos, size_t len);
	 myString(char* x);
	 myString(char*x, size_t n);
	 myString(size_t n, char x);
	 friend ostream& operator<<(ostream& out, const myString &string);
	 friend istream& operator>> (istream& in, myString &string);
	 myString& operator=(const myString &string);
	 myString& operator=(const char*x);
	 myString& operator=(const char x);
	 MyIterator begin();
	 MyIterator end();
	 const_MyIterator begin() const;
	 const_MyIterator end() const;
	 MyIterator_reserve rbegin();
	 MyIterator_reserve  rend();
	 const_MyIterator_reserve rbegin() const;
	 const_MyIterator_reserve rend() const;
	 size_t size()const ;
	 size_t length();
	 size_t length()const ;
	 size_t capacity()const ;
	 size_t max_size()const ;
	 void resize(size_t n);
	 void resize(size_t n, char c);
	 void reserve(size_t n);
	 void clear();
	 bool empty() ;
	 const char& operator[](size_t pos)const;
	 char& myString::operator[](size_t pos);
	 char& at(size_t pos);
	 const char& at(size_t pos) const;
	 char& back();
	 const char& back() const;
	 char& front();
	 const char& front() const;
	 myString& operator+=(const myString& string);
	 myString& operator+=(const char *x);
	 myString& myString::operator+=(char x);
	 myString& append(const myString& string);
	 myString& append(const myString& string,size_t subpos,size_t sublen);
	 myString& append(const char* s);
	 myString& append(const char* x, size_t n);
	 myString& append(size_t n, char c);
	 void push_back(char c);
	 myString& assign(const myString& string);
	 myString& assign(const myString& string, size_t subpos, size_t sublen);
	 myString& assign(const char* s);
	 myString& assign(const char* x, size_t n);
	 myString& assign(size_t n, char c);
	 myString& insert(size_t pos, const myString& string);
	 myString& insert(size_t pos, const myString& string, size_t subpos, size_t sublen);
	 myString& insert(size_t pos, const char* s);
	 myString& insert(size_t pos, const char* s, size_t n);
	 myString& insert(size_t pos, size_t n, char c);
	 myString& erase(size_t pos, size_t len );
	 myString& replace(size_t pos, size_t len, const myString& string);
	 myString& replace(size_t pos, size_t len, const myString& string,size_t subpos, size_t sublen);
	 myString& replace(size_t pos, size_t len, const char* s);
	 myString& replace(size_t pos, size_t len, const char* s, size_t n);
	 myString& replace(size_t pos, size_t len, size_t n, char c);
	 void swap(myString& str);
	 void pop_back();
	 const char* data() const;
	 char* data();
	 size_t copy(char* s, size_t len, size_t pos = 0)const ;
	 size_t find(const myString& string, size_t pos = 0)const;
	 size_t find(const char* x, size_t pos = 0)const;
	 size_t find(const char* x, size_t pos, size_t k) const;
	 size_t find(char c, size_t pos = 0)const;
	 size_t rfind(const myString& string, size_t pos = npos) const;
	 size_t rfind(const char* x, size_t pos = npos) const;
	 size_t rfind(const char* x, size_t pos, size_t k) const;
	 size_t rfind(char c, size_t pos = npos) const;
	 size_t find_first_of(const myString& string, size_t pos = 0) const;
	 size_t find_first_of(const char* x, size_t pos = 0)const;
	 size_t find_first_of(const char* x, size_t pos, size_t n)const;
	 size_t find_first_of(char c, size_t pos = 0)const;
	 size_t find_last_of(const myString& string, size_t pos = npos)const;
	 size_t find_last_of(const char* x, size_t pos = npos)const;
	 size_t find_last_of(const char* x, size_t pos, size_t n)const;
	 size_t find_last_of(char c, size_t pos = npos)const;
	 size_t find_first_not_of(const myString& string, size_t pos = 0)const;
	 size_t find_first_not_of(const char* x, size_t pos = 0)const;
	 size_t find_first_not_of(const char* s, size_t pos, size_t n)const;
	 size_t find_first_not_of(char c, size_t pos = 0)const;
	 size_t find_last_not_of(const myString& string, size_t pos = npos)const;
	 size_t find_last_not_of(const char* x, size_t pos = npos)const;
	 size_t find_last_not_of(const char* s, size_t pos, size_t n)const;
	 size_t myString::find_last_not_of(char c, size_t pos = npos)const;
	 myString substr(size_t pos = 0, size_t len =npos)const;
	 int compare(const myString& string)const;
	 int compare(size_t pos, size_t len, const myString& string, size_t subpos, size_t sublen)const;
	 int compare(size_t pos, size_t len, const myString& str)const;
	 int compare(const char* s)const;
	 int compare(size_t pos, size_t len, const char* s) const;
	 int compare(size_t pos, size_t len, const char* x, size_t n)const;
	 
	 ~ myString ();

	
};
myString operator+(const myString& lhs, const myString& rhs);
myString operator+ (const myString& lhs, const char*   rhs);
myString operator+ (const char*   lhs, const myString& rhs);
myString operator+ (const myString& lhs, char rhs);
myString operator+ (char lhs, const myString& rhs);
bool operator== (const myString& lhs, const myString& rhs);
bool operator== (const char*   lhs, const myString& rhs);
bool operator== (const myString& lhs, const char*   rhs);
bool operator!= (const myString& lhs, const myString& rhs);
bool operator!= (const char*   lhs, const myString& rhs);
bool operator!= (const myString& lhs, const char*   rhs);
bool operator<  (const myString& lhs, const myString& rhs);
bool operator<  (const char*   lhs, const myString& rhs);
bool operator<  (const myString& lhs, const char*   rhs);
bool operator<= (const myString& lhs, const myString& rhs);
bool operator<= (const char*   lhs, const myString& rhs);
bool operator<= (const myString& lhs, const char*   rhs);
bool operator>  (const myString& lhs, const myString& rhs);
bool operator>  (const char*   lhs, const myString& rhs);
bool operator>  (const myString& lhs, const char*   rhs);
bool operator>= (const myString& lhs, const myString& rhs);
bool operator>= (const char*   lhs, const myString& rhs);
bool operator>= (const myString& lhs, const char*   rhs);
void swap(myString& x, myString& y);
istream& getline(istream& is, myString& string);
istream& getline(istream& is, myString& string, char delim);
#endif