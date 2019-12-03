#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void parse_file(std::vector<int>& input, char* file_name)
{
	std::ifstream file_in;
    file_in.open(file_name);
	std::string tmp;
	while (std::getline(file_in, tmp, ','))
	{
		input.push_back(std::stoi(tmp));
	}
    file_in.close();
}

void parse_opcodes(std::vector<int>& input)
{
    auto it = input.begin();

    while (it < input.end())
    {
        int lh = *(it+1);
        int rh = *(it+2);
        int result = *(it+3);
    	if (*it == 1)
		{
            std::cout << *it << " " << lh << " " << rh << " " << result << std::endl;
			input[result] = input[lh] + input[rh]; 
		}
		else if (*it == 2)
		{   
            std::cout << *it << " " << lh << " " << rh << " " << result << std::endl;
			input[result] = input[lh] * input[rh];
		}
		else if (*it == 99)
		{
            std::cout << "BREAK" << std::endl;
			break;
		}
		else
		{
			std::cerr << "Invalid opcode: " << *it << std::endl;
		}
        it+=4;
	}		
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
        std::cerr << "Usage: ./intcode input_file" << std::endl;
		return 1;
	}
	std::vector<int> values;
    parse_file(values, argv[1]);
    //std::vector<int> values {2, 4, 4, 5, 99, 0};
    parse_opcodes(values);
 
    for (auto it = values.begin(); it != values.end(); ++it)
	{
		std::cout << *it << ",";
	}
    return 0;
}

