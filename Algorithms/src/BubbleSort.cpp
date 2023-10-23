#include <vector>

/**
 * Bubble Sort
 * Time complexity: O(n^2)
 */
namespace BubbleSort
{
std::vector<int> Sort(std::vector<int> inNums)
{
    std::vector<int> SortedNums = inNums;
    const int        NumsSize   = static_cast<int>(inNums.size());

    bool HasSwapped = false;
    for (int i = 0; i < NumsSize - 1; ++i)
    {
        HasSwapped = false;

        for (int j = 0; j < NumsSize - 1 - i; ++j)
        {
            const int Left  = SortedNums[j];
            const int Right = SortedNums[j + 1];
            if (Left > Right)
            {
                SortedNums[j]     = Right;
                SortedNums[j + 1] = Left;
                HasSwapped        = true;
            }
        }

        if (!HasSwapped)
        {
            break;
        }
    }

    return SortedNums;
}
} // namespace BubbleSort

TEST(BubbleSortTest, VectorIsSorted)
{
    const std::vector<int> InNums  = {5, 1, 1, 2, 0, 0};
    const std::vector<int> OutNums = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(BubbleSort::Sort(InNums), OutNums);
}
