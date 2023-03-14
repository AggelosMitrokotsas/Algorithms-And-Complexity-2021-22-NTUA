#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;
int *p, *prefix, *length;
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main() {
    int N, K;
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    fastscan(N);
    fastscan(K);
    //scanf("%d", &N);
    //scanf("%d", &K);
    //cin >> N >> K;
    //ifstream inFile(argv[1]);
    //inFile >> N;
    //inFile >> K;
    p = (int*) malloc(N * sizeof(int));
    prefix = (int*) malloc((N+1)* sizeof(int));
    length = (int*) malloc((K+1) * sizeof(int));
    //int p[N], prefix[N+1], length[K+1];
    int x=N+2;
    int temp;
    for(int i=0; i<N; i++) {
        fastscan(p[i]);
        //scanf("%d", &p[i]);
    //cin >> p[i];
    // inFile >> p[i];
    
    }
    length[0] = 0; //το κανω ωστε σε περιπτωση που βρω διαστημα με αθροισμα Κ (αφου η ασκηση επιτρεπει να βάλω ενα μονο διαστημα ως απαντηση) να το ταιριαξω με το διαστημα αθροισματος 0 (μηκους 0 οπως λεω εδω) και να μη χρειαζεται παραπανω ifs
    for(int i=1; i<K+1; i++) { // αυτος ο πινακας μου δειχνει το (ελαχιστο) μηκος του μονοπατιου που θελω για να φτασω στο αθροισμα i
        length[i] = N+1;
    }
    prefix[0] = 0; //για να μη χρειαζεται να κανω if statements μεσα στη for και να ελεγχω περιπτωσεις για τα ακρα 
    for(int i = 1; i<N+1; i++) {
        prefix[i] = prefix[i-1] + p[i-1]; //prefix[1] = prefix[0] + p[0], prefix[2]=prefix[1] + p[1], κοκ
    }

    for(int i = 1; i<N+1; i++){ //τρεχω πανω στον prefix, γι αυτο εχω Ν+1 στοιχεια
              // γεμιζω τον πινακα με τα μηκη
        for(int j=0; j<i; j++) {
            if((prefix[i] - prefix[j]) <=K) { //   
                length[prefix[i] - prefix[j]] = min(length[prefix[i] - prefix[j]],   i-j);//εδω εχω (j,i) διαστημα.
            }
        }


        for(int j=N; j>i; j--){ 
            //εδω εχω (i,j) διαστημα.
            temp = prefix[j]-prefix[i]; 
            if(temp <=K ) {
                x = min(x, (length[K-temp] + j-i));

            }
        }

    }
    if(x == N+2) x = -1;


    printf("%d\n", x);
    //cout << x << endl;
    return 0;
}
