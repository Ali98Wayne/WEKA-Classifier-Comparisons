# WEKA Classifier Comparisons

This is C++ code written as part of a homework assignment from my "Data Mining: Intelligent Systems: Algorithms and Tools" graduate course in winter 2025. Before creating the C++ code, WEKA was used to load the following datasets: **anneal.arff, autos.arff, glass.arff, labor.arff, sonar.arff, tic-tac-toe.arff, & vehicle.arff**. The datasets were then trained with the following classifiers using 10-fold cross-validation & default parameters: **Naïve Bayes, J48, IBK, SMO, MultilayerPerceptron, Bagging, & AdaBoostM1**. The accuracies (weighted average of the true positive rate) and sizes of each dataset were documented for the classifiers on each dataset.

In order to compare the classifiers on each dataset, a Z-statistic value much be computed:
### Z = (pA – pB) / √((2p(1 – p)) / N)
**Where:**
* **pA: Accuracy of classifier A**
* **pB: Accuracy of classifier B**
* **p = (pA + pB) / 2**
* **N = Dataset size**

The Z-statistic values were represented on a 7x7 table, with each cell formatted as win-loss-tie on the datasets. A win would be when classifier A is better than classifier B where Z > -1.96, a loss would be when classifier B is better than classifier A where Z < 1.96, a tie would not fall under either of those ranges. Afterward, a single classifier is determined to be the winner after calculating the sum of all wins for all classifiers.

The C++ code created helps automate the calculations of Z-statistics, as considering what the homework problem was asking, there would be 147 unique values (due to table symmetry) which would be tedious to calculate manually. In order to see all 294 values (with duplicates) line 26 should be changed from “int k = j + 1” to “int k = 0”.

## 7x7 Classifier Comparison Table:

![image](https://github.com/user-attachments/assets/edfab514-380d-4890-ba7e-40a40d8b97fd)

**NOTE:** Cells with the same 2 classifiers don’t need Z-statistics, they are marked with “-“.

## Code Output Screenshots:

![1](https://github.com/user-attachments/assets/b14002e0-5d24-4aa1-a2b4-a213df7a6f9c)

![2](https://github.com/user-attachments/assets/8ae10d00-79aa-489a-a835-72309796b6df)

![3](https://github.com/user-attachments/assets/930abf74-1f28-4525-a4b2-5a37a8717265)

![4](https://github.com/user-attachments/assets/e498db66-0a17-40a4-9e5a-11e4b08e4363)

