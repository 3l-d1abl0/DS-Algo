#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int src, dest;
};

struct Graph{

    int V,E;
    struct Edge *edge;
    pair <long long, pair<int, int> > *p;//[MAX];
};


struct subset{

    int parent, sz;
};

struct Graph *createGraph(int v, int e){

    struct Graph *gr = (struct Graph*)malloc(sizeof(struct Graph));
    gr->V = v;
    gr->E = e;

    //gr->edge = (struct Edge *)malloc(gr->E* sizeof(struct Edge));
    gr->p = new pair <long long, pair<int, int> >[e];
    return gr;
}

int root(struct subset *sub, int i){

    if(sub[i].parent !=i)
        sub[i].parent = root(sub, sub[i].parent);

    return sub[i].parent;
}

void uniOn(struct subset *sub, int x, int y){

    int xroot = root(sub, x);
    int yroot = root(sub, y);

    if(sub[xroot].sz < sub[yroot].sz){
        sub[xroot].parent = yroot;
        sub[yroot].sz += sub[xroot].sz;
    }else if(sub[xroot].sz >= sub[yroot].sz){
        sub[yroot].parent = xroot;
        sub[xroot].sz += sub[yroot].sz;
    }/*else{
        sub[yroot].parent = xroot;
        sub[xroot].sz += sub[yroot].sz;
    }*/
}

bool isCycle(struct Graph *gr){

    int v = gr->V;
    int e= gr->E;

    struct subset *sub = (struct subset*)malloc(v*sizeof(struct subset));

    for(int i=0; i<v; i++){
        sub[i].parent = i;
        sub[i].sz =0;
    }

    for(int i=0; i<e; i++){

        int x = root(sub, gr->edge[i].src);
        int y = root(sub, gr->edge[i].dest);

        if(x==y)
            return true;
        uniOn(sub, x,y);
    }

    return false;

}

int kruskal(struct Graph *gr){

    //1.Sort weighted Edges for smaller weight to Higher
    sort(gr->p, gr->p + gr->E);

    //2. Initalize things for Connected components
    struct subset *sub = (struct subset*)malloc(gr->V*sizeof(struct subset));

    for(int i=0; i<gr->V; i++){
        sub[i].parent = i;
        sub[i].sz =0;
    }

    int minWeight =0;
    pair <long long, pair<int, int> > result[gr->V];
    int idx=0;
    for(int i=0; i<gr->E; i++){

        //cout<<gr->p[i].first<<" : "<<gr->p[i].second.first<<","<<gr->p[i].second.second<<endl;

        //3. check if the two verteces are connected or Not

        int x = root(sub,gr->p[i].second.first);
        int y = root(sub,gr->p[i].second.second);

        if(x!=y){   //if not connected
            minWeight += gr->p[i].first;
            uniOn(sub, x, y);

            result[idx++] = make_pair(gr->p[i].first, make_pair(gr->p[i].second.first, gr->p[i].second.second));
        }

    }

    for(int i=0; i<idx; i++){
        cout<<result[i].first<<" :: "<<result[i].second.first<<","<<result[i].second.second<<endl;
    }

    return minWeight;
}

int main(){

        /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */

    int v= 4, e=5;

    struct Graph *gr = createGraph(v,e);

    //p[i] = make_pair(weight, make_pair(x, y));

    gr->p[0] = make_pair(10, make_pair(0,1));
    gr->p[1] = make_pair(6, make_pair(0,2));
    gr->p[2] = make_pair(5, make_pair(0,3));
    gr->p[3] = make_pair(15, make_pair(1,3));
    gr->p[4] = make_pair(4, make_pair(2,3));



    cout<<"MST :: weight : "<<kruskal(gr)<<endl;

    return 0;
}

/*
O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply find-union algorithm.
The find and union operations can take atmost O(LogV) time. So overall complexity is O(ELogE + ELogV) time.
*/
