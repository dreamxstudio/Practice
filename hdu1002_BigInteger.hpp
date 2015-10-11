#pragma once

#include "BigInteger.hpp"

#include <iostream>
#include <string>

void run()
{
	std::string a, b;
	int nCase;

	for (;std::cin>>nCase;)
	{ 
		for (int index = 1; index <= nCase;++index)
		{
			std::cin >> a >> b;
			BigInteger bA;
			bA.setNumber(a);
			BigInteger bB;
			bB.setNumber(b);

			BigInteger result = bA + bB;

			std::cout << "Case " << index <<":" << std::endl;
			std::cout << a << " + " << b << " = " << result.toString() << std::endl;
			if(index!=nCase)
				std::cout<< std::endl;
		}
	}
}