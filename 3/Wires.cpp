#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

struct Point
{
	Point() : x(0), y(0) {};
	Point(int in_x, int in_y) : x(in_x), y(in_y) {};
	int x;
	int y;

	bool operator==(const Point& rh)
	{
		return ((this->x == rh.x) && (this->y == rh.y));
	}
};

void parse_file(std::vector<std::string>& wire_one, std::vector<std::string>& wire_two, char* file_name)
{
    std::ifstream file_in;
    file_in.open(file_name);
    std::string tmp;
    std::string single_inst;

    std::getline(file_in, tmp);
    std::stringstream stream(tmp);
    while (std::getline(stream, single_inst, ','))
    {
		wire_one.push_back(single_inst);
	}

    std::getline(file_in, tmp);
    std::stringstream stream2(tmp);
    while (std::getline(stream2, single_inst, ','))
    {
		wire_two.push_back(single_inst);
	}

    file_in.close();
}

std::vector<Point> traverse(std::vector<std::string> directions)
{
	std::vector<Point> history;

	Point curr_point;
	for (auto it : directions)
	{
		char dir = it[0];
		int len = std::stoi(&it[1]);

		if (dir == 'U')
		{
			curr_point.y += len;
		}
		else if (dir == 'D')
		{
			curr_point.y -= len;
		}
		else if (dir == 'L')
		{
			curr_point.y -= len;
		}
		else if (dir == 'R')
		{
			curr_point.x += len;
		}
		else
		{
			std::cerr << "invalid dir: " << dir << std::endl;
		}
		history.push_back(curr_point);
	}

	return history;
}

int find_closest_intersect(std::vector<Point>& wire_one_history, std::vector<Point>& wire_two_history)
{
	std::vector<Point> intersects;
	for (auto pt_one : wire_one_history)
	{
		for (auto pt_two : wire_two_history)
		{
			if (pt_two == pt_one)
			{
				intersects.push_back(pt_one);
			}
		}
	}

	for (auto res : intersects)
	{
		std::cout << res.x << "," << res.y << std::endl;
	}

	return 0;
}

int get_man_distance(const Point& lh, const Point& rh)
{
	return (abs(lh.x-rh.x) + abs(lh.y-rh.y));
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./intcode input_file" << std::endl;
        return 1;
    }

    std::vector<std::string> wire_one;
    std::vector<std::string> wire_two;
    parse_file(wire_one, wire_two, argv[1]);

    std::vector<Point> wire_one_history = traverse(wire_one);
    std::vector<Point> wire_two_history = traverse(wire_two);

    find_closest_intersect(wire_one_history, wire_two_history);


    return 0;
}