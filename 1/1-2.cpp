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

    std::vector<std::vector<int>> measurements;

    /* format */
    for (int i = 0; i < sonar_scan.size(); i++)
    {
        std::vector<int> measurement = { sonar_scan[i], sonar_scan[i + 1], sonar_scan[i + 2] };
        measurements.push_back(measurement);
    }

    /* calculate sums */
    std::vector<int> sums;
    for (auto &measurement : measurements)
    {
        sums.push_back(measurement[0] + measurement[1] + measurement[2]);
    }

    /* compare */
    int result = 0;

    for (int i = 0; i < sums.size(); i++)
    {
        if (sums[i] < sums[i + 1])
        {
            result++;
        }
    }

    printf("%i", result);

    return 0;
}