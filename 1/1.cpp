#include <vector>
#include <fstream>

std::vector<int> take_input()
{
    std::ifstream is("input.txt");
    std::istream_iterator<int> start(is), end;
    return std::vector<int>(start, end);
}

int main()
{
    auto sonar_scan = take_input();

    int result = 0;

    for (int i = 0; i < sonar_scan.size(); i++)
    {
        if (sonar_scan[i] < sonar_scan[i + 1])
        {
            result++;
        }
    }
    printf("%i", result);

    return 0;
}