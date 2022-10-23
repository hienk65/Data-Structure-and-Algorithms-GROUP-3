//Heap Sort Algorithm
function swap(*x,*y)
int LEFT(int i) {return (2*i + 1);}
int RIGHT(int i) {return (2*i + 2);}
function heaptify( A[],n){
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    if (left < end && A[left] > A[i]) 
        largest = left;}
    if (right < end && A[right] > A[largest]) 
        largest = right;
    if (largest != i)
        swap(&A[i], &A[largest]);
        heapify(A, largest)   
function BuildHeap(A[])
{
    int i = (end - 2) / 2;
    while (i >= 0) 
        heapify(A, i--); 
}
function  heapsort(int A[], int n)
{
    end = n;
    BuildHeap(A);
    while (end != 1)
    {
        swap(&A[0], &A[end - 1]);
        end--;
        heapify(A, 0);
    }
}