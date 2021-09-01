//sangheum Park
//cs 2336
//lab 02

#include <lab02.h>
#include <cmath>
#include <cstdlib>

Rational::Rational() 
    : Rational(0,1)
    {

	}	
Rational::Rational(int num, int denom)
{
	setNumerator(num);
	setDenominator(denom);
}	
void Rational::setNumerator(int num)     
{
   data.first = num;
}   
void Rational::setDenominator(int denom) 
{
  data.second = (denom == 0) ? 1: denom;
}	
int Rational::getNumerator() const   
{
 return data.first;
}	
int Rational::getDenominator() const
{
 return data.second;
}	

void Rational::reduce()   
{
   int myGcd = gcd(getNumerator(), getDenominator());
   
   if(getDenominator() <0) 
	   myGcd = - myGcd;
   
   setNumerator(getNumerator() / myGcd);
   setDenominator(getDenominator() / myGcd);


}	
int Rational::gcd(int m, int n) const        
{
	if(m == 0) 
		return abs(n);
	else if (n == 0)
		return abs(m);
	else // use Euclid's algorithm
	{
		m = abs(m);
		n = abs(n);
		int rem = m % n;
		while ( rem != 0) 
		{
			m = n;
			n = rem;
			rem = m % n;
		}
		return n;
	}
	
}

