/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.01
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double sq(double x){
    return x*x;
}

map<string,int>locnames;
int locsize = 0;
int drivsize = 0;
bool validclient = false;

class Location{
    public:
        string name;
        double x,y;
        Location(double _x = 0.0, double _y=0.0, string nm = ""){
            x = _x; y = _y;
            name = "";
        }
        double dis(Location &l){
            return sqrt(sq(x-l.x)+sq(y-l.y));
        }
        string getname(){return name;}

        friend istream &operator>>(istream &input, Location &l){
            input>>l.name>>l.x>>l.y;
            if(locnames.find(l.name)==locnames.end())locnames[l.name] = locsize++;
            return input;
        }
};

vector <Location> all_locs;

void insertloc(){
    int prev = locsize;
    Location l;
    cin>>l;
    if(prev!=locsize){
        all_locs.PB(l);
    }
}

class Driver{
    public:
        int drivid;
        Location curlocation;
        int car_number;
        double rating;
        int support_passenger;
        double f_p_km;
        Driver(Location _cur, int _num = -1, double _rat = 0.0, int _pass = 0, double _fare=MXX){
            curlocation = _cur;
            car_number = _num;
            rating = _rat;
            support_passenger = _pass;
            f_p_km = _fare;
        }

        double getrating(){return rating;}
        void setlocation(Location l){curlocation = l;}
        int getsupport(){return support_passenger;}
        Location getlocation(){return curlocation;}
        double fareask(double dis){return dis*f_p_km;}
        bool isvalidloc(){if(locnames.find(curlocation.getname())==locnames.end())return false; return true;}
        void setdriverid(int idx){drivid = idx;}

        friend istream &operator>>(istream &input, Driver &d){
            string loc;
            input>>loc>>d.car_number>>d.rating>>d.support_passenger>>d.f_p_km;
            if(locnames.find(loc)!=locnames.end()){
                drivsize++;
                d.setlocation(all_locs[locnames[loc]]);
            }
            return input;
        }

        friend ostream &operator<<(ostream &output, const Driver &d){
            output<<"Driver id: "<<d.drivid<<" car number "<<d.car_number;
            return output;
        }
};

vector<Driver>drivers;

void insertdriver(){
    int prev = drivsize;
    Location dummy;
    Driver d(dummy);
    cin>>d;
    if(drivsize!=prev){
        d.setdriverid(drivsize);
        drivers.PB(d);
    }
}

class Client{
    public:
        string name;
        Location curlocation;
        Location deslocation;
        int no_of_passenger;
        double req_rating;
        Client(Location _cur, Location _des, int _pass = 0, double _req = 0.0, string nm = ""){
            name = nm;
            curlocation = _cur; deslocation = _des;
            no_of_passenger = _pass;
            req_rating = _req;
        }
        Location getcur(){return curlocation;}
        Location getdes(){return deslocation;}
        void setcur(Location cur){curlocation = cur;}
        void setdes(Location des){deslocation = des;}
        int getpassnumber(){return no_of_passenger;}
        double getreq(){return req_rating;}

        friend istream &operator>>(istream &input, Client &c){
            string cur,des;
            input>>cur>>des>>c.name>>c.no_of_passenger>>c.req_rating;
            if(locnames.find(cur)!=locnames.end() && locnames.find(des)!=locnames.end()){
                validclient = true;
                c.setcur(all_locs[locnames[cur]]);
                c.setdes(all_locs[locnames[des]]);
            }
            return input;
        }
};

pair<bool,Client> clientcomes(){
    validclient = false;
    Location dummycur,dummydes;
    Client c(dummycur,dummydes);
    cin>>c;
    return make_pair(validclient,c);
}

Driver getbestdriver(Client c){
    Location dummyloc;
    int id = -1;
    Driver d(dummyloc);
    double bestfare = MXX;
    double bestdis = MXX;

    FREP(i,0,(int)drivers.size()-1){

        Location drivlocation = drivers[i].getlocation();
        Location passlocation = c.getcur(); Location passdes = c.getdes();

        double drivdis = drivlocation.dis(passlocation);
        double passdis = passlocation.dis(passdes);
        double fare = drivers[i].fareask(passdis);

        if(drivers[i].getrating()<c.getreq() || drivers[i].getsupport()<c.getpassnumber())continue;

        if(fare<bestfare){
            id = i;
            d = drivers[i];
            bestfare = fare;
            bestdis = drivdis;
        }
        else if(fabs(fare-bestfare)<eps){
            if(drivdis<bestdis){
                id = i;
                d = drivers[i];
                bestfare = fare;
                bestdis = drivdis;
            }
        }
    }
    if(id==-1)cout<<"No drivers available according to requirement\n";
    return d;
}

int main(){
    while(true){
        int choice;
        cin>>choice;
        if(choice==1){
            //new driver
            insertdriver();
        }
        else if(choice==2){
            //new location
            insertloc();
        }
        else if(choice==3){
            //new client
            pair<bool,Client> inp =  clientcomes();
            if(inp.first){
                Driver bst = getbestdriver(inp.second);
                if(bst.drivid!=-1){
                    cout<<bst<<" is your best choice\n";
                }
            }
        }
    }
    return 0;
}
