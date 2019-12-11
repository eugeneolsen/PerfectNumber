# PerfectNumber
A C++ program that finds the first 8 perfect numbers *very* quickly and outputs their parts.

Euclid mentions in *Elements* Book VII, Definition 22 that a Perfect Number is equal to the sum of its parts.

In Book IX, Proposition 36 Euclid mentions a "shortcut" for finding perfect numbers: 2<sup>p-1</sup>(2<sup>p</sup>-1) where 2<sup>p</sup>-1 is a prime number.  The number 2<sup>p</sup>-1 is known as a Mersenne Number and when it is prime it is known as a [Mersenne Prime](https://en.wikipedia.org/wiki/Mersenne_prime/ "Mersenne Prime").

Finding perfect numbers using this method is *much* faster than finding a every number's parts by brute force iteration and then adding them to see if the number is equal to the sum of its parts.  The [Lucas–Lehmer primality test (LLT)](https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test) is a simple and efficient primality test that greatly aids this task, making it very easy to test the primality of Mersenne numbers with a minimum of computing overhead.

Now that we have found a perfect number, we find its parts by working backward.  We start by iteratively dividing by 2, since we have multiplied the Mersenne Prime number by 2<sup>p-1</sup>, and pushing each half as a part onto a LIFO stack so that we can later output the parts in numerical order.  When we reach the Mersenne Prime number, we push it onto the stack and add one to it before dividing by 2.   Then continue dividing by 2 and pushing each part onto the stack until we reach 1.   We can now pop each part from the stack in order to output the parts in numerical order.  As we pop each part from the stack, we can also add the parts together to confirm that the sum of the parts is equal to the perfect number discovered by 2<sup>p-1</sup>(2<sup>p</sup>-1).
