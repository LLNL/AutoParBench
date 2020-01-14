"""
//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//
"""

# import matplotlib
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import pandas as pd
import sys
import numpy as np
from plotnine import *

def main(filename):
    df = pd.read_csv(filename)
    df1 = df[0:36]
    df2 = df[36:72]
    print(df1.T)
    print(df2.T)
    #df = pd.melt(df, id_vars='Benchmark', value_vars=['Time_1', 'Time_2', 'Time_3', 'Time_4', 'Time_5'])
    df1 = pd.melt(df1, id_vars='Benchmark', value_vars=['Time_1', 'Time_2', 'Time_3', 'Time_4', 'Time_5'])
    df2 = pd.melt(df2, id_vars='Benchmark', value_vars=['Time_1', 'Time_2', 'Time_3', 'Time_4', 'Time_5'])
#
    p=ggplot(df1) + aes(x = 'Benchmark', y = 'value') + geom_boxplot()
    p= p + ggtitle("") + xlab("") + ylab("") + theme_classic() + theme(axis_text_x  = element_text(angle = 90, hjust = 0.2, size = 12))
    p= p + geom_vline(xintercept = 6.5, color="lightgray")
    p= p + geom_vline(xintercept = 12.5, color="lightgray")
    p= p + geom_vline(xintercept = 18.5, color="lightgray")
    p= p + geom_vline(xintercept = 24.5, color="lightgray")
    p= p + geom_vline(xintercept = 30.5, color="lightgray")
    p= p + geom_vline(xintercept = 36.5, color="lightgray")
    p= p + geom_vline(xintercept = 42.5, color="lightgray")

    p.save("time1.pdf", width = 40, height = 5, units = "cm")

    p=ggplot(df2) + aes(x = 'Benchmark', y = 'value') + geom_boxplot()
    p= p + ggtitle("") + xlab("") + ylab("") + theme_classic() + theme(axis_text_x  = element_text(angle = 90, hjust = 0.2, size = 12))
    p= p + geom_vline(xintercept = 6.5, color="lightgray")
    p= p + geom_vline(xintercept = 12.5, color="lightgray")
    p= p + geom_vline(xintercept = 18.5, color="lightgray")
    p= p + geom_vline(xintercept = 24.5, color="lightgray")
    p= p + geom_vline(xintercept = 30.5, color="lightgray")
    p= p + geom_vline(xintercept = 36.5, color="lightgray")
    p= p + geom_vline(xintercept = 42.5, color="lightgray")

    p.save("time2.pdf", width = 40, height = 5, units = "cm")


if __name__ == "__main__":
    main(sys.argv[1])
