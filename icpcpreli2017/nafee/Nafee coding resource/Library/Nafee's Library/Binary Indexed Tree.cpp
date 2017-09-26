struct BIT
{
    LL siz, *treeAr;
    BIT(){}
    BIT(LL siz)
    {
        this->siz = siz;
        treeAr = new LL[siz+9];
        memset(treeAr, 0, sizeof(treeAr) );
    }

    LL read(LL idx)
    {
        LL ret = 0;
        while( idx > 0 )
        {
            ret += treeAr[idx];
            idx -= ( idx & -idx );
        }
        return ret;
    }

    void update(LL idx, LL val)
    {
        while( idx <= siz )
        {
            treeAr[idx] += val;
            idx += ( idx & -idx );
        }
    }
};

