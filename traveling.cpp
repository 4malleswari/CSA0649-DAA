#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX
int tsp(int graph[MAX][MAX], int n) {
    int dp[1 << MAX][MAX];
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = INF;
        }
    }
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) && i != j) {
                        dp[mask][i] = dp[mask][i] < dp[mask ^ (1 << i)][j] + graph[j][i] ? dp[mask][i] : dp[mask ^ (1 << i)][j] + graph[j][i];
                    }
                }
            }
        }
    }
    int res = INF;
    for (int i = 1; i < n; i++) {
        res = res < dp[(1 << n) - 1][i] + graph[i][0] ? res : dp[(1 << n) - 1][i] + graph[i][0];
    }

    return res;
}

int main() {
    int graph[MAX][MAX], n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int result = tsp(graph, n);

    printf("The minimum cost to visit all cities is: %d\n", result);

    return 0;
}
