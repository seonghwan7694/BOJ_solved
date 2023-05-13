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
                if(map[i][j].first != k) continue;
                int fish_x = i, fish_y = j, fish_dir = map[i][j].second;
                for(int i = 0; i < 8; i++){
                    int fish_nx = fish_x + dir[fish_dir].first;
                    int fish_ny = fish_y + dir[fish_dir].second;
                    if(fish_nx < 0 or fish_nx >= 4 or fish_ny < 0 or fish_ny >= 4 or (fish_nx == shark_x and fish_ny == shark_y)){
                        fish_dir++;
                        if(fish_dir == 9) fish_dir = 1;
                        continue;
                    }
                    map[fish_x][fish_y].second = fish_dir;
                    swap(map[fish_x][fish_y], map[fish_nx][fish_ny]);
                    break;
                }
            }
        }
    }
    return map;
}

void eat_fish(array<array<pair<int, int>, 4>, 4> map, tuple<int, int, int> shark, int score){
    auto [shark_x, shark_y, shark_dir] = shark;

    score += map[shark_x][shark_y].first;
    MAX_SCORE = max(score, MAX_SCORE);
    map[shark_x][shark_y] = make_pair(0, 0);

    auto new_map = move_fish(map, make_tuple(shark_x, shark_y, shark_dir));

    for(int i = 1; i <= 3; i++){
        int x = shark_x + dir[shark_dir].first * i;
        int y = shark_y + dir[shark_dir].second * i;
        if(x < 0 or x >= 4 or y < 0 or y >= 4) continue;
        if(new_map[x][y].first == 0) continue;
        auto nnew_map = new_map;
        eat_fish(nnew_map, make_tuple(x, y, map[x][y].second), score);
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
    eat_fish(map, make_tuple(0, 0, map[0][0].second), 0);
    cout << MAX_SCORE << "\n";
    return 0;
}