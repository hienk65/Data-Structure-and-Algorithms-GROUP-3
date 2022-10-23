// array such that `A[A[i]]` is set to `i` for every element `A[i]`
Function rearrange(A[], n)
int aux[n];
For i = 0 to n do{
    aux[A[i]] = i;
}
for i = 0 to n {
    A[i] = aux[i];
}
