
struct Edge
{
    LL to, cap, cost, revIdx;
    Edge(){}
    Edge(LL to, LL cap, LL cost, LL revIdx)
    :to(to), cap(cap), cost(cost), revIdx(revIdx)
    {
    }

    void print()
    {
        DBG4(to, cap, cost, revIdx);
    }
};



struct Graph
{
    LL maxNode;
    vector<Edge> *gr;
    LL *disAr;


    PairLL *parentAr;
    Graph(LL num)
    {
        maxNode = num;
        gr = new vector<Edge>[num+9];
        disAr = new LL[num+9];
        parentAr = new PairLL[num+9];
    }

    ~Graph()
    {
        LL a, b, c, d;
        FOR(a,0,maxNode)
        {
            gr[a].clear();
        }
    }


    void addEdge(LL u, LL v, LL cap, LL cost)
    {
        LL uIdx = gr[u].size();
        LL vIdx = gr[v].size();

        gr[ u ].PUB( Edge(v, cap, cost, vIdx) );
        gr[ v ].PUB( Edge(u, 0, -cost, uIdx) );
    }

    bool dijkstra(LL s, LL t)
    {
        LL a, b, c, d;
        FOR(a,0,maxNode)
        {
            disAr[a] = INT_MAX;
        }
        disAr[s] = 0;
        set< PairLL > setPair;
        setPair.insert( PairLL(0, s) );
        while( setPair.size() )
        {
            PairLL curPair = *(setPair.begin() );

            setPair.erase( setPair.begin() );
            LL curDis = curPair.first;
            LL curNode = curPair.second;
            if ( curDis > disAr[curNode] )
            {
                continue;
            }
            FOR(a,0,gr[curNode].size())
            {
                Edge it = gr[curNode][a];

                if ( it.cap <= 0 )
                {
                    continue;
                }
                LL nexNode = it.to;
                LL nexDis = it.cost + curDis;

                if ( nexDis >= disAr[ nexNode ] )
                {
                    continue;
                }
                disAr[nexNode] = nexDis;
                parentAr[nexNode] = PairLL(curNode, a);
                setPair.insert( PairLL(nexDis, nexNode) );
            }
        }

        return disAr[t] < INT_MAX;
    }

    LL augment(LL s, LL t)
    {
        LL a, b, c, d;
        LL curNode = t;
        LL maxFlow = INT_MAX;
        while( curNode != s )
        {
            LL curParent = parentAr[curNode].first;
            LL curIdx = parentAr[curNode].second;
            Edge curEdge = gr[curParent][curIdx];
            aMin(maxFlow, curEdge.cap);
            curNode = curParent;
        }

        curNode = t;
        while(curNode != s)
        {
            LL curParent = parentAr[curNode].first;
            LL curIdx = parentAr[curNode].second;

            gr[curParent][curIdx].cap -= maxFlow;
            LL revIdx = gr[curParent][curIdx].revIdx;
            gr[curNode][revIdx].cap += maxFlow;
            curNode = curParent;
        }
        return maxFlow;
    }


    void sendMaxFlow(LL s, LL t, LL &costRet, LL &flowRet)
    {

        costRet = 0;
        flowRet = 0;
        while( dijkstra(s, t) )
        {

            LL perUnitCost = disAr[t];
            LL flow = augment(s, t);
            costRet += (flow * perUnitCost);
            flowRet += flow;
        }
    }



};
