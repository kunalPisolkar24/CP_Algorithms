#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

struct Query {
    ll L, R, index;
};

class MoAlgorithm {
private:
    vl arr;
    ll n, block_size;
    vector<Query> queries;
    vl answers;
    unordered_map<ll,ll> mp;
    ll distinct_count;

    static bool compare(Query q1, Query q2, ll block_size) { 
        if(q1.L / block_size != q2.L / block_size) 
            return q1.L / block_size < q2.L / block_size;
        return q1.R < q2.R;
    }

    void add(ll index) {
        mp[arr[index]]++;
        if(mp[arr[index]] == 1) distinct_count++; 
    }

    void remove(ll index) {
        mp[arr[index]]--;
        if(mp[arr[index]] == 0) distinct_count--;
    }

public:

    MoAlgorithm(const vl &input): arr(input) {
        n = arr.size();
        block_size = static_cast<int>(sqrt(n));
    }

    void addQuery(ll L, ll R) {
        queries.push_back({L, R, static_cast<ll> (queries.size())});
    }

    vl processQueries() {
        sort(queries.begin(), queries.end(), 
            [this](Query q1, Query q2) { return compare(q1, q2, block_size); }); 
        answers.resize(queries.size());

        ll currentL = 0, currentR = -1;
        distinct_count = 0;

        for(const Query &q: queries) {
            while(currentL > q.L) {
                currentL--;
                add(currentL);
            }

            while(currentR < q.R) {
                currentR++;
                add(currentR);
            }

            while(currentL < q.L) {
                remove(currentL);
                currentL++;
            }

            while(currentR > q.R) {
                remove(currentR);
                currentR--;
            }

            answers[q.index] = distinct_count;
        }
        return answers;
    }
};

int main() {
    vl arr = {1, 1, 2, 1, 3, 4, 5, 2, 3};
    MoAlgorithm mo(arr);

    mo.addQuery(0, 4);
    mo.addQuery(1, 3);
    mo.addQuery(2, 4);

    vl results = mo.processQueries();

    for(ll i = 0; i < results.size(); i++)
        cout << "Query: " << i + 1 << " result: " << results[i] << endl;
    return 0;
}