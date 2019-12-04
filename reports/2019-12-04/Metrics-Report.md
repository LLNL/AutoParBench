# Metric report

## Evaluation platform

Intel(R) Xeon(R) CPU E5-2686 v4

## Metric report 

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.76693227 | 0.79710144 | 0.80436760 | 0.78172588 | 385 | 499 | 117 | 98 | 7 | 301 | 
 Dawnc | 0.60000000 | 0.30000000 | 0.67272727 | 0.40000000 | 6 | 31 | 4 | 14 | 0 |  8 | 
 ICC Cost | 0.93089430 | 0.31849791 | 0.62747979 | 0.47461138 | 229 | 625 | 17 | 490 | 136 |  100 | 
 ICC Full | 0.92187500 | 0.82373472 | 0.88395061 | 0.87004607 | 472 | 602 | 40 | 101 | 136 |  246 | 
 ICC Simd | 01.00000000 | 0.59574468 | 0.65454545 | 0.74666666 | 28 | 8 | 0 | 19 | 0 |  8 | 
 Cetus | 0.93548387 | 0.91194968 | 0.94570135 | 0.92356687 | 145 | 273 | 10 | 14 | 0 |  8 | 


## Metric report - Dataracebench

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.98765432 | 0.89887640 | 0.93055555 | 0.94117646 | 160 | 108 | 2 | 18 | 0 | 3 | 
 ICC Cost | 01.00000000 | 0.02040816 | 0.51515151 | 0.03999999 | 3 | 150 | 0 | 144 | 123 |  67 | 
 ICC Full | 0.75000000 | 0.15000000 | 0.74285714 | 0.25000000 | 9 | 147 | 3 | 51 | 123 |  154 | 
 Cetus | 0.98611111 | 0.93421052 | 0.95161290 | 0.95945945 | 142 | 94 | 2 | 10 | 0 |  8 | 


## Metric report - Rodinia

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.18181818 | 0.28571428 | 0.84269662 | 0.22222221 | 4 | 146 | 18 | 10 | 0 | 0 | 
 ICC Cost | 00.00000000 | 00.00000000 | 0.91666666 | 0.00000000 | 0 | 154 | 0 | 14 | 4 |  0 | 
 ICC Full | 0.37931034 | 0.78571428 | 0.87500000 | 0.51162790 | 11 | 136 | 18 | 3 | 4 |  0 | 
 Cetus | 0.33333333 | 0.66666666 | 0.97076023 | 0.44444443 | 2 | 164 | 4 | 1 | 0 |  0 | 


## Metric report  - Nas Parallel Benchmarks

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.69496855 | 0.75945017 | 0.73617693 | 0.72577995 | 221 | 245 | 97 | 70 | 7 | 298 | 
 ICC Cost | 0.93004115 | 0.40501792 | 0.61049107 | 0.56429462 | 226 | 321 | 17 | 332 | 9 |  33 | 
 ICC Full | 0.95966029 | 0.90581162 | 0.92114695 | 0.93195875 | 452 | 319 | 19 | 47 | 9 |  92 | 
 Cetus | 0.20000000 | 0.25000000 | 0.69565217 | 0.22222222 | 1 | 15 | 4 | 3 | 0 |  0 | 



## Metrics formula

precision (P) = TP/(TP + FP)

recall (R) = TP/(TP + FN)

accuracy (A) = (TP+TN)/(TP+FP+TN+FN)

F1 score (F1) = (2 * precision * recall)/(precision + recall)


## Tool version

 Tool | Version 
 --- | --- 
 Autopar (rose) | 0.9.10.235 
 DawnCC (clang) | 3.7.0 
 ICC | 19.0.4.243 
 Cetus | 1.4.4 
