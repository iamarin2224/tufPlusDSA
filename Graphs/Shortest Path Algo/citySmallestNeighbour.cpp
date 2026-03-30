#include <iostream>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));

    for (auto it: edges){
        matrix[it[0]][it[1]] = it[2];
        matrix[it[1]][it[0]] = it[2];
    }

    for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) matrix[i][j] = 0;
            }
        }

    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }

    int minCity = 0;
    int citiesInThreshold = INT_MAX;

    for (int i=0; i<n; i++){
        int curCitiesInThreshold = 0;

        for (int j=0; j<n; j++){
            if (matrix[i][j] <= distanceThreshold) curCitiesInThreshold++;
        }

        if (curCitiesInThreshold <= citiesInThreshold){
            minCity = i;
            citiesInThreshold = curCitiesInThreshold;
        }
    }

    return minCity;
}