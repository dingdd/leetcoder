#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
    static const int _max=46341;
    int square[_max];

public:
    Solution()
    {
        for(int i=0; i<_max; i++)
            square[i]=i*i;
    }
    int sqrt(int x)
    {
        if(x<0)
            return -1;
        int *p=upper_bound(square,square+_max,x);
        p--;
        return p-square;
    }
};

int main()
{
    Solution s;
    int x=0;
    cout <<s.sqrt(4) <<endl;
    return 0;
}
