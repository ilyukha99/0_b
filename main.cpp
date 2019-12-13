#include "head.h"

int main(int argc, char **argv) {

	setlocale(LC_ALL, "rus");

	if (argc != 3)
		return NUMBER_OF_ARGUMENTS_ERR;

	std::string txt_name;
	std::string csv_name;
	txt_name = argv[1];
	csv_name = argv[2];

	Parser parser(txt_name);

	parser.fill_the_map();
	parser.write_down_all_outputs(csv_name);

	system("pause");
	return 0;
}