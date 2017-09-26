/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/*
 * InfInt - Arbitrary-Precision Integer Arithmetic Library
 * Copyright (C) 2013 Sercan Tutar
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *
 * USAGE:
 *   It is pretty straight forward to use the library. Just create an instance of
 *   InfInt class and start using it.
 *
 *   Useful methods:
 *      intSqrt:        integer square root operation
 *      digitAt:        returns digit at index
 *      numberOfDigits: returns number of digits
 *      size:           returns size in bytes
 *      toString:       converts it to a string
 *
 *   There are also conversion methods which allow conversion to primitive types:
 *   toInt, toLong, toLongLong, toUnsignedInt, toUnsignedLong, toUnsignedLongLong.
 *
 *   You may define INFINT_USE_EXCEPTIONS and library methods will start raising
 *   InfIntException in case of error instead of writing error messages using
 *   std::cerr.
 *
 *   See ReadMe.txt for more info.
 *
 *
 * No overflows, happy programmers!
 *
 */

#ifndef INFINT_H_
#define INFINT_H_

//#include "Profiler.h"

#ifdef _WIN32
#define LONG_LONG_MIN LLONG_MIN
#define LONG_LONG_MAX LLONG_MAX
#define ULONG_LONG_MIN ULLONG_MIN
#define ULONG_LONG_MAX ULLONG_MAX
#endif

//#define INFINT_USE_EXCEPTIONS
//#define INFINT_USE_SHORT_BASE

#ifdef INFINT_USE_EXCEPTIONS
#include <exception>
#endif

//inline bool check_pos(int n)
//{
//    return n >= 0;
//}
//inline bool check_neg(int n)
//{
//    return n <= 0;
//}

#ifdef INFINT_USE_SHORT_BASE // uses 10^4 (short) as the base
typedef short ELEM_TYPE;
typedef int PRODUCT_TYPE;
static const ELEM_TYPE BASE = 10000;
static const ELEM_TYPE UPPER_BOUND = 9999;
static const ELEM_TYPE DIGIT_COUNT = 4;
static const int powersOfTen[] = { 1, 10, 100, 1000};
#else // uses 10^9 (int) as the base
typedef int ELEM_TYPE;
typedef long long PRODUCT_TYPE;
static const ELEM_TYPE BASE = 1000000000;
static const ELEM_TYPE UPPER_BOUND = 999999999;
static const ELEM_TYPE DIGIT_COUNT = 9;
static const int powersOfTen[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
#endif

#ifdef INFINT_USE_EXCEPTIONS
class InfIntException: public std::exception
{
public:
    InfIntException(const std::string& txt) throw ();
    ~InfIntException() throw ();
    const char* what() const throw ();
private:
    std::string txt;
};

InfIntException::InfIntException(const std::string& txt) throw () :
std::exception(), txt(txt)
{
}

InfIntException::~InfIntException() throw ()
{
}

const char* InfIntException::what() const throw ()
{
    return txt.c_str();
}
#endif

class InfInt
{
    friend std::ostream& operator<<(std::ostream &s, const InfInt &n);
    friend std::istream& operator>>(std::istream &s, InfInt &val);

public:
    /* some constants */
    static const InfInt zero;
    static const InfInt one;
    static const InfInt two;

    /* constructors */
    InfInt();
    InfInt(const char* c);
    InfInt(const std::string& s);
    InfInt(int l);
    InfInt(long l);
    InfInt(long long l);
    InfInt(unsigned int l);
    InfInt(unsigned long l);
    InfInt(unsigned long long l);

    /* assignment operators */
    const InfInt& operator=(const char* c);
    const InfInt& operator=(const std::string& s);
    const InfInt& operator=(int l);
    const InfInt& operator=(long l);
    const InfInt& operator=(long long l);
    const InfInt& operator=(unsigned int l);
    const InfInt& operator=(unsigned long l);
    const InfInt& operator=(unsigned long long l);

    /* unary increment/decrement operators */
    const InfInt& operator++();
    const InfInt& operator--();
    InfInt operator++(int);
    InfInt operator--(int);

    /* operational assignments */
    const InfInt& operator+=(const InfInt& rhs);
    const InfInt& operator-=(const InfInt& rhs);
    const InfInt& operator*=(const InfInt& rhs);
    const InfInt& operator/=(const InfInt& rhs); // throw
    const InfInt& operator%=(const InfInt& rhs); // throw
    const InfInt& operator*=(ELEM_TYPE rhs);

    /* operations */
    InfInt operator-() const;
    InfInt operator+(const InfInt& rhs) const;
    InfInt operator-(const InfInt& rhs) const;
    InfInt operator*(const InfInt& rhs) const;
    InfInt operator/(const InfInt& rhs) const; // throw
    InfInt operator%(const InfInt& rhs) const; // throw
    InfInt operator*(ELEM_TYPE rhs) const;

    /* relational operations */
    bool operator==(const InfInt& rhs) const;
    bool operator!=(const InfInt& rhs) const;
    bool operator<(const InfInt& rhs) const;
    bool operator<=(const InfInt& rhs) const;
    bool operator>(const InfInt& rhs) const;
    bool operator>=(const InfInt& rhs) const;

    /* integer square root */
    InfInt intSqrt() const; // throw

    /* digit operations */
    char digitAt(size_t i) const; // throw
    size_t numberOfDigits() const;

    /* size in bytes */
    size_t size() const;

    /* string conversion */
    std::string toString() const;

    /* conversion to primitive types */
    int toInt() const; // throw
    long toLong() const; // throw
    long long toLongLong() const; // throw
    unsigned int toUnsignedInt() const; // throw
    unsigned long toUnsignedLong() const; // throw
    unsigned long long toUnsignedLongLong() const; // throw

private:
    static ELEM_TYPE dInR(const InfInt& R, const InfInt& D);
    static void multiplyByDigit(ELEM_TYPE factor, std::vector<ELEM_TYPE>& val);

    void correct(bool justCheckLeadingZeros = false, bool hasValidSign = false);
    void fromString(const std::string& s);
    void optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const;
    void truncateToBase();
    bool equalizeSigns();
    void removeLeadingZeros();

    std::vector<ELEM_TYPE> val; // number with base FACTOR
    bool pos; // true if number is positive
};

const InfInt InfInt::zero = 0;
const InfInt InfInt::one = 1;
const InfInt InfInt::two = 2;

inline InfInt::InfInt() : pos(true)
{
    val.push_back((ELEM_TYPE) 0);
}

inline InfInt::InfInt(const char* c)
{
    fromString(c);
}

inline InfInt::InfInt(const std::string& s)
{
    fromString(s);
}

inline InfInt::InfInt(int l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
#ifndef _WIN32
        lldiv_t dt = lldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
#else
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
#endif
    } while (l > 0);
}

