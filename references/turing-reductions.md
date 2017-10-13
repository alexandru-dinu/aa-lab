Turing reduction:

 - written as: A <<sub>T</sub> B
 - read as: problem A reduces to problem B
 - A is at least as easy as B (because we can solve A if we know how to solve B)

If A is not decidable, then B is not decidable and if B is decidable, then A is decidable. In general, `if A is not in X, then B is not in X` and `if B is in X, then A is in X`.

The transformation `T` takes as an input an instance for problem A, in<sub>A</sub> and outputs an input for problem B, in<sub>B</sub>: T(in<sub>A</sub>) = in<sub>B</sub>. The transformation must be decidable (it should only convert inputs and not perform any other computation that itself is not decidable).

For example, the following transformation is not decidable:

    T(M): {
		if M halts 
			return M' with 111 on the tape
		else
			return M' with 000 on the tape
	}
				
The above transformation is not decidable because it performs a computation that is not decidable (asks whether M halts, and that is the halting problem).

The following example illustrates a transformation that is decidable:

    T(M, w): {
	    w' = w.append('$').append(w) // w' = w$w
	    return M' with w' on the tape
	}

The above transformation is decidable because the only thing it does is to alter its input (i.e. convert it to `w$w`).