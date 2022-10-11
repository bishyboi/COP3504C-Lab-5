#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"

int linearSearch(std::vector<std::string> container, std::string element)
{
    for( int word_idx=0; word_idx<container.size(); word_idx++)
    {
        if (container[word_idx]==element)
            return word_idx;
    }

    return -1;
}

int binarySearch(std::vector<std::string> container, std::string element, int startIndex, int endIndex)
{
    int min_idx = startIndex;
    int max_idx = endIndex;
    int middle_idx = min_idx+ (max_idx-min_idx)/2;

    if (min_idx > max_idx)
        return -1;
    else if (container[middle_idx] == element)
    {
        return middle_idx;
    }
    else
    {
        if (element < container[middle_idx])
        {
            //Slice the container into the lower half
            return binarySearch(container, element, min_idx, middle_idx-1);
        }
        else
        {
            //Slice container into upper half
            return binarySearch(container, element, middle_idx+1, max_idx);
        }
    }
}

int main()
{
    std::vector<std::string> stringData = getStringData();
    //std::vector<std::string> testString = {"not_here", "aaaaa", "mzzzz", "aegfe", "gerbe", "hello", "zzzzz"};
    std::vector<std::string> testString = {"aaaaa", "gerbe", "hello", "zzzzz"};

    for(std::string searchWord:testString)
    {
        std::cout<<"Search Term: " << searchWord <<std::endl;
        std::cout<<"Linear: "<<linearSearch(stringData, searchWord)<<std::endl;
        std::cout<<"Binary: "<<binarySearch(stringData, searchWord,0, stringData.size()-1)<<std::endl<<std::endl;
    }
    return 0;
}