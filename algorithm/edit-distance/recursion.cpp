#include <bits/stdc++.h>

int min(int x, int y, int z) { return std::min(std::min(x, y), z); }

int editDist(std::string str1, std::string str2, int m, int n)
{
    // If str1 is empty, 
    // the only option is to insert all characters of str2 into str1
    if (m == 0)
        return n;
    
    // If str2 is empty, 
    // the only option is to remove all characters of str1
    if (n == 0)
        return m;

    // If last characters of two strings are the same
    // get count for the remaining strings.
    if (str1[m-1] == str2[n-1])
        return editDist(str1, str2, m-1, n-1);

    // If last characters are not the same,
    // consider all three operations on last character of str1,
    // recursively compute minimum cost for al
    return 1 + min(editDist(str1, str2, m, n-1),    // Insert
                   editDist(str1, str2, m-1, n),    // Remove
                   editDist(str1, str2, m-1, n-1)); // Replace
}

int main() 
{
    std::string str1 = "sunday";
    std::string str2 = "saturday";

    std::cout << "the minimum number of edits (operations) is " 
              << editDist(str1, str2, str1.length(), str2.length()) << std::endl;
    return 0;
}

/*
Time Complexity: O(3^m)
Auxiliary Space: O(1)
*/