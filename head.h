#pragma once
#ifndef HEADER
#define HEADER

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#define NUMBER_OF_ARGUMENTS_ERR -1

class Parser {

private:

	std::ifstream _file;
	std::map <std::string, int> my_map;
	int word_counter = 0;

public:
	Parser(const std::string &file_name);
	void fill_the_map();
	void write_down_all_outputs(const std::string &csv_file);
};

#endif //HEADER!