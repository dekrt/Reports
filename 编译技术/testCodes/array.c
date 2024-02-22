int fibo (int a) { // compute the Fibonacci sequence recursively 
    if (a == 1 || a == 2)
        return 1;
    return fibo(a - 1)+fibo(a - 2);
}
int main () {
    int b[5][5];
    int i, j;
    
    for(i = 0; i < 5; i++) 
        for(j = 0; j < 5; j++)
            b[i][j] = i+j;

    for(i = 0; i < 5; i++)
        write(b[i][i]);
    
    write(fibo(b[1][3]));
    return 0;
}