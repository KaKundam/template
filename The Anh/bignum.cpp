string add(string a, string b)
{
    string res = "";
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;
    int du = 0;
    for(int i = a.size()-1;i >= 0;i--)
    {
        int tmp = a[i]-48 + b[i]-48 + du;
        du = tmp / 10;
        tmp = tmp % 10;
        res = (char) (tmp+48) + res;
    }
    if(du > 0) res = '1' + res;
    return res;
}
string sub(string a, string b)
{
    string res = "";
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;
    bool ok = false;
    if(a < b)
    {
        swap(a,b);
        ok = true;
    }
    int du = 0;
    for(int i = a.size()-1; i >= 0;i--)
    {
        int tmp = a[i] - b[i] - du;
        if(tmp < 0)
        {
            tmp += 10;
            du = 1;
        }
        else du = 0;
        res = (char)(tmp%10 + 48) + res;
    }
    while(res.size() > 1 && res[0] == '0')
        res.erase(0,1);
    if(ok) res = "-"+res;
    return res;
}
string mul(string a, string b)
{
    string res = "";
    int n = a.size();
    int m = b.size();
    int len = n+m-1;
    int du = 0;
    for(int i = len;i >= 0;i--)
    {
        int tmp = 0;
        for(int j = n-1;j >= 0;j--)
            if(i-j <= m && i-j >= 1)
            {
                int a1 = a[j]-48;
                int b1 = b[i-j-1]-48;
                tmp += a1*b1;
            }
        tmp += du;
        du = tmp/10;
        res = (char)(tmp%10 + 48)+res;
    }
    while(res.size()>1 && res[0] == '0')
        res.erase(0,1);
    return res;
}
string div(string a,ll n)
{
    string res = "";
    int du = 0;
    for(auto u : a)
    {
        du = du * 10 + u-48;
        if(du >= n)
        {
            res += char(du/n + 48);
            du %= n;
        }
        else res += '0';
    }
    while(res.size()>1 && res[0] == '0')
        res.erase(0,1);
    return res;
}