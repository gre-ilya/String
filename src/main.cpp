#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/String.h"

using std::cout;

// std::cout << String << std::endl
void stringPrintln(String &str);

// some tests
void valgrindTest();


int main(int argc, char** argv)
{
	// valgrindTest();
	if (argc == 1) {
		std::cerr << "give me some strings" << std::endl;
		return -1;
	}
	std::vector<String> input_strings(argc-1);
	for (unsigned int i = 0; i < input_strings.size(); i++) {
		input_strings[i] = argv[i + 1];
	}
	std::sort(input_strings.begin(), input_strings.end());
	for (unsigned int i = 0; i < input_strings.size(); i++) {
		stringPrintln(input_strings[i]);
	}
	return 0;
}

void stringPrintln(String &str)
{
	for (unsigned int i = 0; i < str.getLength(); i++) {
		cout << str[i];
	}
	cout << std::endl;
}

void valgrindTest()
{
	std::vector<String> some_strings(4);
	some_strings[0] = String("abc");
	some_strings[1] = String(some_strings[0]);
	some_strings[2] = some_strings[0] + "def";
	some_strings[2] += some_strings[0];
	some_strings[3] = some_strings[0] + 'd';
	cout << "=====TEST_OUTPUT=====\n";
	for (unsigned int i = 0; i < some_strings.size(); i++) {
		cout << "String length: " << some_strings[i].getLength() << 
		    " String data: ";
		stringPrintln(some_strings[i]);
	}
	cout << "=====================" << std::endl;
}
