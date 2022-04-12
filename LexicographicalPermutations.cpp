#include <iostream>
#include <algorithm>
using namespace std;

void permutations(string str)
{
    sort(str.begin(), str.end());
    while (1)
    {
        cout << str << " ";
        if (!next_permutation(str.begin(), str.end())) {
            break;
        }
    }
}

int main()
{
    string str;
    cin>>str;
    permutations(str);
    return 0;
}
