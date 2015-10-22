#include "stdafx.h"
#include "Bad_File_Read_Exception.h"


//Bad_File_Read_Exception::Bad_File_Read_Exception()
//{
//}


//Bad_File_Read_Exception::~Bad_File_Read_Exception()
//{
//}


Bad_File_Read_Exception::Bad_File_Read_Exception(std::string file_name):runtime_error(file_name)
{
	cout << "Cannot open\n" << file_name << '\n';
}