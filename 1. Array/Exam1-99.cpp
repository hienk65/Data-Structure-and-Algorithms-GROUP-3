Function findKthSmallest(vector in, k)
If i.size()<k then exit(-1)
Qr , vector qp(in.begin(), in.begin()+k
For i=k to in.size() do {
    If(in[i] <qp.top() then qp.pop(), qp.push(in[i])   
}
Return qp.top()
