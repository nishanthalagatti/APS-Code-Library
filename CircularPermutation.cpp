#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class NodeT{
public:
    int val, index;
    NodeT() : val(1e9), index(-1) {}
    NodeT(int v, int i) : val(v), index(i) {}
};

class SegmentTree{
public:
    int n;
    vector<NodeT> tree;
    vector<bool> islazy;
    vector<int> lazy;
    SegmentTree(int sz){
        n = sz;
        tree.resize(4 * n + 1);
        islazy.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }
    void lazyUpdate(int curr, int l, int r){
        if (l != r){
            islazy[curr << 1] = 1;
            islazy[curr << 1 | 1] = 1;
            lazy[curr << 1] += lazy[curr];
            lazy[curr << 1 | 1] += lazy[curr];
        }
        tree[curr].val += lazy[curr];
        lazy[curr] = 0;
        islazy[curr] = 0;
    }
    void combine(NodeT &parent, NodeT &left, NodeT &right){
        if (left.val < right.val){
            parent.val = left.val;
            parent.index = left.index;
        }
        else{
            parent.val = right.val;
            parent.index = right.index;
        }
    }
    void build(vector<int> &arr, int curr, int l, int r){
        if (l == r){
            tree[curr] = NodeT(arr[l], l);
            return;
        }
        int mid = (l + r) / 2;
        build(arr, curr << 1, l, mid);
        build(arr, (curr << 1) | 1, mid + 1, r);
        combine(tree[curr], tree[curr << 1], tree[(curr << 1) | 1]);
    }
    void update(int curr, int l, int r, int i, int j, int val){
        if (islazy[curr])
            lazyUpdate(curr, l, r);
        if (j < l || i > r || i > j)
            return;
        if (i <= l && r <= j){
            islazy[curr] = 1;
            lazy[curr] += val;
            lazyUpdate(curr, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(curr << 1, l, mid, i, j, val);
        update(curr << 1 | 1, mid + 1, r, i, j, val);
        combine(tree[curr], tree[curr << 1], tree[curr << 1 | 1]);
    }
    NodeT query(int curr, int l, int r, int i, int j){
        if (islazy[curr])
            lazyUpdate(curr, l, r);
        if (j < l || i > r)
            return NodeT();
        if (i <= l && r <= j)
            return tree[curr];
        int mid = (l + r) / 2;
        NodeT ans;
        NodeT left = query(curr << 1, l, mid, i, j);
        NodeT right = query(curr << 1 | 1, mid + 1, r, i, j);
        combine(ans, left, right);
        return ans;
    }
};

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1);
    SegmentTree tree(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    tree.build(A, 1, 1, N);
    vector<int> ans(N + 1, 0);
    set<int> zeroPositions;
    for (int c = 0; c < N; c++){
        NodeT minn = tree.query(1, 1, N, 1, N);
        if (minn.val < 0){
            cout << -1 << endl;
            return;
        }
        while (minn.val == 0){
            zeroPositions.emplace(minn.index);
            tree.update(1, 1, N, minn.index, minn.index, 1e9);
            minn = tree.query(1, 1, N, 1, N);
        }
        if (zeroPositions.size() == 0){
            cout << -1 << endl;
            return;
        }
        int id = -1;
        if (zeroPositions.size() == 1)
            id = (*zeroPositions.begin());
        else{
            int last = *(--zeroPositions.end());
            int first = *zeroPositions.begin();
            if ((N - last + first) > K)
                id = first;
            else{
                int start = first;
                while (true){
                    auto ptr = zeroPositions.upper_bound(start + K);
                    if (ptr == zeroPositions.end())
                        break;
                    int curr = *ptr;
                    ptr--;
                    int prev = *ptr;
                    if ((curr - prev) > K){
                        id = curr;
                        break;
                    }
                    else
                        start = curr;
                }
            }
        }
        if (id == -1){
            cout << -1 << endl;
            return;
        }
        zeroPositions.erase(id);
        ans[id] = c + 1;
        if (id - K < 1){
            tree.update(1, 1, N, 1, id, -1);
            tree.update(1, 1, N, N + id - K, N, -1);
        }
        else
            tree.update(1, 1, N, id - K, id, -1);
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;
    cin >> T;

    for (ll t = 1; t <= T; ++t)
        solve();
}
