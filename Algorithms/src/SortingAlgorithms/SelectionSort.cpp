#include "SortingAlgorithms/Helpers/SortingAlgorithmTestBase.h"

#include <vector>

using namespace SortingAlgorithms;

/**
 * Selection Sort
 * Time complexity: O(n^2)
 */
namespace SelectionSort
{
std::size_t FindSmallestNum(const std::vector<int>& inNums)
{
    std::size_t SmallestNumIndex = 0;
    int         SmallestNum      = inNums[SmallestNumIndex];

    for (std::size_t i = 1; i < inNums.size(); ++i)
    {
        const int Num = inNums[i];
        if (Num < SmallestNum)
        {
            SmallestNum      = Num;
            SmallestNumIndex = i;
        }
    }

    return SmallestNumIndex;
}

std::vector<int> Sort(std::vector<int> inNums)
{
    std::vector<int> SortedNums;

    while (!inNums.empty())
    {
        const std::size_t SmallestNumIndex = FindSmallestNum(inNums);
        const int         SmallestNum      = inNums[SmallestNumIndex];
        SortedNums.emplace_back(SmallestNum);
        inNums.erase(inNums.begin() + SmallestNumIndex);
    }

    return SortedNums;
}

class SelectionSortTest : public SortingAlgorithmTestBase
{
};

TEST_F(SelectionSortTest, VectorIsSorted)
{
    const std::vector<int>& InNums  = GetNums();
    const std::vector<int>  OutNums = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(SelectionSort::Sort(InNums), OutNums);
}
} // namespace SelectionSort