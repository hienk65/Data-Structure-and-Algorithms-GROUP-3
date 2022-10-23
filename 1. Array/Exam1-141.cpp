//Combinations of words formed by replacing given numbers with corresponding alphabets
function recur(vector digits, int i, string str){
    n = digits.size();
    static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sum = 0;
    for  j = i to j <= min(i + 1, n - 1) do
        sum = (sum * 10) + digits[j];
        if (sum <= 26) {
            recur(digits, j + 1, str + alphabet[sum - 1]);
        }

}