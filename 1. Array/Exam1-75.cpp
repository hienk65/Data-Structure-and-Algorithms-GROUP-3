Function findPairs (A, n)
unordered_map<int, vector<Pair>> m
For i=0 to n-1 do {
   For j=i+1 to n do {
 	sum = A[i]+A[j]
	If m.find(sum) != m.end(){
	    For for (auto pair: m.find(sum)->second){
m = pair.first, n = pair.second;
 if (m != i && m != j) && (n != i && n != j) then   cout  (A[i], A[j]) , (A[m],A[n])                        
return;
}
                   }
            m[sum].push_back({i, j});
	}
    }
cout << "No non-overlapping pairs present";
