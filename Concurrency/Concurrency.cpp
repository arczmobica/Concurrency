// Concurrency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int f_int()
{
	return 1;
}

using file_content = string;

file_content read_file(string file_name)
{
	ifstream f_in(file_name);
	if (f_in)
	{
		string content;
		string line;
		while (std::getline(f_in, line))
		{
			content += line;
		}
		return content;
	}
	else
	{
		throw Bad_File_Read_Exception{file_name};
	}

}

template<char letter>
int count_occurence_of(file_content str)
{
	int res = std::count(cbegin(str), cend(str), letter);
	return res;
}

string f()
{
	return string{};
}

int real_callback(int val)
{
	cout << "Necessary time passed: " << val << '\n';
	val *= 2;
	return -1;
}

template<bool true_type>
struct Is_Even
{
	static const bool is_even{ true };
	static int accumulate(int val)
	{
		cout << "Adding even numbers\n";
		if (!(val%2))
		{
			return val;
		}
		else
		{
			return 0;
		}
	}
};
template<>
struct Is_Even<false>
{
	static const bool is_even{ false };
	static int accumulate(int val)
	{
		cout << "Adding odd numbers\n";
		if ((val % 2))
		{
			return val;
		}
		else
		{
			return 0;
		}
	}
};

template<class Result_T,class Type, class Iterator>
Result_T accumulate_numbers(Iterator beg, Iterator end)
{
	Result_T result{};
	Result_T intermediate{0};
	while (beg != end)
	{
		result += Type::accumulate(*beg);
		++beg;
	}
	return result;
}


int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	parallel_invoke([&vec] { accumulate_numbers<int, Is_Even<true>>(cbegin(vec), cend(vec)); },
					[&vec] { accumulate_numbers<int, Is_Even<false>>(cbegin(vec), cend(vec)); }
																	);

    return 0;
}

