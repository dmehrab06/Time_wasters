/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;

typedef struct xx{
    int p;
    int m;
    double percentage;
}grade;

bool cmp(grade &a, grade &b){
    double p1 = a.p-(double)a.m*a.percentage;
    double p2 = b.p-(double)b.m*b.percentage;
    return (p1>p2);
}

vector< grade > all_grades;

bool can(double achieve, int n, int d){
    //cout<<"testing for :"<<achieve<<"\n";
    for(int i = 0; i<n; ++i){
        all_grades[i].percentage = achieve;
    }
    
    sort(all_grades.begin(),all_grades.end(),cmp);

    /*for(int i = 0; i<n; ++i){
        cout<<all_grades[i].p<<" "<<all_grades[i].m<<"\n";
    }*/

    long long lob = 0, hor = 0;

    for(int i = 0; i<n-d; ++i){
        lob = lob+all_grades[i].p;
        hor = hor+all_grades[i].m;
    }

    double got = (double)lob/(double)hor;

    return (got>achieve) || (fabs(got-achieve)<eps);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        all_grades.clear();
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i = 1; i<=n; ++i){
            int p,m;
            scanf("%d %d",&p,&m);
            grade g; g.p = p; g.m = m; g.percentage = 0.0;
            all_grades.push_back(g);
        }
        //sort(subjects.begin(),subjects.end());
        //reverse(subjects.begin(),subjects.end());
        double lo = 0.0, hi = 1.0;
        for(int it = 1; it<=100; ++it){
            double m = (lo+hi)/2.0;
            if(can(m,n,d)){
                lo = m;
            }
            else{
                hi = m;
            }
        }
        printf("Case %d: %.8lf\n",cs,hi*100.00);
    }
    return 0;
}
