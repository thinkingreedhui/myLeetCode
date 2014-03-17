#include <iostream>
#include "removeElements.h"
using namespace std;

int main()
{
    int A[10] = {
        1,3,5,3,6,9,8,90,34,3
    };
    Solution s;
    cout << flush<<s.removeElement(A,10,3) << endl;
    return 0;
}
