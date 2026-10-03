#include <iostream>
#include <string>
//#include <conio.h>
#include <stdexcept>
using namespace std;

class Processing
{
private:
	string number;
public:
	void InputNumber()
	{
		cout << "Enter a number or numbers: ";
		cin >> number;
	}

	int Calculate()
	{
		int result = 0;

		for (int i = 0; i < number.length(); i++)
		{
			if (result > 2147483647)
			{
				throw runtime_error("Number is too large");
			}

			int digit = number[i] - '0';

			result = result * 10;
			result = result + digit;
		}

		return result;
	}


};

int main()
{
	Processing p;

	p.InputNumber();

	try
	{
		cout << "Result: " << p.Calculate();
	}
	catch (const runtime_error& e)
	{
		cout << "Error: " << e.what();
	}
}