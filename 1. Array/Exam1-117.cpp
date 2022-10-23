// Ternary Search vs Binary search
function TernarySearch(arr[],n,x){
    low = 0, high = n - 1;
    while (low <= high) do
    {
        left_mid = low + (high - low) / 3;
        right_mid = high - (high - low) / 3;
        if (arr[left_mid] == x) {
            return left_mid;}
        else if (arr[right_mid] == x) {
            return right_mid;}
        else if (arr[left_mid] > x) {
            high = left_mid - 1;}
        else if (arr[right_mid] < x) {
            low = right_mid + 1;}
        else {
            low = left_mid + 1, high = right_mid - 1;}
    }
    return -1;
}