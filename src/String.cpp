#include "../include/String.h"

String::String() 
{ 
	setData(nullptr, 0); 
} 

String::String(const char* data) 
{ 
	createAndSetData(data, countLength(data)); 
}

String::String(char ch)
{
	char tmp[] = {ch};
	createAndSetData(tmp, 1);
}

String::String(const String& other) 
{
	createAndSetData(other.data, other.length); 
}

String::String(String&& other) 
{
	setData(other.data, other.length);
	other.setData(nullptr, 0);
}

String::~String()
{
	delete [] data;	
}

unsigned int String::getLength() const 
{
	return length; 
}
	
const String& String::operator=(const String& other)
{
	delete [] data;
	createAndSetData(other.data, other.length);
	return *this;
}

const String& String::operator=(String&& other) 
{
	delete [] data;
	setData(other.data, other.length);
	other.setData(nullptr, 0);
	return *this;
}

const String& String::operator+=(const String& other)
{
	unsigned int new_length = length + other.length;
	char* new_data = concatenateCharArrays(data, length, other.data,
		other.length);
	delete [] data;
	setData(new_data, new_length);
	return *this;
}

String operator+(const String& str1, const String& str2)
{
	char *new_string_data = String::concatenateCharArrays(str1.data, 
		str1.length, str2.data, str2.length);
	String res;
	res.setData(new_string_data, str1.length + str2.length);
	return res;
}

char& String::operator[](unsigned int index)
{
	return data[index];
}

bool String::operator<(const String& other) const
{
	unsigned int min_len = getMinOfTwoValues(length, other.length);
	for (unsigned int i = 0; i < min_len; i++) {
		char now1 = toLowerCase(data[i]);
		char now2 = toLowerCase(other.data[i]);
		if (now1 < now2) {
			return true;
		} else if (now1 > now2) {
			return false;
		}
	}
	return length < other.length;
}

void String::setData(char* new_data, unsigned int new_length) 
{
	length = new_length;
	data = new_data;
}

void String::createAndSetData(const char* data_to_copy, 
	unsigned int new_length)
{
	char* new_data = new char[new_length + 1];
	new_data[new_length] = '\0';
	copyChar(data_to_copy, new_data, new_length);
	length = new_length;
	data = new_data;
}

unsigned int String::countLength(const char* data)
{
	for (unsigned int res = 0; ; res++) {
		if (data[res] == '\0') {
			return res;
		}
	}
}

void String::copyChar(const char* from, char* to, unsigned int copy_len)
{
	for (unsigned int i = 0; i < copy_len; i++) {
		to[i] = from[i];
	}
}

char String::toLowerCase(char ch)
{
	if (ch >= 'A' && ch <= 'Z') {	// if ch is upper case
		return ch - ('A' - 'a');	//   return ch in lower case
	} else {
		return ch;
	}
}

unsigned int String::getMinOfTwoValues(unsigned int a, unsigned int b)
{
	return a <= b ? a : b; 
}

char* String::concatenateCharArrays(const char* arr_1, unsigned int len_1, 
	const char* arr_2, unsigned int len_2)
{
	char* concatenation = new char[len_1 + len_2 + 1];
	concatenation[len_1 + len_2] = '\0';
	copyChar(arr_1, concatenation, len_1);
	copyChar(arr_2, concatenation + len_1, len_2);
	return concatenation;
}
