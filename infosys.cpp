/*
 " I AM VENGEANCE , I AM THE KNIGHT , I AM THE BATMAN ! "
____ __ __ __ __ __ ___                             ___ __ __ __ __ __ ____
 `-._:  .:'   `:::  .:\           |\__/|           /::  .:'   `:::  .:.-'
     \      :          \          |:   |          /         :       /
      \     ::    .     `-_______/ ::   \_______-'   .      ::   . /
       |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|
       |     ;::         ;::         ;::         ;::         ;::  |
       |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|
       /     :           :           :           :           :    \
      /______::_____     ::    .     ::    .     ::   _____._::____\
                    `----._:: ::'  :   :: ::'  _.----'
                           `--.       ;::  .--'
                               `-. .:'  .-'
                                  \    /
                                   \  /
                                    \/
*/


#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

using ll = long long;
using pI = pair<int,int>;
using pL = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpI = vector<pI>;
using vpL = vector<pL>;

const int MOD=1000000007;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};


/*--------------------No.of digits------------------*/
int cntDig(int n) {
	if(n==0)
	return 1;

	return floor(log10(n)+1);
}




/*------------------isPrime--------------*/
int isPrime(int n) {
    bool h=0;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) {
            h=1;
        }
    }
    return h==0;
}




/*-----------------------check palindrome---------------------------*/
bool check(string s) {
	int n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1])
		return 0;
	}
	return 1;
}





/*------------------------print "Yes/No"-------------------*/
void print(bool h){
	if(h)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}




/*------------------------power of 2 numbers with MOD-----------------------*/
int powerMOD(int a, int b, int MOD) {
    int res = 1;
    while(b>0){
        if(b&1)
        res=(res*a)%MOD;

        a=(a*a)%MOD;
        b=b>>1;
    }
    return res%MOD;
}


struct Node {
    int length;   // Length of longest increasing subarray with distinct parities
    int maxOdd;   // Length of longest increasing subarray ending with an odd number
    int maxEven;  // Length of longest increasing subarray ending with an even number
};

void buildTree(vector<Node>& segmentTree, const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        // Initialize values for a single element
        if (arr[start] % 2 == 0) {
            segmentTree[node] = {1, 0, 1};  // Even number
        } else {
            segmentTree[node] = {1, 1, 0};  // Odd number
        }
    } else {
        int mid = (start + end) / 2;
        buildTree(segmentTree, arr, 2 * node + 1, start, mid);
        buildTree(segmentTree, arr, 2 * node + 2, mid + 1, end);
        // Merge the information from children to parent
        segmentTree[node].length = max({segmentTree[2 * node + 1].length, segmentTree[2 * node + 2].length,
                                segmentTree[2 * node + 1].maxOdd + segmentTree[2 * node + 2].maxEven,
                                segmentTree[2 * node + 1].maxEven + segmentTree[2 * node + 2].maxOdd});
		segmentTree[node].maxOdd = max(segmentTree[2 * node + 1].maxOdd + 1, segmentTree[2 * node + 2].maxOdd);
		segmentTree[node].maxEven = max(segmentTree[2 * node + 1].maxEven + 1, segmentTree[2 * node + 2].maxEven);

    }
}

Node querySegmentTree(const vector<Node>& segmentTree, int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        // No overlap, return a dummy node
        return {0, 0, 0};
    }

    if (start >= l && end <= r) {
        // Complete overlap, return the node
        return segmentTree[node];
    }

    int mid = (start + end) / 2;
    Node left = querySegmentTree(segmentTree, 2 * node + 1, start, mid, l, r);
    Node right = querySegmentTree(segmentTree, 2 * node + 2, mid + 1, end, l, r);

    // Merge the information from children to parent
    Node result;
    result.length = max({left.length, right.length, left.maxOdd + right.maxEven, left.maxEven + right.maxOdd});
    result.maxOdd = max(left.maxOdd + 1, right.maxOdd);
    result.maxEven = max(left.maxEven + 1, right.maxEven);

    return result;
}

// Function to process Type 1 Query
void type1Query(vector<Node>& segmentTree, vector<int>& arr, int node, int start, int end, int index, int value) {
    if (start > index || end < index) {
        return; // No overlap
    }

    if (start == end) {
        // Leaf node, update the value
        if (value % 2 == 0) {
            segmentTree[node] = {1, 0, 1};  // Even number
        } else {
            segmentTree[node] = {1, 1, 0};  // Odd number
        }
        arr[start] = value;
    } else {
        int mid = (start + end) / 2;
        if(index<=mid)
        type1Query(segmentTree, arr, 2 * node + 1, start, mid, index, value);
    	else
        type1Query(segmentTree, arr, 2 * node + 2, mid + 1, end, index, value);
       

        segmentTree[node].length = max({segmentTree[2 * node + 1].length, segmentTree[2 * node + 2].length,
                                        segmentTree[2 * node + 1].maxOdd + segmentTree[2 * node + 2].maxEven,
                                        segmentTree[2 * node + 1].maxEven + segmentTree[2 * node + 2].maxOdd});
        segmentTree[node].maxOdd = max(segmentTree[2 * node + 1].maxOdd + 1, segmentTree[2 * node + 2].maxOdd);
        segmentTree[node].maxEven = max(segmentTree[2 * node + 1].maxEven + 1, segmentTree[2 * node + 2].maxEven);
    }
}

void updateElement(vector<Node>& segmentTree, vector<int>& arr, int index, int value) {
    arr[index] = value;
    type1Query(segmentTree, arr, 0, 0, arr.size() - 1, index, value);
}

/*------------------------Solve-----------------------------*/
void solve(){
    int n,q;cin>>n;
    vi v(n);
    for(int &i:v)cin>>i;

    vector<Node> segmentTree(4 * n);
    buildTree(segmentTree, v, 0, 0, n - 1);

    cin>>q;
	
    int ans=0;
	for(int i=0;i<q;i++){
		int x,y,z;
		cin>>x>>y>>z;

		if(x==1){
			updateElement(segmentTree, v, y-1, z);
		}else if(x==2){
			Node result = querySegmentTree(segmentTree, 0, 0, n - 1, y-1, z-1);
			ans+=result.length;
		}
	}
	cout<<ans<<endl;
    return;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
