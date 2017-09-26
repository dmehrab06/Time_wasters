//Disjoint set union by Nafee


struct DSU
{
    long long *parentAr, *total;
    long long siz;
    DSU(long long siz)
    {
        long long a, b, c;
        this->siz = siz;
        parentAr = new long long[siz];
        total = new long long[siz];
        for (a = 0; a < siz; a++)
        {
            parentAr[a] = a;
            total[a] = 1;
        }
    }
    long long getParent(long long u)
    {
        if ( u != parentAr[u] )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    long long getTotal(long long u)
    {
        return total[ getParent(u) ];
    }
    void makePair(long long u, long long v)
    {
        if ( getParent(u)==getParent(v) )
        {
            return;
        }
        total[ getParent(v) ] += total[ getParent(u) ];
        parentAr[ getParent(u) ] = getParent(v);
    }
};

int main()
{
    return 0;
}
