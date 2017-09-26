import math

PI = math.pi
def angle_between(v1, v2):

    len1 = math.sqrt(v1[0] ** 2  + v1[1] ** 2);
    len2 = math.sqrt(v2[0] ** 2  + v2[1] ** 2);

    dot = 0.0

    dot = (v1[0]* v2[0] + v1[1] * v2[1]);

    a = 0.0
    a = dot / (len1 * len2);

    if ( a > 1.0 or  math.isclose(a , 1.0)):
        return 0.0
    elif ( a < -1.0 or math.isclose(a, -1.0)):
        return PI
    else :
        return math.acos(a) 



if __name__ == "__main__":
        print("You ran this module directly (and did not 'import' it).")
        n = int(input("Enter value of n :"))
        p2 = (5,0)
        ans = 0.0
        for i in range(1,n+1):
                
                x = int(input("Enter the value of x :"))
                y = int(input("Enter the value of y :"))
                p3 = (x,y);
                rad = 0.0
                deg = 0.0
                rad =angle_between(p2,p3);
                deg = rad * 180.0 / math.pi;
                deg = min(deg,360.0-deg);
                ans+=deg;
                p2=p3;

        print("Answer : ", ans)