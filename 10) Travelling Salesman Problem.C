#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities (adjust as needed)
#define INF INT_MAX

// Function to find the minimum cost of visiting all cities
int tsp(int dist[N][N], int visited[], int dp[N][(1 << N)], int current_city, int visited_mask) {
    // Base case: If all cities have been visited, return the distance to the starting city
    if (visited_mask == (1 << N) - 1) {
        return dist[current_city][0];
    }

    // Check if the subproblem has already been solved
    if (dp[current_city][visited_mask] != -1) {
        return dp[current_city][visited_mask];
    }

    int min_cost = INF;

    // Try visiting each city that hasn't been visited yet
    for (int next_city = 0; next_city < N; next_city++) {
        if ((visited_mask & (1 << next_city)) == 0) {  // If the city hasn't been visited
            int new_visited_mask = visited_mask | (1 << next_city);
            int new_cost = dist[current_city][next_city] + tsp(dist, visited, dp, next_city, new_visited_mask);
            min_cost = (min_cost < new_cost) ? min_cost : new_cost;  // Minimize the cost
        }
    }

    // Store the result and return it
    dp[current_city][visited_mask] = min_cost;
    return min_cost;
}

int main() {
    // Distance matrix representing the distance between each pair of cities
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[N][(1 << N)];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;  // Initialize dp table with -1
        }
    }

    int visited[N] = {0};  // Keep track of the cities visited
    int min_cost = tsp(dist, visited, dp, 0, 1);  // Start from city 0 with only city 0 visited

    printf("Minimum cost to visit all cities: %d\n", min_cost);
    
    return 0;
}
