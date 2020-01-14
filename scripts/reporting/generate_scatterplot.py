"""
//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//
"""


library(ggplot2)
library(dplyr)
library(RColorBrewer)
library(tidyr)
library(readr)
library(stringr)
library(ggbeeswarm)
options(scipen = 999)

df = read.csv('time.csv')
df2 = read.csv('time.csv')

df

df = df %>% filter(!grepl('CTS', Benchmark))
df2 = df2 %>% filter(!grepl('CTS', Benchmark))

df = df %>% mutate(t = str_split(Benchmark, "_")) %>% mutate(t1 = sapply(t, '[', 1)) %>% mutate(t2 = sapply(t, '[', 2))
df2 = df2 %>% mutate(t = str_split(Benchmark, "_")) %>% mutate(t1 = sapply(t, '[', 1)) %>% mutate(t2 = sapply(t, '[', 2))



