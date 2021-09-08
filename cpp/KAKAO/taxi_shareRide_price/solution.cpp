#include <string>
#include <vector>
#define INF 9999999

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    int map[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j){
                map[i][j]=0;
                continue;
            }
            map[i][j] = INF;
        }
    }
    for(int k=0; k<fares.size(); k++){
        vector<int> temp=fares[k];
        map[temp[0]][temp[1]]=temp[2];
        map[temp[1]][temp[0]]=temp[2];
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    for(int mid=1; mid<=n; mid++){
        
        int thismid=map[s][mid]+map[mid][a]+map[mid][b];
        answer=min(answer,thismid);
    }
    
    return answer;
}