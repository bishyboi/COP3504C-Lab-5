#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "StringData.h"

int linearSearch(std::vector<std::string> container, std::string element);
int binarySearch(std::vector<std::string> *containerPtr, std::string element, int startIndex, int endIndex);

int main()
{
    std::vector<std::string> stringData = getStringData();
    std::vector<std::string> testString = {"not_here", "aaaaa", "mzzzz", "aegfe", "gerbe", "hello", "zzzzz"};

    for(std::string searchWord:testString)
    {
        std::cout<<"Search Term: " << searchWord <<std::endl;
        long long initTime = systemTimeNanoseconds();
        
        std::cout<<"Linear: " << linearSearch(stringData, searchWord) << std::endl;
        long long linTime = systemTimeNanoseconds();

        std::cout<<"Linear Time: " << linTime-initTime << "ms" << std::endl;

        std::cout<<"Binary: " << binarySearch(&stringData, searchWord,0, stringData.size()-1) << std::endl;
        long long binTime = systemTimeNanoseconds();

        std::cout<<"Binary Time: " << binTime-linTime << "ms"<< std::endl<<std::endl;
    }

    return 0;
}

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

int binarySearch(std::vector<std::string> *containerPtr, std::string element, int startIndex, int endIndex)
{
    int min_idx = startIndex;
    int max_idx = endIndex;
    int middle_idx = min_idx+ (max_idx-min_idx)/2;

    if (min_idx > max_idx)
        return -1;
    else if ((*containerPtr)[middle_idx] == element)
    {
        return middle_idx;
    }
    else
    {
        if (element < (*containerPtr)[middle_idx])
        {
            //Slice the container into the lower half
            return binarySearch(containerPtr, element, min_idx, middle_idx-1);
        }
        else
        {
            //Slice container into upper half
            return binarySearch(containerPtr, element, middle_idx+1, max_idx);
        }
    }
}