struct rude
{
    ll val,x,y;
    bool operator < (const rude &a) const
    {
        return a.val < val;
    }
};