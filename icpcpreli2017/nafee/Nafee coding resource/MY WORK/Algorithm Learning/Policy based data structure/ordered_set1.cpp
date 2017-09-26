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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set X;


int main()
{
    X.insert(1);
    X.insert(2);
    X.insert(3);
    X.insert(4);
    X.insert(4);

    cout << "X.size() = " << X.size() << endl;

    cout << *X.find_by_order(1) << endl;
    cout << *X.find_by_order(2) << endl;
    cout << *X.find_by_order(3) << endl;
    cout << *X.find_by_order(4) << endl;

    cout << endl;


    cout << X.order_of_key(1) << endl;
    cout << X.order_of_key(2) << endl;
    cout << X.order_of_key(3) << endl;
    cout << X.order_of_key(4) << endl;
    cout << X.order_of_key(5) << endl;

    return 0;
}