inline InfInt::InfInt(unsigned int l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long long l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline const InfInt& InfInt::operator=(const char* c)
{
    fromString(c);
    return *this;
}

inline const InfInt& InfInt::operator=(const std::string& s)
{
    fromString(s);
    return *this;
}

inline const InfInt& InfInt::operator=(int l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
#ifndef _WIN32
        lldiv_t dt = lldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
#else
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
#endif
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned int l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator++()
{
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline const InfInt& InfInt::operator--()
{
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline InfInt InfInt::operator++(int)
{
    InfInt result = *this;
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline InfInt InfInt::operator--(int)
{
    InfInt result = *this;
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline const InfInt& InfInt::operator+=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) + (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator-=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) - (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator*=(const InfInt& rhs)
{
    // TODO: optimize (do not use operator*)
    *this = *this * rhs;
    return *this;
}


inline const InfInt& InfInt::operator%=(const InfInt& rhs)
{
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return zero;
#endif
    }
    InfInt D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    bool oldpos = pos;
    val.clear();
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        val.insert(val.begin(), (ELEM_TYPE) 0);
        val[0] = N.val[i];
        correct(true);
        *this -= D * dInR(*this, D);
    }
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : oldpos;
    return *this;
}


inline InfInt InfInt::operator-() const
{//PROFILED_SCOPE
    InfInt result = *this;
    result.pos = !pos;
    return result;
}





inline InfInt InfInt::operator%(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return zero;
#endif
    }
    InfInt R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        R.val.insert(R.val.begin(), (ELEM_TYPE) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        R -= D * dInR(R, D);
    }
    R.correct();
    R.pos = (R.val.size() == 1 && R.val[0] == 0) ? true : pos;
    return R;
}

inline InfInt InfInt::operator*(ELEM_TYPE rhs) const
{//PROFILED_SCOPE
    InfInt result = *this;
    ELEM_TYPE factor = rhs < 0 ? -rhs : rhs;
    multiplyByDigit(factor, result.val);
    result.correct();
    result.pos = (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == (rhs >= 0));
    return result;
}

inline bool InfInt::operator==(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos != rhs.pos || val.size() != rhs.val.size())
    {
        return false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] != rhs.val[i])
        {
            return false;
        }
    }
    return true;
}


inline bool InfInt::operator<(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return false;
    }
    if (!pos && rhs.pos)
    {
        return true;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? false : true;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? true : false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? true : false;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? false : true;
        }
    }
    return false;
}


inline bool InfInt::operator>(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return true;
    }
    if (!pos && rhs.pos)
    {
        return false;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? true : false;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? false : true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? false : true;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? true : false;
        }
    }
    return false;
}





inline size_t InfInt::size() const
{//PROFILED_SCOPE
    return val.size() * sizeof(ELEM_TYPE) + sizeof(bool);
}





inline void InfInt::truncateToBase()
{//PROFILED_SCOPE
    for (size_t i = 0; i < val.size(); ++i) // truncate each
    {
        if (val[i] >= BASE || val[i] <= -BASE)
        {//PROFILED_SCOPE
            div_t dt = div(val[i], BASE);
            val[i] = dt.rem;
            if (i + 1 >= val.size())
            {//PROFILED_SCOPE
                val.push_back(dt.quot);
            }
            else
            {//PROFILED_SCOPE
                val[i + 1] += dt.quot;
            }
        }
    }
}

