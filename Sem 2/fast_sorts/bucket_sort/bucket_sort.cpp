#include <iostream> 
using namespace std; 

void bsort(int arr[], int n){
    if (n <= 1 ) return; 

    const int bucket_num = 10; 
    const int b1_size = 100; 

    int buckets[bucket_num][b1_size]; 
    int buckets_sizes[bucket_num] = {0}; 

    int maxVal = arr[0]; 

    for (int i = 1; i < n; i++){
        if (arr[i] > maxVal) {maxVal = arr[i]; }
    }

    for (int i = 0; i < n; i++){
        int bucketidx = (bucket_num * arr[i]) / (maxVal + 1); 
        if (buckets_sizes[bucketidx] < b1_size){
            buckets[bucketidx][buckets_sizes[bucketidx]] = arr[i]; 
            buckets_sizes[bucketidx]++;
        }
    }

    for(int i = 0; i < bucket_num; i++){
        for (int j = 1; j < buckets_sizes[i]; j++){
            int tmp = buckets[i][j];
            int k = j-1;
            while (k >= 0 && buckets[i][k] > tmp){
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = tmp;
        }
    }

    int idx = 0; 
    for (int i = 0; i < bucket_num; i++){
        for (int j = 0; j < buckets_sizes[i]; j++){
            arr[idx++] = buckets[i][j];
        }
    }
}

int main()
{
    int a[] = {7, 10, 4, 2, 9, 1};
    const int N = 6; 

    bsort(a, N);
    cout << "Sorted massive: " << endl; 

    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    return 0;
}