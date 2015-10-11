#pragma once

#include <iostream>
#include <vector>
#include <sstream>

class BigInteger
{
public:

	BigInteger()
	{
		isPositive = true;
		dlimit = 10;
		digits.clear();
	}

	~BigInteger()
	{ 
	}

	void setNumber(int value)
	{
		digits.clear();
		while (value>0)
		{
			int v = value%dlimit;

			value /= dlimit;

			digits.insert(digits.begin(), v);
		}

		deflat();

		trim();

		isPositive = value >= 0;
	}
	 
	void setNumber(std::string str)
	{
		std::string::iterator it;
		it = str.begin();
		while (str.size() > 0 && it!=str.end() && *it == ' ')
		{
			str.erase(it);
			it = str.begin();
		}
		it = str.end();
		while (str.size() > 0 && it != str.end() && *it == ' ')
		{
			str.erase(it);
			it = str.end();
		}

		if (str.size() == 0)
			return; 

		it = str.begin();
		if (*it == '+')
		{
			isPositive = true;
			str.erase(it);
		}
		else if (*it == '-')
		{
			isPositive = false;
			str.erase(it);
		}
		
		for (int i = 0; i < str.size(); ++i)
		{
			if (!isdigit(str[i]))
			{
				return;
			}
		}

		digits.clear();
		for (int i = str.length() - 1; i >= 0; --i)
		{
			addDigit(str[i] - '0');
		}

		deflat();

		trim();
	}

	void addDigit(int value)
	{
		digits.insert(digits.begin(), value);
		deflat();
	}

	int getDigit(int index) const
	{
		if (index<digits.size())
			return digits[index];
		return -1;
	}

	std::string toString()
	{
		std::ostringstream ss;

		for (int i = 0; i<capacity(); ++i)
		{
			ss << getDigit(i);
		}

		return ss.str();
	}

	unsigned long capacity() const
	{
		return digits.size();
	}

	BigInteger operator*(const BigInteger &num)
	{
		return multiply(num);
	}

	BigInteger operator*(const int &num)
	{
		return multiply(num);
	}

	BigInteger operator+(const BigInteger &num)
	{
		return plus(num);
	}

	BigInteger operator+(const int &num)
	{
		return plus(num);
	}

	BigInteger operator-(const BigInteger &num)
	{

	}

	BigInteger operator-(const int &num)
	{

	}
	
protected:

	BigInteger &multiply(const BigInteger &num)
	{
		return (*this);
	}

	BigInteger &multiply(const int &num)
	{
		return (*this);
	}

	BigInteger plus(const BigInteger &num)
	{
		BigInteger sum;

		BigInteger *maxNum = nullptr; //max number
		BigInteger *minNum = nullptr; //min number

		if (num.capacity()>this->capacity())
		{
			maxNum = (BigInteger *)&num;
			minNum = this;
		}
		else
		{
			maxNum = this;
			minNum = (BigInteger *)&num;
		}

		int rem = 0;
		int idx = minNum->capacity() - 1;

		int dist = maxNum->capacity() - minNum->capacity();

		while (idx >= 0)
		{
			int a = maxNum->getDigit(idx+dist);
			int b = minNum->getDigit(idx);

			int s = a + b + rem;

			rem = s / dlimit;

			sum.addDigit(s%dlimit);

			--idx;
		}

		idx = dist - 1;

		while (idx >= 0)
		{
			int s = maxNum->getDigit(idx) + rem;

			rem = s / dlimit;

			sum.addDigit(s%dlimit);

			--idx;
		}

		while (rem>0)
		{
			int v = rem%dlimit;
			sum.addDigit(v);
			rem /= dlimit;
		}

		sum.deflat();

		sum.trim();

		return sum;
	}

	BigInteger plus(const int &num)
	{
		BigInteger d;
		d.setNumber(num);
		return plus(d);
	}

	void deflat()
	{
		int rem = 0;
		for (int i = capacity() - 1; i >= 0; --i)
		{
			int s = (digits[i] + rem);

			rem = s / dlimit;

			if (s%dlimit != digits[i])
			{
				digits[i] = s%dlimit;
			}
		}

		while (rem>0)
		{
			int v = rem%dlimit;
			addDigit(v);
			rem /= dlimit;
		}
	}

	void trim()
	{
		std::vector<int>::iterator it;
		it = digits.begin();
		while (capacity()>1 && *it == 0 && it != digits.end() )
		{ 
			digits.erase(it);
			it = digits.begin();
		}
	} 

	std::vector<int> digits;

	//数组每个元素的位数为log10(dlimit)
	int dlimit;

	bool isPositive;
};
