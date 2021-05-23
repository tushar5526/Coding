// 10111010

// count total set bits

// sum = bits req - 1 c set bits - 1

// for each set bits except first
// sum += count non set bits

#include <bits/stdc++.h>

using namespace std;

long long ncr(long long n, long long r)
{

    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}

long long calc_bits(long long n)
{
    long long bitsreq = 1;

    while (pow(2, bitsreq) <= n)
        ++bitsreq;
    return bitsreq;
}
void sudo_main(long long n)
{

    long long setbits = 0;
    long long unset = 0;
    long long tmp = n;
    long long sum = 0;

    long long bitsreq = calc_bits(n);

    for (int i = 0; i < bitsreq; ++i)
    {
        int mask = 1 << i;
        if (mask & n)
        {
            ++setbits;
            if (i != bitsreq - 1)
                sum += unset;
        }
        else
            ++unset;
    }
    // cout << "set bits and unset bitsreq " << setbits << " " << unset << " " << bitsreq << endl;
    // if (setbits != -1)
    //     cout << "comb is " << ncr(bitsreq - 1, setbits) << endl;
    // cout << "sum is " << sum << endl;
    if (bitsreq - 1 >= setbits)
        sum += ncr(bitsreq - 1, setbits);
    // cout << "ANS "<< sum << endl;
    cout << n << " " << sum << endl;
}

int main()
{
    long long n;
    // cin>>n;
    // sudo_main(4);
    for (int i = 1; i <= 50; ++i)
        sudo_main(i);
}
