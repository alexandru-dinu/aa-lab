A prime gap g<sub>n</sub> is defined as the difference between two consecutive primes: g<sub>n</sub> = p<sub>n+1</sub> - p<sub>n</sub>. The `primeGap` problem asks if its input, `x`, is a prime gap (i.e. there exists two consecutive prime numbers with distance `x`)

It's easy to write a piece of code (Turing Machine) that always returns `True` if the input **is** a prime gap:

    prime_gap(x):
	    if x is 1 return True
	    if x is odd return False
    
	    i = 1
	    loop:
	        s = [i, i+1, i+2, ..., i+x]
	        if the only 2 prime numbers in s are [i, i+x] return True
	        else i += 1, go to loop

Therefore, `primeGap` problem is in RE. We would like to know whether `primeGap` is in R, so we must construct an algorithm that also outputs `False` if the input is not a prime gap.

It's clear that:

 - the prime gap is an even number (except for g<sub>1</sub> = 1, for p<sub>2</sub> = 3, p<sub>1</sub> = 2)
 - the gap can get arbitrarily large (considering the sequence `[n!+2, n!+3, ..., n!+n]` in which the first element is divisible with 2, the second one with 3, ..., the last one with n)
 
Therefore, only even numbers > 2 (and 1) can be prime gaps (for any other input, output `False`).  Up until now,  it is [conjectured](https://arxiv.org/pdf/1206.0149.pdf) that every even number can be written in infinitely many ways as the difference of two consecutive primes, so we cannot certainly state that `primeGap` is decidable.

