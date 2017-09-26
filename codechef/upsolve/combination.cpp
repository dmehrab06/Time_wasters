#include <bits/stdc++.h>
using namespace std;

struct combinations
{
    typedef vector<int> combination_t;

    // initialize status
   combinations(int N, int R) :
       completed(N < 1 || R > N),
       generated(0),
       N(N), R(R)
   {
       for (int c = 1; c <= R; ++c)
           curr.push_back(c);
   }

   // true while there are more solutions
   bool completed;

   // count how many generated
   int generated;

   // get current and compute next combination
   combination_t next()
   {
       combination_t ret = curr;

       // find what to increment
       completed = true;
       for (int i = R - 1; i >= 0; --i)
           if (curr[i] < N - R + i + 1)
           {
               int j = curr[i] + 1;
               while (i <= R)
                   curr[i++] = j++;
               completed = false;
               ++generated;
               break;
           }

       return ret;
   }

private:

   int N, R;
   combination_t curr;
};

int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    //int N = argc >= 2 ? atoi(argv[1]) : 5;
    //int R = argc >= 3 ? atoi(argv[2]) : 2;
    combinations cs(N, R);
    while (!cs.completed)
    {
        combinations::combination_t c = cs.next();
        for(int i=0;i<c.size();++i){
            cout<<c[i]<<" ";
        }
        cout<<"\n";
        //copy(c.begin(), c.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    //return cs.generated;
    return 0;
}
