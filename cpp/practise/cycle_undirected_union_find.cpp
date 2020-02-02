#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int src, dest;
};

struct Graph{

    int V,E;
    struct Edge *edge;
};


struct subset{

    int parent, sz;
};

struct Graph *createGraph(int v, int e){

    struct Graph *gr = (struct Graph*)malloc(sizeof(struct Graph));
    gr->V = v;
    gr->E = e;

    gr->edge = (struct Edge *)malloc(gr->E* sizeof(struct Edge));

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

int main(){

   /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */

    int v= 3, e=2;

    struct Graph *gr = createGraph(v,e);
    /*
    gr->edge[0].src = 0;
    gr->edge[0].dest = 1;

    gr->edge[1].src = 1;
    gr->edge[1].dest = 2;

    gr->edge[2].src = 0;
    gr->edge[2].dest = 2;
    */
    /*
    (1, 0);(0, 2)(2, 0)(0, 3)(3, 4);
    */
    gr->edge[0].src = 1;
    gr->edge[0].dest = 0;

    gr->edge[1].src = 1;
    gr->edge[1].dest = 2;

    /*gr->edge[2].src = 0;
    gr->edge[2].dest = 2;

    gr->edge[3].src = 0;
    gr->edge[3].dest = 3;

    gr->edge[4].src = 3;
    gr->edge[4].dest = 4;*/

    if(isCycle(gr)){
        printf("Has Cycle !");
    }else{
        printf("No Cycle !");
    }

    return 0;
}