inline bool InfInt::equalizeSigns()
{//PROFILED_SCOPE
    bool isPositive = true;
    int i = (int) ((val.size())) - 1;
    for (; i >= 0; --i)
    {
        if (val[i] != 0)
        {
            isPositive = val[i--] > 0;
            break;
        }
    }

    if (isPositive)
    {
        for (; i >= 0; --i)
        {
            if (val[i] < 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); // count adjacent zeros on left
                //if ((size_t)(index) < val.size() && val[index] > 0)
                { // number on the left is positive
                    val[index] -= 1;
                    val[i] += BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = UPPER_BOUND;
                    }
                }
            }
        }
    }
    else
    {
        for (; i >= 0; --i)
        {
            if (val[i] > 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); // count adjacent zeros on right
                //if ((size_t)(index) < val.size() && val[index] < 0)
                { // number on the left is negative
                    val[index] += 1;
                    val[i] -= BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = -UPPER_BOUND;
                    }
                }
            }
        }
    }

    return isPositive;
}

inline void InfInt::removeLeadingZeros()
{//PROFILED_SCOPE
    for (int i = (int) (val.size()) - 1; i > 0; --i) // remove leading 0's
    {
        if (val[i] != 0)
        {
            return;
        }
        else
        {
            val.erase(val.begin() + i);
        }
    }
}

inline void InfInt::correct(bool justCheckLeadingZeros, bool hasValidSign)
{//PROFILED_SCOPE
    if (!justCheckLeadingZeros)
    {
        truncateToBase();

        if (equalizeSigns())
        {
            pos = ((val.size() == 1 && val[0] == 0) || !hasValidSign) ? true : pos;
        }
        else
        {
            pos = hasValidSign ? !pos : false;
            for (size_t i = 0; i < val.size(); ++i)
            {
                val[i] = abs(val[i]);
            }
        }
    }

    removeLeadingZeros();
}


inline ELEM_TYPE InfInt::dInR(const InfInt& R, const InfInt& D)
{//PROFILED_SCOPE
    ELEM_TYPE min = 0, max = UPPER_BOUND;
    while (max - min > 0)
    {
        ELEM_TYPE avg = max + min;
        //div_t dt = div(avg, 2);
        //avg = dt.rem ? (dt.quot + 1) : dt.quot;
        ELEM_TYPE havg = avg / 2;
        avg = (avg - havg * 2) ? (havg + 1) : havg;
        InfInt prod = D * avg;
        if (R == prod)
        {//PROFILED_SCOPE
            return avg;
        }
        else if (R > prod)
        {//PROFILED_SCOPE
            min = avg;
        }
        else
        {//PROFILED_SCOPE
            max = avg - 1;
        }
    }
    return min;
}

inline void InfInt::multiplyByDigit(ELEM_TYPE factor, std::vector<ELEM_TYPE>& val)
{//PROFILED_SCOPE
    ELEM_TYPE carry = 0;
    for (size_t i = 0; i < val.size(); ++i)
    {
        PRODUCT_TYPE pval = val[i] * (PRODUCT_TYPE) factor + carry;
        if (pval >= BASE || pval <= -BASE)
        {
            //carry = (ELEM_TYPE) (pval / BASE);
            //pval %= BASE;

            carry = (ELEM_TYPE) (pval / BASE);
            pval -= carry * BASE;
        }
        else
        {
            carry = 0;
        }
        val[i] = (ELEM_TYPE) pval;
    }
    if (carry > 0)
    {
        val.push_back(carry);
    }
}

/**************************************************************/
/******************** NON-MEMBER OPERATORS ********************/
/**************************************************************/



inline std::ostream& operator<<(std::ostream &s, const InfInt &n)
{//PROFILED_SCOPE
    if (!n.pos)
    {
        s << '-';
    }
    bool first = true;
    for (int i = (int) n.val.size() - 1; i >= 0; --i)
    {
        if (first)
        {
            s << n.val[i];
            first = false;
        }
        else
        {
            s << std::setfill('0') << std::setw(DIGIT_COUNT) << n.val[i];
        }
    }
    return s;
}

#endif



typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI coin[100005];

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

InfInt moka(){
    InfInt s=1;
    FREP(i,1,64){
        s=s*2;
    }
    return s;
}

int main(){
    InfInt mdd=moka();
   // cout<<mdd<<"\n";
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n; LLI k;
        scanf("%d %lld",&n,&k);
        map<LLI,int>freq;
        FREP(i,1,n){
            scanf("%lld",&coin[i]);
            if(freq.find(coin[i])==freq.end())freq[coin[i]]=1;
            else freq[coin[i]]++;
        }
        InfInt ans=0;
        FREP(i,1,n){
            LLI cur=coin[i];
            LLI ff=freq[cur];
         //   cout<<cur<<" "<<ff<<"\n";
            LLI gg=gcd(cur,k);
          //  cout<<gg<<"\n";
            LLI dd=k/gg;
            if(ff%dd==0){
                ans+=(InfInt)cur;
                ans%=mdd;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}


