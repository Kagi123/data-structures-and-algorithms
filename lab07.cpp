//sangheum Park
//Cs 2336
//Lab07

#include <lab07.h>

istream& operator>>(istream& in, Rational& rat)
{
int num, denom;
 if( in>> num >> denom)
 {
	rat.setNumerator(num);
	 rat.setDenominator(denom);
 }
 else 
 {
	rat.setNumerator(0);
	 rat.setDenominator(1);
 }
 return in;
}
 
ostream& operator<<(ostream& out, const Rational& rat) 
{
   out << rat.getNumerator() << '/' << rat.getDenominator();
   return out;
}
Rational& Rational::operator=(const Rational& rhs) 
{
	if(this != &rhs) 
	{
	this->setNumerator(rhs.getNumerator());
	this->setDenominator(rhs.getDenominator());
	}
	return *this;
	
}	
Rational Rational::operator+(const Rational& addend) const
{
	Rational sum; // declare a local object
	int lhs, rhs;
	int myLCM = lcm(this-> getDenominator(), addend.getDenominator() );
	lhs = myLCM / this->getDenominator() * this->getNumerator();
	rhs = myLCM / addend.getDenominator() * addend.getNumerator();
	//manipulate the local object's data
	sum.setNumerator(lhs+rhs);
	sum.setDenominator(myLCM);
	sum.reduce();
	
	return sum; // return the local object
}
Rational Rational::operator-() const  
{
	 return Rational(this->getNumerator() * -1, this->getDenominator());
}	
Rational Rational::operator-(const Rational& subtrahend) const
{
	//return this->add(subtrahend.additiveInverse());
	return *this + -subtrahend;
}
  Rational Rational::operator*(const Rational& multiplicand) const
  {
	Rational prod;
	prod.setNumerator(getNumerator() * multiplicand.getNumerator());
	prod.setDenominator(getDenominator() * multiplicand.getDenominator());
	prod.reduce();
	return prod;
}
  Rational Rational::operator/(const Rational& divisor) const
  {
	Rational multInv;
	
	multInv = divisor.multiplicativeInverse();
	
	return multInv * *this;
  }

bool Rational::operator==(const Rational& rhs) const    
{
	  return (*this - rhs).getNumerator() == 0;
}
bool Rational::operator!=(const Rational& rhs) const    
{
	return !(*this  == rhs);
}

bool Rational::operator< (const Rational& rhs) const
{
	return (*this  - rhs).getNumerator() < 0;
}	
bool Rational::operator<=(const Rational& rhs) const
{
	return *this < rhs || *this == rhs;
}  
bool Rational::operator> (const Rational& rhs) const 
{
	return !(*this < rhs || *this == rhs);
}  
bool Rational::operator>=(const Rational& rhs) const   
{
	return !(*this < rhs);
}