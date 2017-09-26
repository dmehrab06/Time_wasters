#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100000+10 ;
int tc ;
int n ;
string s0 ;
string s1 ;

int c0[maxn] ;
int c1[maxn] ;

int ans ;
bool horizontal ;
int snk ;

int main()
{
    //freopen("input.txt","r",stdin) ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;

    cin >> tc ;
    while( tc-- )
    {
        cin >> n ;
        cin >> s0 >> s1 ;

        ans = 0 ;
        horizontal = false ;
        snk = 0 ;
        //cout << s0 << endl << s1 << endl << endl ;
        for( int i = 0 ; i < n ; i++ )
        {
            c0[i] = 0 ;
            c1[i] = 0 ;

            if( s0[i] == '*' )
            {
                snk++ ;
                c0[i] = 1 ;

            }
            if( i-1 >= 0 ) c0[i] += c0[i-1] ;

            if( s1[i] == '*' )
            {
                snk++ ;
                c1[i] = 1 ;
            }
            if( i-1 >= 0 ) c1[i] += c1[i-1] ;
        }

        if( snk <= 1 )
        {
            cout << 0 << endl ;
            continue ;
        }
        for( int i = 0 ; i < n ; i++ )
        {
            if( s0[i] == '*' && s1[i] == '*' )
            {
                horizontal = true ;
                //break ;
            }
            if( s0[i] == '*' or s1[i] == '*' )
            {
                ans++ ;
            }

        }
        /*
        for( int i = n-1 ; i >= 0 ; i-- )
        {
            if( s0[i] == '*' )
            {
                snk-- ;
                if( snk > 0 )
                {
                    if( s1[i] == '*' )
                    {
                        snk-- ;
                        horizontal = true ;
                        if( snk > 0 )
                        {
                            if( i-1 >= 0 && c0[i-1] > 0 )
                            {
                                ans++ ;
                            }

                        }
                    }
                    else
                    {
                        if( snk > 0 )
                        {
                            if( horizontal && c0[i-1] == 0 )
                            {
                                //continue;
                            }
                            else //if( !horizontal && c0[i-1] == 0 )
                            {
                                ans++ ;
                            }
                        }
                    }
                }

            }
            //else  s0[i] = empty
            else if( s1[i] == '*' )
            {
                snk-- ;
                if( snk > 0 )
                {
                    //if( i == 0 ) continue ;

                    if( horizontal && c1[i-1] == 0  )
                    {
                        //continue ;
                    }
                    else //if( !horizontal )
                    {
                        ans++ ;
                    }
                }

            }
        }
        */


        ans-- ;
        if( horizontal) ans++ ;
        cout << ans << endl ;
    }

    return 0 ;
}
