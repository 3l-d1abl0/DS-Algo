#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
double dist(int x,int y)
{
    return sqrt((x-50)*(x-50)+(y-50)*(y-50));
}

int main()
{
    fstream myfile("progress_pie.txt",std::ios_base::in);
    ofstream output;
    output.open("output.txt");
    int t;myfile >> t;
    for(int i=1;i<=t;i++)
    {
        int per,x,y; myfile >> per >> y >> x;
        //cout<<atan2(y,x)*180/PI<<endl;
        double d=atan2(y-50,x-50)*180/PI;
        //cout<<"d is "<<d<<endl;
        if(d<0)
            d=360+d;
        //cout<<"degree obtained is "<<d<<endl;
        //cout<<"dist(x,y) is "<<dist(x,y)<<endl;
        if(dist(x,y)>50.0)
            output<<"Case #"<<i<<": "<<"white\n";
        else
        {
            if((double)per*360/100>d)
                output<<"Case #"<<i<<": "<<"black\n";
            else
                output<<"Case #"<<i<<": "<<"white\n";
        }
    }
}
