#include "BoardConfig.hpp"
#include <fstream>
#include <string>

bool loadSnakesAndLadders(const char* filename,
                          int snakes[][2], int& numSnakes, int maxSnakes,
                          int ladders[][2], int& numLadders, int maxLadders)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return false; // could not open file
    }

    numSnakes = 0;
    numLadders = 0;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Expected format: T,from,to   where T is 'S' or 'L'
        // Example: S,16,6
        char type = line[0];

        // find commas
        std::size_t firstComma = line.find(',');
        if (firstComma == std::string::npos)
            continue;

        std::size_t secondComma = line.find(',', firstComma + 1);
        if (secondComma == std::string::npos)
            continue;

        // substrings for from and to
        std::string fromStr = line.substr(firstComma + 1,
                                          secondComma - firstComma - 1);
        std::string toStr = line.substr(secondComma + 1);

        int from = std::stoi(fromStr);
        int to = std::stoi(toStr);

        if (type == 'S')
        {
            if (numSnakes < maxSnakes)
            {
                snakes[numSnakes][0] = from;
                snakes[numSnakes][1] = to;
                numSnakes++;
            }
        }
        else if (type == 'L')
        {
            if (numLadders < maxLadders)
            {
                ladders[numLadders][0] = from;
                ladders[numLadders][1] = to;
                numLadders++;
            }
        }
    }

    file.close();
    return true;
}
