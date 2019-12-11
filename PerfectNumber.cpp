// PerfectNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// Perfect Number
// Euclid's Elements, Book VII, Definition 22:
// A perfect number is that which is equal to its own parts.
// E.g. 6 = 1 + 2 + 3
// Book IX, Proposition 36 explains how a perfect number is formed.
// Euclid showed that 2 raised to the p-1 power times (2 raised to the p power) minus 1 when the latter is prime, is a perfect number
// As of 2019 there are 51 known Perfect Numbers and no known odd perfect numbers


// Lucas–Lehmer primality test
// For prime p > 2, M sub p = 2 raised to the p − 1 power is prime if and only if M sub p divides (S sub p) − 2, where S0 = 4 and S sub k = ((S sub k) − 1) squared − 2 for k > 0\
// See https://en.wikipedia.org/wiki/Mersenne_prime#Searching_for_Mersenne_primes and https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
bool IsMersennePrime(long long M, int p)
{
    long long s = 4;

    for (int i = 0; i < p - 2; i++)
    {
        s = ((s * s) - 2) % M;
    }

    return (s == 0) ? true : false;
}

// Get the parts of the Perfect Number
void GetParts(long long perfect, stack<long long>& parts)
{
    // Divide the perfect number by 2 until the quotient is an odd number.  
    // If the quotient is odd, add one and continue dividing by 2
    long long part = perfect;

    do
    {
        if (part % 2 == 1)  // if the part is odd
        {
            part++; // add one before dividing
        }

        part = part / 2;

        parts.push(part);

    } while (part > 1);
}

int main()
{
    bool isPerfect = false;

    cout << "Perfect Numbers\n\n"; 

    for (int p = 2; p < 32; p++)
    {
        long long M = (long long)pow(2.0, p) - 1;

        if (IsMersennePrime(M, p) || p == 2)
        {
            long long perfect = (long long)pow(2.0, p - 1) * M;

            cout << perfect;

            stack<long long> parts;

            GetParts(perfect, parts);

            cout << " = ";

            long long sum = 0;  // for validation

            while (parts.size())
            {
                if (parts.top() > 1)
                {
                    cout << " + ";
                }

                sum += parts.top(); // for validation

                cout << parts.top();

                parts.pop();
            }

            _ASSERT(sum == perfect);    // validate that the sum of the parts is the Perfect Number

            cout << "\n\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
