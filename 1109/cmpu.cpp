#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<complex>
#include<vector>
#include<stack>
#include<cmath>

#define ERROR 0x00
#define FRONT 0x01
#define RIGHT 0x02
#define BACK 0x04
#define LEFT 0x08
#define OVER 0x10

#define DEBUG

#ifdef NDEBUG
#define DBG(x)
#else
#define DBG(x) x
#endif

#define sc second
#define fr first

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long double elem;
typedef complex<elem> point, vec;
typedef pair<point, point> line, seg, pp;

const double eps = 1.0e-12;
const double infty = 1e44;
const double pi = acos(-1.0);
point base(0,0);

inline elem sq(elem a){ return a*a; }
inline elem cq(elem a){ return a*a*a; }

elem rad(elem deg){ return (deg/180)*pi; }
elem deg(elem rad){ return (rad*180)/pi; }

bool eq(elem a, elem b){ return abs(a-b) < eps; }
bool lt(elem a, elem b){ return !eq(a,b) && a < b; }
bool leq(elem a, elem b){ return eq(a,b) || a < b; }
bool gt(elem a, elem b){ return !eq(a,b) && a > b; }
bool geq(elem a, elem b){ return eq(a,b) || a > b; }
bool ltz(elem a){ return lt( a, 0 ); }
bool gtz(elem a){ return gt( a, 0 ); }
bool eqv(vec a, vec b){ return eq( abs(b-a),0); }
bool is_zv(vec v){ return eq(abs(v),0); }

bool far(point a, point b){ return gtz( abs(b-a) ); }
bool near(point a, point b){ return leq( abs(b-a), 0 ); }
elem dot(vec a, vec b){ return (a.real() * b.real() + a.imag() * b.imag() ); }
elem cross(vec a, vec b){ return ( a.real() * b.imag() - a.imag() * b.real() ); }

elem varg(vec a, vec b){
  elem ret=arg(a)-arg(b);
  if(lt(ret,0))ret+=2*pi;
  if(gt(ret,2*pi))ret-=2*pi;
  if(eq(ret,2*pi))ret=0;
  return ret;
}
elem arg(vec a, vec b){ return acos( dot(a,b) / ( abs(a) * abs(b) ) ); }
point rot(point p, elem theta){ return p * polar((elem)1.0, theta); }
point rotdeg(point p, elem deg){ return p * polar((elem)1.0, rad(deg)); }

elem dist(point a, point b){ return abs(a-b); }
elem dist_l(line l, point x){ return abs(cross(l.sc-l.fr,x-l.fr)) / abs(l.sc-l.fr); }
elem dist_seg(seg s, point x)
{
  if( ltz( dot(s.sc-s.fr,x-s.fr) ) ) return abs(x-s.fr);
  if( ltz( dot(s.fr-s.sc,x-s.sc) ) ) return abs(x-s.sc);
  return dist_l(s,x);
}

vec uvec(vec a){ return a / abs(a); }
vec nmr(vec a){ return a * vec(0,-1); }
vec nml(vec a){ return a * vec(0,1); }
vec unmr(vec a){ return uvec( nmr(a) ); }
vec unml(vec a){ return uvec( nml(a) ); }

bool prll(point a1, point a2, point b1, point b2){ return eq( cross( a2 - a1, b2 - b1 ), 0 ); }
bool prll(vec v1, vec v2){ return eq( cross(v1, v2), 0 ); }

int ccw(point a, point b, point x){
  b -= a;
  x -= a;
  if( gtz( cross(b,x) ) ) return LEFT;
  if( ltz( cross(b,x) ) ) return RIGHT;
  if( ltz( dot(b,x) ) ) return BACK;
  if( lt( abs(b), abs(x) ) ) return FRONT;
  return OVER;
}

bool intersected_seg(seg a, seg b)
{
  return ( leq( cross(a.sc-a.fr,b.fr-a.fr) * cross(a.sc-a.fr,b.sc-a.fr), 0 ) &&
	   leq( cross(b.sc-b.fr,a.fr-b.fr) * cross(b.sc-b.fr,a.sc-b.fr), 0 ) );
}
bool intersected_l(line a, line b){
  return !prll(a.fr,a.sc,b.fr,b.sc);
}
point intersection_seg(seg a, seg b)
{
  elem d1 = dist_l(b,a.fr);
  elem d2 = dist_l(b,a.sc);
  return a.fr + ( d1 / (d1 + d2 ) ) * (a.sc-a.fr);
}
point intersection_l(line a, line b)
{
  vec va = a.sc - a.fr;
  vec vb = b.sc - b.fr;
  return a.fr + va * ( cross(vb, b.fr - a.fr) / cross(vb,va) );
}
bool intersection_seg(seg a, seg b, point &ret){
  if( intersected_seg(a,b) ){
    ret = intersection_seg(a,b);
    return true;
  }
  return false;
}
bool intersection_l(line a, line b, point &ret){
  if( intersected_l( a, b ) ){
    ret = intersection_l( a, b );
    return true;
  }
  return false;
}
bool intersection_lseg(line l, seg s, point &ret){
  point tmp;
  if( intersection_l(l,s,tmp) ){
    if(ccw(s.fr,s.sc,tmp)&OVER){
      ret=tmp;
      return true;
    }
  }
  return false;
}

ostream &operator<<(ostream &os, const pair<point,point> &p){
  os << p.fr << "-" << p.sc;
  return os;
}

int main(){
  while(true){
    int n;
    elem max_x = -infty;
    vector<point> vp;
    cin >> n;
    if( n == 0 ) break;
    for(int i = 0; i < n; ++i){
      elem x,y;
      cin >> x >> y;
      vp.push_back(point(x,y));
      vp.push_back(point(x,y-1));
    }
    for(int i = 0; i < vp.size(); ++i){
      for(int j = i+1; j < vp.size(); ++j){
	line l(vp[i],vp[j]);
	for(int m = 0; m < vp.size(); m += 2){
	  point tmp;
	  seg vertical( vp[m], vp[m+1] );
	  
	  if( intersection_lseg(l,vertical,tmp) ){
	    max_x = gt( vp[m].real(), max_x ) ? vp[m].real() : max_x;
	  }else{
	    if( m>1 && intersection_lseg(l,seg(vp[m],vp[m-2]),tmp) ){
	      max_x = gt(tmp.real(),max_x)?tmp.real():max_x;
	    }
	    if( m>0 && m<vp.size()-1 && intersection_lseg(l,seg(vp[m+1],vp[m-1]),tmp) ){
	      max_x = gt(tmp.real(),max_x)?tmp.real():max_x;
	    }
	    break;
	  }
	}
      }
    }
    if( eq(max_x,vp.back().real()) ){
      printf("%s\n", "Through all the pipe.");
    }else{
      printf("%.2Lf\n", max_x);
    }
  }
  return 0;
}
