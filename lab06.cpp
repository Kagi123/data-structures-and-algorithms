//sangheum Park
//cs 2336
//Lab06

#include <cmath>
#include <lab06.h>
  IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
  {
	  IntegerSet myUnion; // declare a local object
	  //manipulate the local object
	  for(uint e = 0; e < N; ++e)
	  {
		  if (this->isMember(e) || otherSet.isMember(e))
			  myUnion.insertElement(e);
	  }
	  return myUnion; // return the local object
  }
  IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
  {
	  IntegerSet myIntersection;
	   for(uint e = 0; e < N; ++e)
	  {
		  if (this->isMember(e) && otherSet.isMember(e))
			  myIntersection.insertElement(e);
	  }
	  return myIntersection;
  }
	  
  IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
  {
	  IntegerSet myDifference;
	   for(uint e = 0; e < N; ++e)
	  {
		  if (this->isMember(e) && !otherSet.isMember(e))
			  myDifference.insertElement(e);
	  }
	  
	  return myDifference;
  }
  IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
  {
	  IntegerSet myUnion(this->Union(otherSet));
	  IntegerSet myIntersection(this->intersection(otherSet));
	  return myUnion.difference(myIntersection);
  }