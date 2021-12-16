#include <vector>
#include <fstream>
#include <string>
#include <bitset>
#include <iostream>

std::vector<std::string> take_input()
{
    std::vector<std::string> lines;

    std::ifstream file;
    std::string line;

    file.open("input.txt");

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();

    return lines;
}

std::bitset<12> calc_gamma(std::vector<std::string> reports)
{
    std::bitset<12> gamma = {};

    int zero = 0, one = 0;

    for (int column = 0; column < reports[0].size(); column++)
    {
        for (int i = 0; i < reports.size(); i++)
        {
            auto first_bit = std::bitset<12>(reports[i])[column];
            if (first_bit == 0)
            {
                zero++;
                continue;
            }
            one++;
        }

        if (one >= reports.size() / 2)
        {
            gamma.set(column, 1);
        }
        else
        {
            gamma.set(column, 0);
        }

        zero = 0;
        one  = 0;
    }

    return gamma;
}

int main()
{
    auto reports = take_input();
    auto gamma   = calc_gamma(reports);

    std::cout << gamma.to_ulong() * gamma.flip().to_ulong() << std::endl;

    return 0;
}