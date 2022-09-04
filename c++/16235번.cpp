#include<iostream>
#include<deque>
#include<algorithm>
 
using namespace std;
 
int n, m, k;
int feed_plus[12][12];
int feed[12][12];
deque<int> map[12][12];
int dir[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };
 
void spring_summer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].empty())continue;   //나무없으면 스킵
 
            sort(map[i][j].begin(), map[i][j].end());  
 
            int t = 0;
            for (; t < map[i][j].size(); t++)    //나무들이 양분먹고 나이 증가
            {
                if (map[i][j][t] <= feed[i][j]) 
                {
                    feed[i][j] -= map[i][j][t];    
                    map[i][j][t]++;
                }
                else break;
            }
             
            int t2 = map[i][j].size()-1;
            for (; t2 >= t; t2--)      //양분 못먹은 나무들 죽고 양분으로 변함
            {
                feed[i][j] += map[i][j][t2] / 2;
                map[i][j].pop_back();
            }
        }
    }
}
 
void fall()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].empty())continue;
 
            for (int t = 0; t < map[i][j].size(); t++)
            {
                if (map[i][j][t] % 5 == 0)   //나이가 5의 배수이면 주변에 나무 번식
                {
                    for (int d = 0; d < 8; d++)
                    {
                        int nextx = i + dir[d][0];
                        int nexty = j + dir[d][1];
                        if (nextx<1 || nexty<1 || nextx>n || nexty>n)continue;
                        map[nextx][nexty].push_back(1);   
                    }
                }
            } 
        }
    }
}
 
void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            feed[i][j] += feed_plus[i][j];
        }
    }
}
 
int tree_count()
{
    int sum= 0;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += map[i][j].size();
        }
    }
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> feed_plus[i][j];  //가을에 줄 양분 셋팅
            feed[i][j] = 5;        //처음 양분 셋팅
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        map[x][y].push_back(age);  //나무들 삽입
    }
     
    for(int i=0;i<k;i++)  //k번 돌리기
    {
        spring_summer();
        fall();
        winter();
    }
 
    int result=tree_count();
     
    cout << result;
 
    return 0;
}