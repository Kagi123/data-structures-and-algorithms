//sangheum Park
//Lab 01

#include <iostream>
#include <string>

using namespace std;

uint productOfDigits(uint num);  
const string ID = "sangheum Park = CS 2336 = lab 01\n\n";


int main() 
{
	uint num;
	
	cout << ID;
	
	while(cin >> num)
	{
		cout << num;
		cout << productOfDigits(num) << endl;
	}
	
	return 0;
}

	uint productOfDigits(uint num)
	{
		uint digit, product;
		product = 1;
		int cnt = 0;
		while(num > 9) 
		{
		 while(num != 0) 
		{
			// calculate the rightmost digit of num
			digit = num % 10;
			//incorporate digit into product
			product = product * digit;
			// eliminate the rightmost digit from num
			num = num / 10;
		}
		cnt++;
		cout << " -> " << product;
		
		num = product;
		product = 1;
		}
		
		cout << " persistence= ";
		return cnt;
	}
	

