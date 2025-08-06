/* The functions which
builds the segment tree */

void buildSegmentTree(int i, int l, int r, int segTree[], int arr[]) {
    if(l == r) {
        segTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segTree, arr);
    
    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

int *constructST(int arr[], int n) {
    // Your code here
    int *segTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segTree, arr);
    return segTree;
}

int Query(int st, int end, int i, int l, int r, int segTree[]) {
    if(l > end || r < st) return INT_MAX;
    if(l >= st && r <= end) return segTree[i];
    int mid = l + (r - l) / 2;
    return min(Query(st, end, 2 * i + 1, l, mid, segTree), Query(st, end, 2 * i + 2, mid + 1, r, segTree));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    // Your code here
    return Query(a, b, 0, 0, n - 1, st);
}