#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;


// Order Statistic Tree

/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

struct myStruct
{
    long long a, b;
    myStruct(){}
    myStruct(long long a, long long b)
    {
        this->a = a;
        this->b = b;
    }
    bool operator < (const myStruct B) const
    {
        if ( a == B.a )
        {
            return b < B.b;
        }
        return a < B.a;
    }
};

bool cmpMyStruct(myStruct A, myStruct B)
{

}

typedef tree<
myStruct,
null_type,
less<myStruct>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set X;


int main()
{

    X.insert( myStruct(2, 22) );
    X.insert( myStruct(3, 33) );
    X.insert( myStruct(4, 44) );
    X.insert( myStruct(5, 55) );
    X.insert( myStruct(1, 11) );

    cout << X.find_by_order(0)->a << " " << X.find_by_order(0)->b << endl;

    cout << X.order_of_key( myStruct(2, 23) ) << endl;

    return 0;
}
