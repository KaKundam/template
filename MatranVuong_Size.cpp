// nhớ mod 
struct Matrix
{
    int n;
    vector<vector<int>> x;
    Matrix(){
        n=0;
        x.clear();
    }
    Matrix(int b)
    {
        this->n=b;
        x.assign(b+1,vector<int>(b+1,0));
    }
    void read()
    {
        cin>>n;
        x.assign(n+1,vector<int>(n+1,0));
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                cin>>x[i][j];
    }
    void out()
    {
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j)
                cout<<x[i][j]<<' ';
            cout<<'\n';
        }
    }
    Matrix operator * (const Matrix b)
    {
        Matrix c=Matrix(n);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
        {
            c.x[i][j]=0;
            for (int t=1;t<=n;++t)
                c.x[i][j]=(c.x[i][j]+1LL*x[i][t]*b.x[t][j]+1LL*mod*mod)%mod;
        }
        return c;
    }
};