#include<bits/stdc++.h>


using namespace std;

void rev(char *, char *);

void reverseWords(char *s){

    char *st = s;
    char *en = s;

    while(*en){
            en++;
            if( *en == ' '){
                    rev(st,en-1 );
                    st=en+1;
            }
            if(*en == '\0'){
                    cout<<"---"<<endl;
                rev(st, en-1);
            }

            //en++;
    }

    rev(s,en-1);
}


void revWords(char *s){

    char *st = NULL;
    char *en = s;

    while(*en){

        //skiping the blank spaces//checking fir non-blank  after Blank
        if(st == NULL && *en !=' '){
            st=en;  cout<<" =-= "<<*en<<endl;
        }
        //reverse the words
        if(st!=NULL && (*(en+1) == ' ' || *(en+1) =='\0') ){
            rev(st, en);
            st = NULL;
        }

        en++;
    }

    rev(s,en-1);
}


void rev(char *st, char *en){
    char temp;
    cout<<"----"<<endl;
    for (char *i= st; i<=en; i++){
        cout<<*i;
    }
    cout<<endl;

    while(st<en){
        temp = *st;
        *st = *en;  st++;
        *en = temp; en--;
    }
}


int main()
{
  char s[] = "  i like      this program very much";
  char *temp = s;
  //reverseWords(s);
  revWords(s);
  printf("--%s--", s);
  getchar();
  return 0;
}
