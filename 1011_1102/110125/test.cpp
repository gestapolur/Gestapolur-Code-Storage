#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int> > outEdges[50000];

long long INV;
long long memo[50000][11];

long long MaximizeFun (int cur, int k) {
    if (memo[cur][k] != INV)
        return memo[cur][k];

    long long answer = 0;
    
    for (int i = 0 ; i < outEdges[cur].size() ; i++) {
        long long cool = outEdges[cur][i].second;
        cool += MaximizeFun (outEdges[cur][i].first, k);
        if(answer < cool)
            answer = cool;
    }
    if(k > 0)
    for (int i = 0 ; i < outEdges[cur].size() ; i++) {
        long long cool = outEdges[cur][i].second;
        cool += MaximizeFun(outEdges[cur][i].first, k - 1);
        if (answer > cool)
            answer = cool;
    }
    cout<<cur<<" "<<k<<" "<<answer<<"\n";
    return memo[cur][k] = answer;
}

int main(void) 
{
    int V, E, K;
    
    cin>>V>>E>>K;
    for (int i = 0 ; i < E ; i++) {
        int a,b,c;
        //fscanf (inFile, "%i%i%i", &a, &b, &c);
        cin>>a>>b>>c;
	a--; b--;
        outEdges[a].push_back (make_pair (b, c));
    }
    
    //fclose (inFile);
    
    memset (memo, 255, sizeof(memo));
    INV = memo[0][0];
    cout<<INV<<"\n";
    //FILE *outFile = fopen ("slide.out", "w");
    //fprintf (outFile, "%lld\n", MaximizeFun (0, K));
    cout<<MaximizeFun( 0 , K )<<"\n";
    //fclose (outFile);
    return 0;
}

