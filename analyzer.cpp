#include "StringData.h"
#include <iostream>
#include <chrono>

int linearSearch(std::vector<std::string> container, std::string element)
{
    for(int i = 0; i < container.size(); i++)
    {
        if(container[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> container, std::string element)
{
    int min = 0;
    int max = container.size() - 1;
    while(min <= max)
    {
        int mid = (min + max) / 2;
        if(container[mid] == element)
        {
            return mid;
        }
        else if(container[mid] > element)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<std::string> data = getStringData();

    std::cout << "Search 'mzzzz' with linear_search" << "\n";
    auto linear_start = std::chrono::system_clock::now();
    int linear_result = linearSearch(data, "mzzzz");
    auto linear_end = std::chrono::system_clock::now();
    std::chrono::duration<double> linear_time_delta = linear_end - linear_start;

    std::cout << "Search 'mzzzz' with binary_search" << "\n";
    auto binary_start = std::chrono::system_clock::now();
    int binary_result = binarySearch(data, "mzzzz");
    auto binary_end = std::chrono::system_clock::now();
    std::chrono::duration<double> binary_time_delta = binary_end - binary_start;

    std::cout << "Linear index: " << linear_result << "\n";
    std::cout << "Binary index: " << binary_result << "\n";
    std::cout << "Linear time: "  << linear_time_delta.count() << " s" << "\n";
    std::cout << "Binary time: "  << binary_time_delta.count() << " s" << "\n";

    return -1;
}