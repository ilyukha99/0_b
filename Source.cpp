#include "head.h"

Parser::Parser(const std::string &file_name) :_file(file_name) { //initializer list
}

void Parser::fill_the_map() {

	std::string buffer = "";
	std::string str;
	while (!_file.eof()) {
		getline(_file, str);
		buffer = "";
		for (unsigned int i = 0; i < str.length(); i++) {
			if (isdigit((unsigned char)str[i]) || isalpha((unsigned char)str[i]))
				buffer += str[i];
			else if (buffer != "") {
				my_map[buffer]++;
				word_counter++;
				buffer = "";
			}
		}
		if (buffer != "") {
			my_map[buffer]++;
			word_counter++;
		}

	}
}


void Parser::write_down_all_outputs(const std::string &csv_file) {
	std::vector <std::pair<int, std::string>> my_vector;

	for (auto it = my_map.begin(); it != my_map.end(); ++it)
		my_vector.push_back(std::pair<int, std::string>(it->second, it->first));
	std::sort(my_vector.begin(), my_vector.end(), std::greater<std::pair<int, std::string>>());

	std::ofstream file(csv_file);
	for (auto it = my_vector.begin(); it != my_vector.end(); ++it)
		file << it->second << ", " << it->first << ", "
		<< ((double)it->first / word_counter) * 100 << "%" << std::endl;
}


//for (auto it : my_map)
//my_vector.emplace_back(it.second, it.first);

// it = std::map<>::iterator
// *it = pair<STRING,INT>

//, [](std::pair<int, std::string>& lhs,
//	std::pair<int, std::string>& rhs) {
//	return  lhs > rhs;
//}