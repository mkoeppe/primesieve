///
/// @file   nth_prime1.cpp
/// @brief  Test nth_prime for |n| <= 9592
///
/// Copyright (C) 2017 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License. See the COPYING
/// file in the top level directory.
///

#include <primesieve.hpp>

#include <stdint.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace primesieve;

void check(bool isCorrect)
{
  cout << "   " << (isCorrect ? "OK" : "ERROR") << "\n";
  if (!isCorrect)
    throw runtime_error("test failed!");
}

int main()
{
  try
  {
    uint64_t upperBound = (uint64_t) 1e5;
    vector<uint64_t> primes;
    generate_primes(upperBound, &primes);
    int64_t i = primes.size() - 1;
    int64_t n = 0;

    // nth_prime(n) forwards
    for (uint64_t prime : primes)
    {
      n++;
      uint64_t res = nth_prime(n);
      cout << "nth_prime(" << n << ") = " << res;
      check(res == prime);
    }

    // nth_prime(-n, start) backwards
    for (n = 0; i >= 0; i--)
    {
      n--;
      uint64_t res = nth_prime(n, upperBound);
      cout << "nth_prime(" << n << ", " << upperBound << ") = " << res;
      check(res == primes[i]);
    }

    cout << endl;
    cout << "All tests passed successfully!" << endl;
  }
  catch (exception& e)
  {
    cerr << endl << "primesieve error: " << e.what() << endl;
    return 1;
  }

  return 0;
}
