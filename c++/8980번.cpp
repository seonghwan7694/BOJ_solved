#include <bits/stdc++.h>
#include <tuple>
#define DEBUG 1
using namespace std;

int town, capacity, info;
int C[10101010];
vector<tuple<int, int, int>> v;

int main(){
    ios::sync_with_stdio(false);
    cin >> town >> capacity >> info;
    for(int i = 0, send_box, receive_box, box_ea; i < info; i++){
        cin >> send_box >> receive_box >> box_ea;
        v.push_back(make_tuple(send_box, receive_box, box_ea));
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b){
        auto &[a_send_box, a_receive_box, a_box_ea] = a; 
        auto &[b_send_box, b_receive_box, b_box_ea] = b; 
        if(a_receive_box == b_receive_box) return a_send_box < b_send_box;
        return a_receive_box < b_receive_box;
    });

    int ans = 0;
    for(int i = 0; i < info; i++){
        int box_max = 0;
        for(int from = get<0>(v[i]); from < get<1>(v[i]); from++){
            box_max = max(box_max, C[from]);
        }
        int left_space = min(get<2>(v[i]), capacity - box_max);
        ans += left_space;
        for(int from = get<0>(v[i]); from < get<1>(v[i]); from++){
            C[from] += left_space; 
        }
    }
    cout << ans << "\n";
    return 0;
}