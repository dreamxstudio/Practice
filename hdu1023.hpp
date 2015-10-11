/*
*
*/

#ifndef hdu1023_h
#define hdu1023_h

#include "BigInteger.hpp"

void catalan(const std::string &inputNum )
{
	BigInteger sNum;
	sNum.setNumber(inputNum);
   
	BigInteger result = sNum + sNum;

	std::cout << result.toString() << std::endl;
}

void run()
{
	std::string inputNum;
	for (; std::cin >> inputNum;)
	{
		catalan(inputNum);
	}
}

#endif  
