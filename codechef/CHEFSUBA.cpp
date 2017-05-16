#include <bits//stdc++.h>
using namespace std;
#define ll long long
bool ara[100005] = {0};
char s[100005];
int n, k, p;
map <int, int> mp;
set <int> st;
deque <int> dq;
void init () {
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (ara[i]) cnt++;
    }
    dq.push_back (cnt);
    st.insert (cnt);
    mp[cnt]++;
    for (int i = 1; ; i++) {
        if (i + k-1 >= n) break;
        if (ara[i-1] != ara[i+k-1]) {
            if (ara[i-1]) cnt--;
            else cnt++;
            dq.push_back (cnt);
            st.insert (cnt);
            mp[cnt]++;
        }
        else {
            dq.push_back (cnt);
            mp[cnt]++;
        }
    }
}
int m;
void shift () {
    int tem = (m+k) %n;
    int tt = dq.back ();
    dq.pop_back ();
    mp[tt]--;
    if (mp[tt] == 0) {
        st.erase (tt);
    }
    if (ara[tem] != ara[m]) {
        int p = dq.front();
        if (ara[tem]) {
            dq.push_front(p-1);
            mp[p-1]++;
            st.insert (p-1);
        }
        else {
            dq.push_front(p+1);
            mp[p+1]++;
            st.insert (p+1);
        }
    }
    else {
        int p = dq.front();
        dq.push_front(p);
        mp[p]++;
    }
    m--;
    if (m < 0) m = n-1;
}
int query () {
    set <int> :: iterator it = st.end();
    it--;
    return *it;
}
void print () {
    set <int> :: iterator it;
    for (it = st.begin(); it != st.end(); it++) cout << *it << " "; cout << endl;
    deque <int> :: iterator itt;
    for (itt = dq.begin(); itt != dq.end(); itt++) cout << *itt << " "; cout << endl;

}
int main ()
{
    while (scanf (" %d %d %d", &n, &k, &p) == 3) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d", &ara[i]);
            if (ara[i]) cnt ++;
        }
        if (k >= n) {
            printf ("%d\n", cnt);
            continue;
        }
        init ();
        scanf (" %s", s);
        m = n-1;
        //print();
        for (int i = 0; s[i]; i++) {
            if (s[i] == '!') shift ();
            else printf ("%d\n", query());
           // print();
        }
    }
    return 0;
}
