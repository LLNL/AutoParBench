# Metric report

## Evaluation platform

Intel(R) Xeon(R) CPU E5-2686 v4

## Metric report 

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.85546875 | 0.89024390 | 0.85746102 | 0.87250995 | 657 | 498 | 111 | 81 | 1 | 33 | 
 Dawnc | 01.00000000 | 0.30000000 | 0.73584905 | 0.46153846 | 6 | 33 | 0 | 14 | 0 |  10 | 
 ICC Cost | 0.91469194 | 0.28216374 | 0.61351556 | 0.43128490 | 193 | 615 | 18 | 491 | 136 |  126 | 
 ICC Full | 0.91697416 | 0.83811129 | 0.88499184 | 0.87577091 | 497 | 588 | 45 | 96 | 136 |  217 | 
 ICC Simd | 01.00000000 | 0.59574468 | 0.65454545 | 0.74666666 | 28 | 8 | 0 | 19 | 0 |  8 | 
 Cetus | 0.92567567 | 0.93835616 | 0.95260663 | 0.93197278 | 137 | 265 | 11 | 9 | 0 |  8 | 


## Metric report - Dataracebench

 TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | Different Parallelization 
 --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
 Autopar | 0.98757763 | 0.93529411 | 0.95167286 | 0.96072506 | 159 | 97 | 2 | 11 | 0 | 0 | 
 ICC Cost | 01.00000000 | 0.18681318 | 0.54179566 | 0.31481480 | 34 | 141 | 0 | 148 | 123 |  27 | 
 ICC Full | 0.96694214 | 0.71779141 | 0.83552631 | 0.82394365 | 117 | 137 | 4 | 46 | 123 |  46 | 
 Cetus | 0.97810218 | 0.96402877 | 0.96491228 | 0.97101448 | 134 | 86 | 3 | 5 | 0 |  8 | 


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
 Autopar | 0.84444444 | 0.89169675 | 0.83222222 | 0.86742756 | 494 | 255 | 91 | 60 | 1 | 33 | 
 ICC Cost | 0.89830508 | 0.32581967 | 0.57990314 | 0.47819547 | 159 | 320 | 18 | 329 | 9 |  99 | 
 ICC Full | 0.94132653 | 0.88701923 | 0.90716180 | 0.91336633 | 369 | 315 | 23 | 47 | 9 |  171 | 
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
