struct H{
        int n;
        int dr=0;
        H(int a){
            n=a;
            int t=n;
            while(t){
                dr+=t%10;
                t/=10;
            }
        }
    bool operator<(H b){
        if (dr==b.dr){
            return n<b.n;
        }
        return dr<b.dr;
    }
        
    };
/*bool mycom(H a, H b){
    if(a.dr==b.dr)return a.n<b.n;
    return a.dr<b.dr;
}*/
std::vector< int >ans, digitRootSort(std::vector< int > a) {
    std::vector< H> pp;
    for(int c:a){
        H h(c);
        pp.push_back(h);
    }
    std::sort(pp.begin(),pp.end());
    for(H h:pp){
        ans.push_back(h.n);
    }
    return ans;
}

