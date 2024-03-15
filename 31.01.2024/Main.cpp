#include "MyString.h"
using namespace std;

int main()
{
	MyString str1("Hello");
	MyString str2("World");

	str1.show();
	str2.show();

	str1.append(str2);
	str1.show();

	str1 += '!';
	str1.show();

	str1.insert(5, ", ");
	str1.show();

	str1.replace(5, 6, "n");
	str1.show();

	cout << R"(str1.find("d") : )" << str1.find("d") << endl;
	cout << R"(str1.rfind("d") : )" << str1.rfind("d") << endl;

	cout << str1.sizeStr() << endl;
	cout << str1.empty() << endl;

	cout << str1.compare("HellonnnWorld") << endl;
	
	str1.erase('H');
	str1.show();

	cout << str1.stoi("-257") << endl;

	int result;

	result = (str1 == "Wolrd"); 
	cout << " operator== " << result << endl;
	result = (str1 != "Wolrd");
	cout << " operator!= " << result << endl;
	result = (str1 >= "World");
	cout << " operator>= " << result << endl;
	result = (str1 <= "World");
	cout << " operator<= " << result << endl;
	result = (str1 > "World");
	cout << " operator> " << result << endl;
	result = (str1 < "World");
	cout << " operator< " << result << endl;
}