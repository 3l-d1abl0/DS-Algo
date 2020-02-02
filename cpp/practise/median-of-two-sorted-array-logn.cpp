#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;



float getMedian(int X[], int sx, int Y[], int sy){

    int start= 0, end = sx;

    while(start <=end){
        int g2X = (end+start) /2;
        int g2Y = (sx+sy+1)/2 - g2X;

        int leftX = (g2X==0) ? INT_MIN : X[g2X-1];
        int leftY = (g2Y==0) ? INT_MIN : Y[g2Y-1];

        int rightX = (g2X==sx) ? INT_MAX : X[g2X];
        int rightY = (g2Y==sy) ? INT_MAX : Y[g2Y];

        if(leftX <= rightY && leftY <= rightX){
            if( (sx +sy)%2==0 )
                return ( max(leftX, leftY) + min(rightX, rightY))/2;
            else
                return max(leftX, leftY);
        }else if(leftX > rightY){ //too much on the right side of Partition
            end = g2X-1;
        }else{
            start = g2X+1;
        }
    }


}

int main(){

    //int X[] = {2, 3, 5 ,8};
    int X[] = {1, 3, 8, 9, 15};
    //int Y[] = {10, 12, 14, 16, 18,20 };
    int Y[] = {7, 11, 19, 21, 18, 25};

    int sx = sizeof(X)/sizeof(X[0]);
    int sy = sizeof(Y)/sizeof(Y[0]);

    if(sx <sy )
        cout<<getMedian(X, sx, Y, sy )<<endl;
    else
        cout<<getMedian(Y, sy, X, sx)<<endl;

    return 0;
}
