#include <iostream>
#include <vector>
#include <chrono>
const int MaxCount = 150000;
using namespace std;

bool IsPrimeNumber(int number)
{
    if (number == 1)
        return false;
    if (number == 2 || number == 3)
        return true;
    for (int idx = 2; idx < number - 1; ++idx)
    {
        if (number % idx == 0)
            return false;
    }
    return true;
}

void PrintNumbers(const vector<int>& primes)
{
    for (int v : primes)
        cout << v << '\n';
}

int main()
{
    vector<int> primes;

    auto t0 = chrono::system_clock::now();

    for (int idx = 1; idx < MaxCount; ++idx)
    {
        if (IsPrimeNumber(idx))
        {
            primes.push_back(idx);
        }
    }
    auto t1 = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
    cout << "Took" << duration << " mileseconds." << '\n';
    PrintNumbers(primes);
}
