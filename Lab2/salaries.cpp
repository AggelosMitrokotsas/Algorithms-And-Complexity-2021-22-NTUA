#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

int64_t* p = (int64_t*) malloc(1000000*sizeof(*p));
int64_t* a = (int64_t*) malloc(1000000*sizeof(*p));

int LIS(long long X[], int N) {
		int parent[N]; //Tracking the predecessors/parents of elements of each subsequence.
		int increasingSub[N+1]; //Tracking ends of each increasing subsequence.
		int length = 0; //Length of longest subsequence.
		
		for(int i=0; i< N; i++)
		{
			//Binary search
			int low = 1;
			int high = length;
			while(low <= high)
			{
				int mid = ceil((low + high)/2);
				
				if(X[increasingSub[mid]] < X[i])
					low = mid + 1;
				else
					high = mid - 1;
			}
			
			int pos = low;
			//update parent/previous element for LIS
			parent[i] = increasingSub[pos-1];
			//Replace or append
			increasingSub[pos] =  i;
			
			//Update the length of the longest subsequence.
			if(pos > length)
				length=pos;
		}
		/* //Generate LIS by traversing parent array
		int LIS[length];
		int k 	= increasingSub[length];
		for(int j=length-1; j>=0; j--)
		{
			LIS[j] =  X[k];
			k = parent[k];
		}
		
		
		for(int i=0; i<length; i++)
		{ 
            printf("%d\n", LIS[i]);
		} */

		return length;
	}

int LDS(long long X[], int N) {
		int parent[N]; //Tracking the predecessors/parents of elements of each subsequence.
		int decreasingSub[N+1]; //Tracking ends of each increasing subsequence.
		int length = 0; //Length of longest subsequence.
		
		for(int i=0; i< N; i++)
		{
			//Binary search
			int low = 1;
			int high = length;
			while(low <= high)
			{
				int mid = ceil((low + high)/2);
				
				if(X[decreasingSub[mid]] > X[i])
					low = mid + 1;
				else
					high = mid - 1;
			}
			
			int pos = low;
			//update parent/previous element for LDS
			parent[i] = decreasingSub[pos-1];
			//Replace or append
			decreasingSub[pos] =  i;
			
			//Update the length of the longest subsequence.
			if(pos > length)
				length=pos;
		}
		return length;
        /*
		//Generate LDS by traversing parent array
		int LDS[length];
		int k 	= increasingSub[length];
		for(int j=length-1; j>=0; j--)
		{
			LDS[j] =  X[k];
			k = parent[k];
		}
		
		
		for(int i=0; i<length; i++)
		{ 
            printf("%d\n", LDS[i]);
		} */
	}


int main() {
    int K, N;
    scanf("%d %d",&N, &K);

    for(int i=0; i<N; i++) {
        scanf("%lld", &p[i]);
		a[i] = p[i];
    }

int myMax= -1;
int j=0, k=N-1;

while(j<=k) {
	for(int i=j; i<=k; i++) {
    a[i] += K;
	}
	if(myMax <= LIS(a, N)) myMax = LIS(a, N);
	for(int i=0; i<N; i++) {
		a[i] = p[i];
	}
	j++;
	//k--;
}
/*
for(int i=0; i<N; i++) {
	if(p[i] == *max_element(p, p+N)) {
    for(int j=i+1; j<N; j++) {
    p[j]+=K;
	 }
	 break;
	}
} */

/* for(int i=0; i<N; i++) {
	if(p[i] == *min_element(p, p+N)) {
    for(int j=0; j<i-1; j++) {
    p[j]-=K;
	}
	break;
}
} */
 

//myMax = LIS(p, N);

printf("%d\n", myMax);
 return 0;
}