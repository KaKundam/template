// (a^n)%k = (a^(n%phi(k)))%k
lo phi(lo x)
{
    lo s = x;
    for (lo i = 2; i * i <= x; i++)
        if ( x % i == 0 )
        {
            s -= s/i;
            while ( x % i == 0 )
                x /= i;
        }
    if ( x > 1 ) s -= s/x;
    return s;
}