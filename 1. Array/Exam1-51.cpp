Function quadTuple (A, n, t)
Sort (A, A+n)
For i=0 to n-4 do {
      For j=i+1 to n-3 do {
	k = t – A[i] +A[j], l=j+1, h=n-1
	While (l<h){
	        if A[l] +A[h] <k then l++
	        else if A[l] +A[h] >k then h --
	        else cout A[i], A[j], A[l], A[h]
	        l++, h—
        }
}
