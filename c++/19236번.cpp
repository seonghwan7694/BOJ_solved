#include <bits/stdc++.h>
#include <tuple>
#include <unordered_map>
#include <utility>
using namespace std;

int MAX_SCORE = 0;
pair<int, int> dir[9] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

array<array<pair<int, int>, 4>, 4> move_fish(array<array<pair<int, int>, 4>, 4> map, tuple<int, int, int> shark){
    auto [shark_x, shark_y, shark_dir] = shark;

    for(int k = 1; k <= 16; k++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(map[i][j].first == k){
                    int fish_nx, fish_ny, fish_dir = map[i][j].second;
                    int cnt = 0;
                    while(true){
                        fish_nx = i + dir[fish_dir].first;
                        fish_ny = j + dir[fish_dir].second;
                        if(fish_nx < 0 or fish_nx >= 4 or fish_ny < 0 or fish_ny >= 4 or make_pair(fish_nx, fish_ny) == make_pair(shark_x, shark_y)){
                            cnt++, fish_dir++;
                            if(fish_dir > 8) fish_dir = 1;
                            if(cnt > 9) break;
                            continue;
                        }
                        break;
                    }
                    if(cnt > 9) break;
                    map[i][j] = make_pair(map[i][j].first, fish_dir);
                    swap(map[i][j], map[fish_nx][fish_ny]);
                }
            }
        }
    }
    return map;
}

void eat_fish(array<array<pair<int, int>, 4>, 4> map, tuple<int, int, int> shark, int score){
    auto &[shark_x, shark_y, shark_dir] = shark;

    score += map[shark_x][shark_y].first;
    shark_dir = map[shark_x][shark_y].second;
    MAX_SCORE = max(score, MAX_SCORE);
    map[shark_x][shark_y] = make_pair(0, 0);

    auto new_map = move_fish(map, shark);

    for(int i = 1; i <= 3; i++){
        int x = shark_x + dir[shark_dir].first * i;
        int y = shark_y + dir[shark_dir].second * i;
        if(x < 0 or x >= 4 or y < 0 or y >= 4) continue;
        if(map[x][y] == make_pair(0, 0)) continue;
        eat_fish(new_map, make_tuple(x, y, shark_dir), score);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    array<array<pair<int, int>, 4>, 4> map;
    for(int i = 0, a, b; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> a >> b;
            map[i][j] = make_pair(a, b);
        }
    }
    eat_fish(map, make_tuple(0, 0, 0), 0);
    cout << MAX_SCORE << "\n";
    return 0;
}