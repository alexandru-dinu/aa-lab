Turing reduction:

 - written as: A <<sub>T</sub> B
 - read as: problem A reduces to problem B
 - A is at least as easy as B (because we can solve A if we know how to solve B)

_Solving A when knowing how to solve B_ is captured in the following pseudo-code:

    def solveA(inA):
	    inB = transform(inA)
	    return solveB(inB)

For example, if we know how to solve the satisfiability problem (SAT), then we can solve the k-Vertex Cover problem. The only thing we have to do is to convert the input from the k-Vertex Cover problem (`G = (V, E), k`) to a boolean formula `(φ)`.


----------


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