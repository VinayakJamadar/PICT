# Problem Statement
# Descriptive Statistics - Measures of Central Tendency and variability
# Perform the following operations on any open source dataset (e.g., data.csv)

# 1. Provide summary statistics (mean, median, minimum, maximum, standard deviation) for
    # a dataset (age, income etc.) with numeric variables grouped by one of the qualitative
    # (categorical) variable. For example, if your categorical variable is age groups and
    # quantitative variable is income, then provide summary statistics of income grouped by
    # the age groups. Create a list that contains a numeric value for each response to the
    # categorical variable.
# 2. Write a Python program to display some basic statistical details like percentile, mean,
    # standard deviation etc. of the species of ‘Iris-setosa’, ‘Iris-versicolor’ and ‘Iris-
    # virginica of iris.csv dataset.
# Provide the codes with outputs and explain everything that you do in this step.

import pandas as pd
import numpy as np

# 1. Statisical details of income (quantitative variable) grouped by age (categorical variable)
# Refer : https://stackoverflow.com/questions/56351867/how-to-find-mean-of-quantitative-variable-from-categorical-variable-in-a-datafra

df1 = pd.read_csv('data.csv') #reading csv file
print(df1)
print('Statisical details')

# Refer : https://riptutorial.com/pandas/example/5965/grouping-numbers#:~:text=pandas%20Grouping%20Data%20Grouping%20numbers&text=a%20sequence%20of%20integers%20denoting,inf%5D%20.

age_groups = pd.cut(df1['Age'], bins=[0, 15, 59, 99], labels=['Children', 'Working Age', 'Senior Citizen'])
print('\n Mean')
print(df1.groupby(age_groups)['Income'].mean())
# print(df1.groupby('Age', as_index=False).mean())
print('\n Median')
print(df1.groupby(age_groups)['Income'].median())
# print(df1.groupby('Age', as_index=False).median())
# print('\nMode')
# print(df1.groupby(['Age'])['Income'].agg(pd.Series.mode))
print('\n Minimum')
print(df1.groupby(age_groups)['Income'].min())
# print(df1.groupby('Age', as_index=False).min())
print('\n Maximum')
print(df1.groupby(age_groups)['Income'].max())
# print(df1.groupby('Age', as_index=False).max())
print('\n Standard Deviation')
print(df1.groupby(age_groups)['Income'].std())
# print(df1.groupby('Age', as_index=False).std())

# 2. Statisical details of the species of ‘Iris-setosa’, ‘Iris-versicolor’ and ‘Iris-virginica of iris.csv dataset
# Refer : https://www.w3resource.com/machine-learning/scikit-learn/iris/python-machine-learning-scikit-learn-logistic-regression-exercise-1.php

df2 = pd.read_csv('iris.csv')
print(df2)
print('Iris-setosa')
setosa = df2['Species'] == 'Iris-setosa'
print(df2[setosa].describe())
print('\n Iris-versicolor')
setosa = df2['Species'] == 'Iris-versicolor'
print(df2[setosa].describe())
print('\n Iris-virginica')
setosa = df2['Species'] == 'Iris-virginica'
print(df2[setosa].describe())