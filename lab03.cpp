//sangheum Park
//2336
//Lab03

#include <lab03.h>
#include <cmath>


Rational  Rational::add(const Rational& addend) const     // Addition
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
Rational Rational::additiveInverse() const               // Returns the additive 
{
 return Rational(this->getNumerator() * -1, this->getDenominator());
}	
Rational Rational::subtract(const Rational& subtrahend) const // Subtraction
{
	return this->add(subtrahend.additiveInverse());
}
Rational Rational::multiply(const Rational& multiplicand) const // Multiplication
{
	Rational result;
	int num, denom;
	num = getNumerator() * multiplicand.getNumerator();
	denom = getDenominator() * multiplicand.getDenominator();
	result.setNumerator(num);
	result.setDenominator(denom);
	result.reduce();
	return result;
}
Rational Rational::multiplicativeInverse() const              
{
	Rational result;
	int num, denom;
	num = getDenominator();
	denom = getNumerator();
	result.setNumerator(num);
	result.setDenominator(denom);
	result.reduce();
	return result;
}                                           
Rational Rational::divide(const Rational& divisor) const   // Division
{
	Rational result;
	int num, denom;
	num = getNumerator() * divisor.getDenominator();
	denom = getDenominator() * divisor.getNumerator();
	result.setNumerator(num);
	result.setDenominator(denom);
	result.reduce();
	return result;
}
ostream& Rational::print(ostream& os) const              // Print Rational to output    
{
   os << this->getNumerator() << '/' << this-> getDenominator();
   return os;
}	
istream& Rational::read(istream& is)                     // Read Rational from input         
{
int num, denom;
 if( is>> num >> denom)
 {
	 this ->setNumerator(num);
	 this->setDenominator(denom);
 }
 else 
 {
	 this->setNumerator(0);
	 this->setDenominator(1);
 }
 return is;
}	

int Rational::lcm(int m, int n) const   
{
	if ( m == 0 && n == 0) 
		return 0;
	else
		return abs(m * n) / gcd(m,n);
}
