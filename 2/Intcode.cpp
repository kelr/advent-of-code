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

void run(std::vector<int>& input)
{
    auto it = input.begin();

    while (it < input.end())
    {
        int lh = *(it+1);
        int rh = *(it+2);
        int result = *(it+3);
        if (*it == 1)
        {
            //std::cout << *it << " " << lh << " " << rh << " " << result << std::endl;
            input[result] = input[lh] + input[rh]; 
        }
        else if (*it == 2)
        {   
            //std::cout << *it << " " << lh << " " << rh << " " << result << std::endl;
            input[result] = input[lh] * input[rh];
        }
        else if (*it == 99)
        {
            //std::cout << "BREAK" << std::endl;
            break;
        }
        else
        {
            std::cerr << "Invalid opcode: " << *it << std::endl;
        }
        it+=4;
    }       
}

int find_noun_verb(std::vector<int>& og_state, const int target)
{
    // Initialize so that index 0 has something
    std::vector<int> curr_run {0};

    for (int noun = 0; noun < 100; ++noun)
    {
        for (int verb = 0; verb < 100; ++verb)
        {
            curr_run = og_state;
            curr_run[1] = noun;
            curr_run[2] = verb;
            run(curr_run);
            if (curr_run[0] == target)
            {
                return 100 * noun + verb;
            }
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./intcode input_file" << std::endl;
        return 1;
    }
    const int TARGET = 19690720;
    std::vector<int> og_state;
    parse_file(og_state, argv[1]);
    
    std::cout << find_noun_verb(og_state, TARGET) << std::endl;
 
    return 0;
}

