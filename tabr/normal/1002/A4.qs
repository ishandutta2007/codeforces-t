namespace Solution
{
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        if(n==1){
            X(qs[0]);
        }else{
            Ry(2.0 * ArcSin(Sqrt(1.0 / IntAsDouble(n))), qs[0]);
            for(i in 1..n-1){
                (ControlledOnInt(0, Ry))(qs[0..i-1],(2.0 * ArcSin(Sqrt(1.0 / IntAsDouble(n-i))), qs[i]));
            }
        }
    }

    operation Deutsch_Jozsa (n : Int, U : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable res = true;
        using ((x, y) = (Qubit[n], Qubit())) {
            X(y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
            }
            U(x, y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
                if (M(x[i]) != Zero) {
                    set res = false;
                }
            }
            ResetAll(x);
            Reset(y);
        }
        return res;
    }

    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if (desired != current) { X(q1); }
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                let binary = IntAsBoolArray(k, N);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                unitary(qs);
                DumpMachine($"DU_{N}_{k}.txt");
                ResetAll(qs);
            }
        }
    }

    operation CallDumpUnitary (N : Int) : Unit {
        // let unitary = ApplyToEach(I, _);
        let unitary = Solve;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);