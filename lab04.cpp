



//sangheum Park
//cs 2336
//Lab04

#include <lab04.h>

IntegerSet::IntegerSet()
{
  allocateStorage();
  //Loop through the universe, calling deleteElement
  //for each possible element
  uint e;
  for (e=0; e< N; ++e)
	  deleteElement(e);
}	
                                       
IntegerSet::IntegerSet(const IntegerSet& otherSet)
{
	allocateStorage();
	uint e;
	
	for(e = 0; e < N; ++e)
	{	
		if(otherSet.isMember(e)) insertElement(e);
	    else deleteElement(e);	
	}
}
IntegerSet::~IntegerSet()
{
	delete [] bitVector;
}
bool IntegerSet::isMember(uint e) const
{
   // getBit:  get value of bit n in word.
   //unsigned int getBit(unsigned int word, int n);
   if(isValid(e)) 
   {
	    uint myWord = bitVector[word(e)];
        int n = bit(e);
   
        return getBit(myWord, n);
   }
   
   return false;
   
}
                                         
uint IntegerSet::cardinality() const
{
	uint i = 0;
	for (uint e = 0; e < N; ++e)
	{
		if( this->isMember(e)) i++;
	}
	return i;
}

void IntegerSet::insertElement(uint e)
{
   // setBit:  return value with bit n set to v (0 or 1).
   //unsigned int setBit(unsigned int word, int n, unsigned int v);
   if(isValid(e) && !isMember(e))
   {
	    uint myWord = bitVector[word(e)];
        int n = bit(e);
		
	    myWord = setBit(myWord, n, 1);
		bitVector[word(e)] = myWord;
   }
}	
void IntegerSet::deleteElement(uint e)
{
	if (isValid(e) && isMember(e))
	{
		bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), 0);
	}
}
                                         
IntegerSet IntegerSet::complement() const
{
	IntegerSet myComplement;
	
	uint e;
	for(e = 0; e < N; ++e)
	{	
		if(isMember(e)) myComplement.deleteElement(e);
		else            myComplement.insertElement(e);	
	}
	
	return myComplement;
}
 
ostream& IntegerSet::print(ostream& os) const
{
	bool printComma = false;
	if (this->cardinality() == 0)
	{
		os << static_cast<char>(216) << endl;
	}
	else
	{
		os << '{';
		for (uint e = 0; e < N; ++e)
		{
			if( this->isMember(e))
			{
				if (printComma)
					os << ",";
				os << e;
				printComma = true;
			}
		}
		os << '}' << endl;
	}
	
	return os;	
}

bool IntegerSet::isValid(uint e) const
{
	return (0 <= e && e < N);
}
