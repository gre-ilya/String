#ifndef _STRING_H_
#define _STRING_H_

///////////////////////////////////////////////////
// Library for simplify work with character arrays.
//
// author:		Ilya Grebenyuk 
// last add were made:	27/07/2021
// 
// feedback on: ilya.grebenyuk.01@mail.ru 
///////////////////////////////////////////////////

class String 
{

	// '\0' - last character of any String
	char* data;
	// '\0' not included in length
	unsigned int length;
 
public:
	String(); 
	
	String(const char* data);

	String(char ch);

	String(const String& other);

	String(String&& other);

	~String();
	
	// return String length O(1)
	unsigned int getLength() const;
	
	// copy String other to calling String, copy has own data, O(n)
	const String& operator=(const String& other); 

	// move String other data and length to the left operand String, 0(1)
	const String& operator=(String&& other);

	// add String other to the end of calling string, O(n + m)
	const String& operator+=(const String& other);

	// external operator+, return concatenation of str1 and str2, O(n + m)
	friend String operator+(const String& str1, const String& str2);
	
	// access to String characters, O(1)
	char& operator[](unsigned int index);
	
	// lexicographically compares two strings, case insensetive,
	//   work current with ASCII english letters only, O(n)
	bool operator<(const String& other) const;

private:

	// change this String data and length, by new character array and 
	//   new_length, O(1);
	void setData(char* new_data, unsigned int new_length);

	// create new character array in memory and copy new_data to it, then	
	//   replace this String data by new_data and new_length, O(n)
	void createAndSetData(const char* new_data, unsigned int new_length);

	// return literal length w/o '\0', O(n) 
	static unsigned int countLength(const char* data);

	// copy characters from one array to another, O(n)
	static void copyChar(const char* from, char* to, unsigned int copy_len);

	// return given ASCII english letter in lower case
	static char toLowerCase(char ch);

	// return minimum of two given values
	static unsigned int getMinOfTwoValues(unsigned int a, unsigned int b);

	// create new character array and copy two character arrays in it
	//   one by another, add '\0' in the end of copy, O(n + m)
	static char* concatenateCharArrays(const char* arr_1, 
		unsigned int len_1, const char* arr_2, unsigned int len_2);
};

#endif //_STRING_H_
