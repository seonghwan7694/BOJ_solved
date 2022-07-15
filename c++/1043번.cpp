#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[51];
vector<int> knowing; // 이야기를 아는 사람 벡터
vector<vector<int>> party(50); // party 참여 명단

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return x = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n,m,k 입력
    cin >> n >> m >> k;
    // parent 초기화
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int x;
    // 이야기 아는사람 입력
    while (k--)
    {
        cin >> x;
        knowing.push_back(x);
    }
    // party 명단 입력
    int p, num, prev;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            // 같은 파티에 참여한 사람들을 같은 집합으로 합치는 과정
            if (j >= 1)
            {
                prev = num; 
                cin >> num;
                Union(prev, num);
            }
            else
                cin >> num;
            party[i].push_back(num);
        }
    }
}

int answer()
{
    int res = m;
    for (const auto &people : party) // 파티 순회
    {
        bool flag = false;
        for (const auto &person : people) // 파티의 참여자 순회
        {
            if (flag)
                break;
            for (const auto &know : knowing) // 이야기를 아는 사람 순회
            {
                // 파티의 참여자가 이야기를 아는 사람과 같은 집합(같은 파티에 참여한 적 있다)에 있다면 이 파티에서 거짓말을 할 수 없다. 그러므로 flag를 true로 바꿔주고 break 해준다.
                if (Find(person) == Find(know))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) // 파티에서 거짓말을 할 수 없다면
            res--;
    }

    return res;
}

int main()
{
    input();
    cout << answer() << '\n';
    return 0;
}