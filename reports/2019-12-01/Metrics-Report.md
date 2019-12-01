# Metric report

## Evaluation platform

Intel(R) Xeon(R) CPU E5-2686 v4

## Metric report 

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.70270270 | 0.79510703 | 0.79931972 | 0.74605451 | 260 | 445 | 110 | 67 | 2 | 32 | 
 Dawnc | 01.00000000 | 01.00000000 | 01.00000000 | 01.00000000 | 28 | 35 | 0 | 0 | 0 |  0 | 
 ICC Cost | 0.65333333 | 0.15806451 | 0.67643742 | 0.25454543 | 49 | 551 | 26 | 261 | 136 |  83 | 
 ICC Full | 0.50753768 | 0.52061855 | 0.75226977 | 0.51399490 | 101 | 479 | 98 | 93 | 136 |  199 | 
 ICC Simd | 01.00000000 | 0.59574468 | 0.65454545 | 0.74666666 | 28 | 8 | 0 | 19 | 0 |  8 | 
 Cetus | 0.92857142 | 0.93464052 | 0.95161290 | 0.93159608 | 143 | 270 | 11 | 10 | 0 |  8 | 


## Metric report - Dataracebench

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.70270270 | 0.79510703 | 0.79931972 | 0.74605451 | 260 | 445 | 110 | 67 | 2 | 32 | 
 ICC Cost | 01.00000000 | 0.02040816 | 0.51351351 | 0.03999999 | 3 | 149 | 0 | 144 | 123 |  63 | 
 ICC Full | 0.75000000 | 0.15000000 | 0.74162679 | 0.25000000 | 9 | 146 | 3 | 51 | 123 |  150 | 
 Cetus | 0.98611111 | 0.93421052 | 0.95141700 | 0.95945945 | 142 | 93 | 2 | 10 | 0 |  8 | 


## Metric report - Rodinia

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 00.00000000 | 00.00000000 | 0.85119047 | 0.00000000 | 0 | 143 | 21 | 4 | 0 | 0 | 
 ICC Cost | 00.00000000 | 00.00000000 | 0.97468354 | 0.00000000 | 0 | 154 | 0 | 4 | 4 |  0 | 
 ICC Full | 0.04545454 | 0.25000000 | 0.84810126 | 0.07692306 | 1 | 133 | 21 | 3 | 4 |  0 | 
 Cetus | 00.00000000 | 00.00000000 | 0.96428571 | 0.00000000 | 0 | 162 | 6 | 0 | 0 |  0 | 


## Metric report  - Nas Parallel Benchmarks

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.53968253 | 0.69387755 | 0.69230769 | 0.60714284 | 102 | 195 | 87 | 45 | 2 | 31 | 
 ICC Cost | 0.63888888 | 0.28930817 | 0.67898383 | 0.39826838 | 46 | 248 | 26 | 113 | 9 |  20 | 
 ICC Full | 0.55151515 | 0.70000000 | 0.72029702 | 0.61694915 | 91 | 200 | 74 | 39 | 9 |  49 | 
 Cetus | 0.25000000 | 01.00000000 | 0.84210526 | 0.40000000 | 1 | 15 | 3 | 0 | 0 |  0 | 



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
