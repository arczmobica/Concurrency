#pragma once
#include <stdexcept>
class Bad_File_Read_Exception : public std::runtime_error
{
public:
	Bad_File_Read_Exception()=default;
	explicit Bad_File_Read_Exception(std::string file_name);
	virtual ~Bad_File_Read_Exception()=default;
};

