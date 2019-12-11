# PerfectNumber
A C++ program that finds the first 8 perfect numbers *very* quickly and outputs their parts.

Euclid mentions in *Elements* Book VII, Definition 22 that a Perfect Number is equal to the sum of its parts.

In Book IX, Proposition 36 Euclid mentions a "shortcut" for finding perfect numbers: 2<sup>p-1</sup>(2<sup>p</sup>-1) where 2<sup>p</sup>-1 is a prime number.  The number 2<sup>p</sup>-1 is known as a Mersenne Number and when it is prime it is known as a [Mersenne Prime](https://en.wikipedia.org/wiki/Mersenne_prime/ "Mersenne Prime").

Finding perfect numbers using this method is *much* faster than finding a every number's parts by brute force iteration and then adding them to see if the number is equal to the sum of its parts.  The [Lucas–Lehmer primality test (LLT)](https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test) is a simple and efficient primality test that greatly aids this task, making it very easy to test the primality of Mersenne numbers.
