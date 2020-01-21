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
    return len(df[(df["loops"] >= lower) & (df["loops"] < upper)])

def count_pos(df, lower, upper):
    return len(df[(df["positive_loops"] >= lower) & (df["positive_loops"] < upper)])

def count_neg(df, lower, upper):
    return len(df[(df["negative_loops"] >= lower) & (df["negative_loops"] < upper)])

def main(filename):
    df = pd.read_csv(filename)
    df2 = pd.read_csv(filename)
    list_data=[]
    for i in range(0,100, 10):
        #c = count(df, i, i+10)
        #row = {"loops":" < "+str((i+10)).rjust(3, ' '), "benchmarks":c}
        #list_data.append(row)
        cp = count_pos(df, i, i+10)
        row_p = {"loop":"positive","loops":" < "+str((i+10)).rjust(3, ' '), "benchmarks":cp}
        list_data.append(row_p)
        cn = count_neg(df, i, i+10)
        row_n = {"loop":"negative","loops":" < "+str((i+10)).rjust(3, ' '), "benchmarks":cn}
        list_data.append(row_n)

    #c = count(df, 100, 4200)
    #row = {"loops":">= "+str((100)).rjust(3, ' '), "benchmarks":c}
    #list_data.append(row)
    cp = count_pos(df, 100, 4200)
    row_p = {"loop":"positive", "loops":">= "+str((100)).rjust(3, ' '), "benchmarks":cp}
    list_data.append(row_p)
    cn = count_neg(df, 100, 4200)
    row_n = {"loop":"negative", "loops":"=> "+str((100)).rjust(3, ' '), "benchmarks":cn}
    list_data.append(row_n)

    df = pd.DataFrame.from_dict(list_data)
    print(df)
    
    p=ggplot(df, aes(x='loops', y='benchmarks', fill='loop')) + geom_bar(stat = 'identity', position = 'dodge',width=0.6, show_legend = False) 
    
    p= p +  ggtitle("") + xlab("") + ylab("") + theme_classic()
    p= p + theme(axis_title_x=element_blank(), axis_text_x=element_blank(), axis_ticks=element_blank())
    p= p + theme(axis_title_y=element_blank(),axis_text_y=element_blank(), axis_ticks=element_blank())
    #p= p + theme(axis_text_x  = element_text(angle = 90, hjust = 0.2, size = 15))
    
    colors=[]
    colors.append('#999999')
    colors.append('#444444')
    
    p= p + scale_fill_manual(values=colors)
    p.save("num_benchmarks_loops.png")


if __name__ == "__main__":
    main(sys.argv[1])
