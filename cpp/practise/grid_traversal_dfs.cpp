#include<bits/stdc++.h>
#include<iostream>
#define SIZE 5  //size of our grid area ,can also be more than 5X5
#define MAX_PATH_SIZE 25   //we need to store the shortest path in an array/vector of x and y co-ordinates
#define NO_OF_DIRECTIONS 4  //we can traverse in four directions in this case, may be different in different grid problems
using namespace std;

int originalGrid[SIZE][SIZE]; //stores the input grid
bool flag[SIZE][SIZE]; //a boolean array.any value in this=true means that point in the grid has been seen at/before that time instant

int direction[NO_OF_DIRECTIONS][2]={{0,1},{1,0},{0,-1},{-1,0}}; // RIGHT , UP , LEFT ,BOTTOM -the order is important in the sense that
//RIGHT and BOTTOM must come before UP and LEFT as final point in lower right corner

bool finish=false; // a boolean variable to stop the graph traversal as soon as we reach the end point the first time
//this is required since there may be more than one path from start point to end point and we do not need to print all
//those paths.We just need the first shortest path and if we choose the direction array carefully DFS will ensure us that
//as soon as we reach the end point it is the shortest path indeed

struct Point
{                 //stores a grid/path point
    int x;
    int y;
};

Point path[MAX_PATH_SIZE];//this array will store the final result of the shortest path
int nextX,nextY;

    void init()
    {
        int i=0,j=0;
        for(i=0;i<SIZE;i++)
        {
        for(j=0;j<SIZE;j++)
        scanf("%d",&originalGrid[i][j]);  //input the original grid
        // cout<<endl;
        }

        for(i=0;i<SIZE;i++)
            for(j=0;j<SIZE;j++)
            flag[i][j]=false; // initialize flag array to all false,as initially no grid point has been traversed

        for(i=0;i<MAX_PATH_SIZE;i++)
        {
            path[i].x=-1;path[i].y=-1; //this is not mandatory,just initialising with -1 for debugging purposes
        }

        path[0].x=0;path[0].y=0; //we always start from (0,0) so saving it in our shortest path array

    }

    void printPath(int pathIndex) //prints our path array . pathIndex=length of the path
    {
        for(int i=0;i<pathIndex;i++)
        {
        printf("(%d, %d)\n", path[i].x, path[i].y);
        }
    }

        void dfs(int x,int y,int pathIndex)
        {

            if(x==SIZE-1 && y==SIZE-1) //we have found the best path/the end point , print it
            {
            //pathIndex++;
            printPath(pathIndex);
            //finish=true; //we do not need to continue with our graph traversal any more.we have found shortest path
            return;
            }

            if(finish)  //this will only be true if any of the recursive calls had found the first end point.Then this is needed
            return;  //to stop all other recursive sub-calls  from propagating furthers

            cout<<"Visiting .....  "<<x<<":"<<y<<" -->>"<<originalGrid[x][y]<<endl;

            for(int i=0;i<4;i++) //we need to move in all four directions but in the specified direction
            {
                nextX=x+direction[i][0]; //calculating next point in the grid
                nextY=y+direction[i][1];
                //cout<<"Next :: "<<nextX<<"  "<<nextY<<endl;
                //cout<<"FLag ::"<<flag[nextX][nextY]<<endl;
                //if it is a valid point, and it is not a wall and,it has not been traversed before
                //all conditions need to be true in order to consider it as a part of the path
                if(nextX>=0 && nextY >=0 && nextX<SIZE && nextY<SIZE && flag[nextX][nextY]==false)
                {
                            //&& originalGrid[nextX][nextY]==0

                            flag[nextX][nextY]=true; // we mark this point as seen
                            path[pathIndex].x=nextX; //stores the current grid point in the path array for shortest path .
                            path[pathIndex].y=nextY; //this is because dfs will give us the shortest path
                            //cout<<"Next :: "<<nextX<<"  "<<nextY<<endl;
                            dfs(nextX,nextY,pathIndex+1); // recursive sub-call .this means we need to continue our graph traversal
                            //as we have still not reached end point.Note we have incremented pathIndex as now
                            //the current point is part of our shortest path and pathIndex is our pathLength
                            flag[nextX][nextY]=false;//we  mark this point as unseen so that some other recursive call can use
                            //this point in its path
                }
            }

        }
        void findShortestPath()  //always for recursive functions keep a base function to which program control returns
        {                   //after all the recursive calls finish
                            //we are starting our Depth-First Traversal from (0,0) and path length=1 as (0,0) is already part of path
                            cout<<"Calling Dfs.. "<<endl;
                dfs(0,0,1);
        }

        //our execution starts from here
        int main()
        {
                init(); //initialize all our variables here
                printf("INit Done..... \n");
                findShortestPath(); //use this to find the shortest path
                //system("pause");
                return 0;
        }

http://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/
