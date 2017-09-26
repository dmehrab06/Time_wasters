#include<bits/stdc++.h>
using namespace std ;

bool status[ 500005 ] , pstatus[ 500005 ];
int arr[ 500005 ] , dist[ 500005 ];

vector<int> graph[500005] , reverse_graph[500005] ;

int dfs( int source ) {

	status[ source ] = true ;
	if( reverse_graph[source].size() == 0 ) return 0 ;
	cout << " dfs source : " << source << endl ;
	int len = 0 ;
	for( int i = 0 ; i < reverse_graph[source].size() ; i++ )
		if( !status[ reverse_graph[source][i] ] && !pstatus[ reverse_graph[source][i] ] )
			len = max( len , dfs(  reverse_graph[source][i] ) + 1 ) ;
	cout << " dfs_len : " << len << endl ;
	return len ;
}

int main() {

	int t ;
	cin >> t ;

	while( t-- ) {

		int n  ;
		cin >> n ;


		//clearing graphs...
		for( int i = 0 ; i <= n ; i++ ) {
			graph[i].clear() ;
			reverse_graph[i].clear() ;
		}

		//taking input , setting node -1 as nth node and creating a graph...
		for( int i= 0 ; i < n ; i++ ) {
			cin >> arr[ i ] ;
			if( arr[i] == -1 ) arr[i] = n ;
			graph[i].push_back( arr[i] ) ;
		}

		//reversing the graph...
		for( int i = 0 ; i < n ; i++ ) {
			for( int j = 0 ; j < graph[i].size() ; j++ ) {
				reverse_graph[ graph[i][j] ].push_back( i ) ;
			}
		}

		/*for( int i = 0 ; i <= n ; i++ ) {
			cout << i << " : " ;
			for( int j = 0 ; j < graph[i].size() ; j++ ) cout << graph[i][j] << " " ; cout << endl ;

		}
		cout << " graph reversed " << endl ;

		/*for( int i = 0 ; i <= n ; i++ ) {
			cout << i << " : " ;
			for( int j = 0 ; j < reverse_graph[i].size() ; j++ ) cout << reverse_graph[i][j] << " " ; cout << endl ;

		}
		*/

		//for( int i = 0 ; i < n ; i++ ) cout << arr[i] << " " ; cout << endl ;

		for( int i = 0 ; i <= n ; i++ ) {
			status[i] = pstatus[i] = false ;
		}

		bool cycle = false ;
		int i = 0 , len = 0 ;

		//calculating length of principal chian or cycle
		while( arr[i] != n && !status[i] ) {
			status[i] = true ;
			i = arr[i] ;
			len++ ;
		}

		//cout << " len : " << len << endl ;
		//checking cycle...
		if( ( arr[i] !=n ) ) cycle = true ;
		status[i] = true ;
		status[ n ] = true ;
		pstatus[n] = true ;

		for( int i = 0 ; i <= n ; i++ ) {
			dist[i] = 0   ;
			if( status[i] && !cycle ){cout<<i<<" made pstatus true"<<"\n";pstatus[i] = true ;}
			status[i] = false ;
		}

	//	for( int i = 0 ; i <= n ; i++ ) if( pstatus[i] ) cout << i << " , " ; cout << endl ;

		for( i = n ; i > 0 ; i-- ) {

			if( pstatus[i] ) {

			status[i] = true ;
				for( int j = 0 ; j < reverse_graph[i].size() ; j++ ) {
					if( !status[ reverse_graph[i][j] ] && !pstatus[ reverse_graph[i][j] ] ) {
						cout << " dfs : " << i << " , " << reverse_graph[i][j] << endl ;
						dist[ i ] = max( dist[i] , dfs( reverse_graph[i][j] ) + 1 ) ;
					}
				}
			}
		}

		//cout << "cycle: " << cycle <<endl ;
	//	for( int i = 0 ; i <= n ; i++ ) cout << dist[i] << " " ; cout << endl ;
		int ans  ;
		if( cycle ) {
            cout<<"cycle\n";
			ans = len + dist[n] ;
		}
		else {
            cout<<"no cycle\n";
			int max_val = 0 ;
			len++ ;
			for( int i = 0 ; i <= n ; i++ ) max_val = max( max_val , dist[i] ) ;
			for(int i=0;i<=n;++i){
                cout<<"dis is "<<dist[i]<<"\n";
			}
			ans = max_val ;
			ans += len ;
			cout<<len<<" "<<max_val<<"\n";
		}


		cout << ans << endl ;

	}

	return 0 ;
}
