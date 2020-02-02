#include<bits/stdc++.h>

using namespace std;

int solution(string &E, string &L) {
    //int entryHour;
    //int entryMin;

    int entryHour = E[0]-'0';       int entryMin = E[3]-'0';
         entryHour = (entryHour*10)+(E[1]-'0');     entryMin = (entryMin*10)+(E[4]-'0');

    int exitHour = L[0]-'0';        int exitMin = L[3]-'0';
         exitHour = (exitHour*10) +(L[1]-'0');      exitMin = (exitMin*10)+(L[4]-'0');

    //cout<<entryHour<<":"<<entryMin<<endl;
    //cout<<exitHour<<":"<<exitMin<<endl;

         //Diff
         if(exitMin<entryMin){
            exitMin+=60;    exitHour--;
         }

         int durMin = exitMin - entryMin;
         int durHour = exitHour - entryHour;
         //cout<<"Hour "<<durHour<<":"<<durMin<<endl;

         if(durMin>0)
                durHour++;

        //cout<<"Hour "<<durHour<<":"<<durMin<<endl;
         int cost=2;
         if(durHour>=1){
                cost+=3; durHour--;
         }
            cost += (durHour * 4);


        return cost;
}


int main(){

    //string entry ="10:00";
    string entry ="02:45";
    //string exit = "13:21";
    string exit = "04:10";

    cout<<solution(entry, exit)<<endl;

    return 0;
}
