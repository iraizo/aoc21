#include <vector>
#include <fstream>
#include <string>

enum cmds
{
    FORWARD,
    DOWN,
    UP
};

struct submarine
{
    int x   = 0;
    int y   = 0;
    int aim = 0;

    void input(int cmd, int unit)
    {

        switch (cmd)
        {
        case cmds::FORWARD:
        {
            x += unit;
            y += aim * unit;
            break;
        }
        case cmds::UP:
        {
            //  y -= unit;
            aim -= unit;
            break;
        }
        case cmds::DOWN:
        {
            // y += unit;
            aim += unit;
            break;
        }
        }
        printf("x: %i, y: %i, aim: %i\n", x, y, aim);
    }
};

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

int main()
{
    auto input = take_input();

    int unit = 0;
    int cmd  = 0;

    submarine sub;

    /* format*/
    for (auto &line : input)
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                unit = std::atoi(&line[i]);
                line.erase(line.begin() + i);
            }
        }
        std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());

        if (line == "forward")
        {
            cmd = cmds::FORWARD;
        }
        if (line == "down")
        {
            cmd = cmds::DOWN;
        }

        if (line == "up")
        {
            cmd = cmds::UP;
        }
        sub.input(cmd, unit);
    }

    printf("%i", sub.x * sub.y);
}