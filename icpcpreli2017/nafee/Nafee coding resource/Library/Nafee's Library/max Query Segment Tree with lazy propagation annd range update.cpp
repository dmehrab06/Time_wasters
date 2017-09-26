struct SegTree
{
    LL siz;
    LL *maxAr, *lazyAr;
    SegTree(){}
    SegTree(LL siz)
    {
        this->siz = siz;
        maxAr = new LL[siz+9];
        lazyAr = new LL[siz+9];
    }
    void build(LL att, LL L, LL R, LL *feed)
    {
        maxAr[att] = INT_MIN;
        lazyAr[att] = 0;
        if (L==R)
        {
            maxAr[att] = feed[L];
            return;
        }
        LL mid = (L+R)/2;
        build(att*2, L, mid, feed);
        build(att*2+1, mid+1, R, feed);
        maxAr[att] = max(maxAr[att*2], maxAr[att*2+1]);
    }
    void putLazy(LL &oldVal, LL newVal)
    {
        oldVal = oldVal+newVal;
    }
    void propagate(LL att, LL L, LL R)
    {
        if ( lazyAr[att] )
        {
            maxAr[att] += lazyAr[att];
            if (L<R) // not a leaf node
            {
                putLazy(lazyAr[att*2], lazyAr[att]);
                putLazy(lazyAr[att*2+1], lazyAr[att]);
            }
        }
        lazyAr[att] = 0;
    }
    void update(LL att, LL L, LL R, LL lef, LL r, LL val)
    {
        propagate(att, L, R);
        if ( r<L || R<lef ) // no overlap
        {
            return;
        }

        if ( lef<=L && R <=r ) // total overlap
        {
            putLazy( lazyAr[att], val );
            propagate(att, L, R);
            return;
        }

        // partial overlap
        LL mid = (L+R)/2;
        update(att*2, L, mid, lef, r, val);
        update(att*2+1, mid+1, R, lef, r, val);
        maxAr[att] = max(maxAr[att*2], maxAr[att*2+1]);
    }
    LL query(LL att, LL L, LL R, LL lef, LL r)
    {
        propagate(att, L, R);
        if ( r<L || R<lef ) // no overlap
        {
            return INT_MIN;
        }

        if ( lef<=L && R <=r ) // total overlap
        {
            return maxAr[att];
        }

        // partial overlap
        LL mid = (L+R)/2;
        LL x = query(att*2, L, mid, lef, r);
        LL y = query(att*2+1, mid+1, R, lef, r);
        return max(x, y);
    }
};

