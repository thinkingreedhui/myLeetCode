#include <iostream>

using namespace std;
long long permutation(int m, int n){
        long long result = 1;
        int k = m-n;
        for(int i = m; i > k ; i--){
            result *= i;
        }
        return result;
}
long long factorial(int n){
        long long result = 1;
        for(int j = n; j > 0; j--)
            result *= j;
        return result;
}
int main()
{
    long long m = permutation(18,9);
    long long n = factorial(9);

    cout<<m/(n*10)<<endl;
    return 0;
}
