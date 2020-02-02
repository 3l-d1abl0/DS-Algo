#include <bits/stdc++.h>
using namespace std;
int t;
int currentEnergy,farmPosition=-1,n;
int m[1001],a[1001];

bool canMove() {
   return currentEnergy > 0 && farmPosition < (n - 1);
  }

void move() {
   if(canMove()) {
    farmPosition++;
    currentEnergy--;
   }
  }

int getMilk() {
   return m[farmPosition];
}
int getApple() {
   return a[farmPosition];
}
int getRemaining(int start, int end) {
   
   int endPos = (end >= n ? n - 1 : end);
   int maxapple=0;
   for(int index = start; index <= endPos; index++) {
    maxapple += a[index];
   }
   return maxapple;
}
int getRemainingApples(int farmToVisit) {
   return getRemaining(farmPosition + 1, farmToVisit+farmPosition);
  }
int getRemainingApple(int farmToVisit) {
   return getRemaining(farmPosition, farmToVisit+farmPosition);
  }

void consumeEnergy() {
   currentEnergy += m[farmPosition];
  }

int getApplesCollected() {
  int collectedApples = 0;
  
  while(canMove()) { 
   move();

   int consumableEnergy = getMilk();
   int applesToBeCollectedWithCurEnergy = getRemainingApple(currentEnergy);
   int applesToBeCollectedWithAllEnergy = getRemainingApples(currentEnergy + consumableEnergy);
   if(applesToBeCollectedWithAllEnergy > applesToBeCollectedWithCurEnergy) {
    consumeEnergy();
   } 
   else {
    collectedApples += getApple();
       }
  }  
  return collectedApples;
 }
 int main()
 {

  int ans;
  cin>>n>>currentEnergy;
  for (int i = 0; i < n; ++i)
  {
    cin>>m[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  ans=getApplesCollected();
  cout<<ans<<endl;
  
  return 0;
 }