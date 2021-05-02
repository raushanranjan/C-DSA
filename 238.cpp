#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    //int t;
    //cin >> t;
    //while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
   // }
    return 0;
}// } Driver Code Ends


bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
int maxMeetings(int start[], int end[], int n) {
    // Your code hereint n = sizeof(arr)/sizeof(arr[0]); 
     vector< pair <unsigned int,unsigned int> > vect ;;
    // Entering values in vector of pairs 
    for (int i=0; i<n; i++) 
        vect.push_back( make_pair(start[i],end[i]) ); 
    sort(vect.begin(), vect.end(), sortbysec);

 for (int i=0; i<n; i++){
        cout << vect[i].first << " "<< vect[i].second;
}

    int count = 1;
    int i=0;
    int j=1;
      while(j<n){
          int dif = vect[j].first - vect[i].second;
          if (dif >= 0){
              count++;
              i=j;
              j++;

          }
          else{
              j++;
          }
          
      }
      return count;
}