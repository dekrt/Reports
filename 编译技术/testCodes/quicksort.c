int arr[20];
int QuickSort(int begin, int end) {
    int tmp, i, j, t;
    if(begin > end)
        return 0;
    tmp = arr[begin];
    i = begin;
    j = end;
    while(i != j){
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];
    arr[i] = tmp;
    QuickSort(begin, i-1);
    QuickSort(i+1, end);
    return 0;
}
int main () {
    int i, n;
    
    n=read();
    for(i=1;i<=n;i++)
        arr[i]=read();
    QuickSort(1, n);
    for(i=1;i<=n;i++)
        write(arr[i]);
    return 0;
}