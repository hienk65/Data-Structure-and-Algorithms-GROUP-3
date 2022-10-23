Ex123:
Function  binarySearch(A,n,t,sF)
l=0, h=n-1, s=-1
While l<h {
       m =(l+h)/2
        If t=A[m] {
	r=m
	If sF then h= m-1 else l=m+1
        }
        Else if t<A[m] then h=m-1
        Else l=m+1
}
Return s
