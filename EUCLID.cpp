// return x such that a*x=1 mod b
int modinv(int a, int b){
    int r1 = a, r2 = b, x1 = 1, x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return (x1 + b) % b;
}


long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b%a,a) * b / a : 1;
}