namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
 
    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        for(a in 1 .. n - 1){
            let i = n - a;
            for(j in 0 .. i - 1){
                Controlled H(qs[i .. n - 1], qs[j]);
            }
            X(qs[i]);
        }
        for(i in 1 .. n - 1){
            X(qs[i]);
        }
    }
}