#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void parse_file(std::vector<int>& input, char* file_name)
{
    std::ifstream file_in;
    file_in.open(file_name);
    std::string tmp;
    while (std::getline(file_in, tmp))
    {
        input.push_back(std::stoi(tmp));
    }
    file_in.close();
}

unsigned long int sum_fuel_req(std::vector<int>& input)
{
    unsigned long int sum = 0;
    int curr_mass = 0;
    for (auto i : input)
    {
        // Calculate mass of module and additional fuel until expression mass/3 - 2 is <= 0
        curr_mass = (i/3) - 2;
        while (curr_mass > 0)
        {
            sum += curr_mass;
            curr_mass = (curr_mass/3) - 2;
        }
    }       
    return sum;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./mass input_file" << std::endl;
        return 1;
    }

    std::vector<int> masses;
    parse_file(masses, argv[1]);
    std::cout << sum_fuel_req(masses) << std::endl;
 
    return 0;
}
