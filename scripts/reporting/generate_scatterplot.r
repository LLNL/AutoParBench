#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//
library(ggplot2)
library(dplyr)
library(RColorBrewer)
library(tidyr)
library(readr)
library(stringr)
library(ggbeeswarm)
options(scipen = 999)

df = read.csv('~/Downloads/time.csv')
df2 = read.csv('~/Downloads/time.csv')
df_header = df[,1]
df2_header = df2[,1]
df_tmp = log(df[,2:6])
df2_tmp = log(df2[,2:6])
df = cbind(df_header,df_tmp)
df2 = cbind(df2_header,df2_tmp)
names(df)[names(df) == "df_header"] <- "Benchmark"
names(df2)[names(df2) == "df2_header"] <- "Benchmark"
df = df %>% filter(!grepl('CTS', Benchmark))
df2 = df2 %>% filter(!grepl('CTS', Benchmark))
df = df %>% filter(!grepl('BPT_ATP', Benchmark))
df2 = df2 %>% filter(!grepl('BPT_ATP', Benchmark))
df = df %>% mutate(t = str_split(Benchmark, "_")) %>% mutate(t1 = sapply(t, '[', 1)) %>% mutate(t2 = sapply(t, '[', 2))
df2 = df2 %>% mutate(t = str_split(Benchmark, "_")) %>% mutate(t1 = sapply(t, '[', 1)) %>% mutate(t2 = sapply(t, '[', 2))
df = df %>% gather("type", "value", 2:6)
df2 = df2 %>% mutate(mean = rowMeans(select(.,starts_with("Time")), na.rm = TRUE))
df2 %>% head
p = ggplot () + theme_light()
p + theme(axis.title.x=element_blank(),axis.text.x=element_blank(), axis.ticks.x=element_blank()) +  theme(axis.title.y=element_blank(),axis.text.y=element_blank(), axis.ticks.y=element_blank()) + 
#p + theme(axis.text.x = element_text(angle = 45, hjust = 0.1, size = 12)) + theme(axis.text.y = element_text(size = 12)) + xlab("") + ylab("") +
  geom_point(data = df2, aes(x = t1, y = mean, colour = t2, shape = t2, size = 12), show.legend = FALSE)
ggsave("figure_7.pdf", width = 5, height = 5)

