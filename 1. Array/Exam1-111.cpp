#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;
struct MinHeapNode
{
    int element;
    int i;
};
struct comp
{
    bool operator()(const MinHeapNode &lhs, const MinHeapNode &rhs) const {
        return lhs.element > rhs.element;
    }
};
 
FILE* openFile(char* fileName, char* mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void mergeFiles(char *output_file, int n, int k)
{
    FILE* in[k];
    for (int i = 0; i < k; i++)
    {
        char fileName[2];
        snprintf(fileName, sizeof(fileName), "%d", i);
        in[i] = openFile(fileName, "r");
    }
 
    FILE *out = openFile(output_file, "w");
    MinHeapNode harr[k];
    priority_queue<MinHeapNode, vector<MinHeapNode>, comp> pq;
 
    int i;
    for (i = 0; i < k; i++)
    {
        if (fscanf(in[i], "%d ", &harr[i].element) != 1) {
            break;
        }
        harr[i].i = i;
        pq.push(harr[i]);
    }
 
    int count = 0;
    while (count != i)
    {
        MinHeapNode root = pq.top();
        pq.pop();
        fprintf(out, "%d ", root.element);
        if (fscanf(in[root.i], "%d ", &root.element) != 1 )
        {
            root.element = numeric_limits<int>::max();
            count++;
        }
        pq.push(root);
    }
    for (int i = 0; i < k; i++) {
        fclose(in[i]);
    }
 
    fclose(out);
}
void createInitialRuns(char *input_file, int run_size, int num_ways)
{
    FILE *in = openFile(input_file, "r");
    FILE* out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++)
    {
        snprintf(fileName, sizeof(fileName), "%d", i);
        out[i] = openFile(fileName, "w");
    }
    int* arr = new int[run_size];
    bool more_input = true;
    int next_output_file = 0;
    int i;
    while (more_input)
    {
        for (i = 0; i < run_size; i++)
        {
            if (fscanf(in, "%d ", &arr[i]) != 1)
            {
                more_input = false;
                break;
            }
        }
        sort(arr, arr + i);
        for (int j = 0; j < i; j++) {
            fprintf(out[next_output_file], "%d ", arr[j]);
        }
 
        next_output_file++;
    }
    delete arr;
 
    for (int i = 0; i < num_ways; i++) {
        fclose(out[i]);
    }
 
    fclose(in);
}

int main()
{
    int num_ways = 10;
    int run_size = 1000;
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    FILE* in = openFile(input_file, "w");
    srand(time(NULL));
    for (int i = 0; i < num_ways * run_size; i++) {
        fprintf(in, "%d ", rand());
    }
    fclose(in);
    createInitialRuns(input_file, run_size, num_ways);
    mergeFiles(output_file, run_size, num_ways);
    return 0;
}