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
from plotnine import *

def count(df, lower, upper):
    return len(df[(df["lines"] >= lower) & (df["lines"] < upper)])

def main(filename):
    df = pd.read_csv(filename)
    list_data=[]
    for i in range(0,1000, 100):
        c = count(df, i, i+100)
        row = {"lines":" < "+str((i+100)).rjust(4, ' '), "benchmarks":c}
        list_data.append(row)

    c = count(df, 1000, 4200)
    row = {"lines":">= "+str((1000)).rjust(4, ' '), "benchmarks":c}
    list_data.append(row)

    df = pd.DataFrame.from_dict(list_data)
    p=ggplot(df, aes(x='lines', y='benchmarks')) + geom_bar(stat = 'identity', width=0.6, position = position_dodge(width=0.7)) + theme_light()
    p= p + ggtitle("") + xlab("") + ylab("Number of Benchmarks") + theme(axis_text_x  = element_text(angle = 90, hjust = 0.2, size = 15))
    p.save("num_benchmarks_lines_of_code.png")

if __name__ == "__main__":
    main(sys.argv[1])
