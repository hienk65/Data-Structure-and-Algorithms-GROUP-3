Function findLongestSequence (A, n, k)
L=0, c=0, w =0, lI =0
For r=0 to n do {
    If A[r] =0 then c++
    While (c>k) {
	If A[l] = 0 then c—else l++}
    If r>l+1>w then w=r-l+1, lI=l
}
If w= 0 then return
Printf The_longest_sequence_has_length w from index lI to lI+w-1
