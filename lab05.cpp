//sangheum Park
//cs 2336
//Lab05

#include <lab05.h>


bool Rational::isEqualTo(const Rational& other) const
{
	return this->subtract(other).getNumerator() == 0;
}
bool Rational::isNotEqualTo(const Rational& other) const
{
	return !(this->isEqualTo(other));
}
bool Rational::isLessThan(const Rational& other) const
{
	return this->subtract(other).getNumerator() < 0;
}
bool Rational::isLessThanOrEqualTo(const Rational& other) const
{
	return this->subtract(other).getNumerator() <= 0;
}
bool Rational::isGreaterThan(const Rational& other) const
{
	return this->subtract(other).getNumerator() > 0;
}
bool Rational::isGreaterThanOrEqualTo(const Rational& other) const
{
	return this->subtract(other).getNumerator() >= 0;
}