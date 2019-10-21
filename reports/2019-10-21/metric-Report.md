# Metric report

## Evaluation platform

Intel(R) Xeon(R) CPU E5-2686 v4

## Metric report 

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 AutoPar | 0.77142857 | 0.65707964 | 0.73927038 | 0.70967741 | 297 | 392 | 88 | 155 | 7 | 418 | 
 DawnCC | 0.60000000 | 0.30000000 | 0.67272727 | 0.40000000 | 6 | 31 | 4 | 14 | 0 |  8 | 
 ICC Cost | 0.97701149 | 0.30575539 | 0.57392571 | 0.46575341 | 255 | 533 | 6 | 579 | 136 |  85 | 
 ICC Full | 01.00000000 | 0.79459459 | 0.88115715 | 0.88554216 | 588 | 539 | 0 | 152 | 136 |  179 | 
 ICC Simd | 01.00000000 | 0.59574468 | 0.65454545 | 0.74666666 | 28 | 8 | 0 | 19 | 0 |  8 | 
 CETUS | 0.96644295 | 0.64864864 | 0.78497409 | 0.77628031 | 144 | 159 | 5 | 78 | 0 |  14 | 


## Metric report - Dataracebench

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 AutoPar | 01.00000000 | 0.77294685 | 0.83566433 | 0.87193459 | 160 | 79 | 0 | 47 | 0 | 5 | 
 ICC Cost | 01.00000000 | 0.03846153 | 0.41860465 | 0.07407405 | 7 | 119 | 0 | 175 | 123 |  63 | 
 ICC Full | 01.00000000 | 0.18085106 | 0.63849765 | 0.30630630 | 17 | 119 | 0 | 77 | 123 |  151 | 
 CETUS | 01.00000000 | 0.78688524 | 0.84274193 | 0.88073394 | 144 | 65 | 0 | 39 | 0 |  8 | 


## Metric report - Rodinia

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 AutoPar | 00.00000000 | 00.00000000 | 0.68695652 | 0.00000000 | 0 | 79 | 9 | 27 | 0 | 13 | 
 ICC Cost | 00.00000000 | 00.00000000 | 0.67272727 | 0.00000000 | 0 | 111 | 0 | 54 | 4 |  0 | 
 ICC Full | 01.00000000 | 0.66666666 | 0.89090909 | 0.79999999 | 36 | 111 | 0 | 18 | 4 |  0 | 
 CETUS | 00.00000000 | 00.00000000 | 0.68965517 | 0.00000000 | 0 | 80 | 1 | 35 | 0 |  5 | 


## Metric report  - Nas Parallel Benchmarks

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 AutoPar | 0.63425925 | 0.62844036 | 0.69868173 | 0.63133639 | 137 | 234 | 79 | 81 | 7 | 400 | 
 ICC Cost | 0.97637795 | 0.41471571 | 0.60749724 | 0.58215960 | 248 | 303 | 6 | 350 | 9 |  22 | 
 ICC Full | 01.00000000 | 0.90371621 | 0.93673695 | 0.94942324 | 535 | 309 | 0 | 57 | 9 |  28 | 
 CETUS | 00.00000000 | 00.00000000 | 0.63636363 | 0.00000000 | 0 | 14 | 4 | 4 | 0 |  1 | 



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
