#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double classifierPercentages[7][7] = {
    {0.863, 0.924, 0.991, 0.974, 0.991, 0.986, 0.836}, // anneal.arff accuracy percentages
    {0.561, 0.82, 0.761, 0.712, 0.80, 0.678, 0.449}, // autos.arff accuracy percentages
    {0.486, 0.668, 0.706, 0.561, 0.678, 0.724, 0.449}, // glass.arff accuracy percentages
    {0.895, 0.737, 0.825, 0.895, 0.86, 0.842, 0.877}, // labor.arff accuracy percentages
    {0.678, 0.712, 0.865, 0.76, 0.822, 0.769, 0.716}, // sonar.arff accuracy percentages
    {0.696, 0.846, 0.99, 0.983, 0.974, 0.915, 0.725}, // tic-tac-toe.arff accuracy percentages
    {0.855, 0.924, 0.935, 0.938, 0.995, 0.917, 0.70}}; // vehicle.arff accuracy percentages
    
    int datasetSizes[7] = {898, 205, 214, 57, 208, 958, 1728};

    double p = 0.0; // Initialize variable "p"
    double zStatistic = 0.0; // Initialize Z-statistic variable

    string dataSets[7] = {"anneal.arff", "autos.arff", "glass.arff", "labor.arff", "sonar.arff", "tic-tac-toe.arff", "vehicle.arff"}; // List of dataset file names
    string classifiers[7] = {"Naive Bayes", "J48", "IBK", "SMO", "MLP", "Bagging", "AdaBM1"}; // List of classifiers

    for (int i = 0; i < 7; i++) { // Increments through datasets
        cout << "\n" << dataSets[i] << ":\n\n"; 
        for(int j = 0; j < 7; j++) {// Increments through classifier A
            for(int k = j + 1; k < 7; k++) { // Iterates through classifier B (k being more than j to prevent duplicate Z-statistics)
                if (j != k) {
                    p = (classifierPercentages[i][j] + classifierPercentages[i][k]) / 2;
                    zStatistic = (classifierPercentages[i][j] - classifierPercentages[i][k]) / 
                    sqrt((2*p*(1-p) / datasetSizes[i]));

                    cout << "Z-statistic for " << classifiers[j] << " vs " << classifiers[k] << ": " << zStatistic << " | ";    
                    
                    if (zStatistic > 1.96) cout << "Win\n";
                    else if (zStatistic < -1.96) cout << "Loss\n";
                    else cout << "Tie\n";
                }
            }
        }
     }
    return 0;
}