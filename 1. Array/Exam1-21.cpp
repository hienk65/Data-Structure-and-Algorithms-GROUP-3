//Find the maximum difference between two array elements that satisfies the given constraints
Function getMaxDiff(array, n)
For i=0 to n-1 do {
    For j=i+1 to n do {
    If array[j]>array[i] then diff = max(diff, array[j] - array[i]);// max( x, y) {return (x > y) ? x : y;}
 }
}