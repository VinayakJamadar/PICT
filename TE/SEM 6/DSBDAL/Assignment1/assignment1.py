import pandas as pd
# import numpy as np

df = pd.read_csv('Salary_dataset.csv')

print("Printing Dataframe : \n", df)

# Data Preprocessing

print("Checking NULL or NaN values in Dataframe using isnull function : \n", df.isnull())

print("Describing Dataframe using describe function : \n", df.describe())

print("Displaying Dimensions of Dataframe using shape attribute : ", df.shape)

print("Displaying Datatypes of Dataframe using dtypes attribute : \n", df.dtypes)

print("Displaying Datatypes of Dataframe using info function :")
print(df.info(verbose=True))

# For get_dummies we will consider different data frame as follows
df = pd.DataFrame({'Roll_No': [111, 222, 333, 444],'Gender': ['male', 'male', 'female', 'male']})
df1 = pd.get_dummies(df, columns=['Gender'])
df.drop(columns=['Gender'])
pd.concat([df, df1])

df = pd.read_csv('Salary_dataset.csv')

# Data Formatting

print("Display of first n rows using head function : ")
# if n is positive it displays first 5 rows
print(df.head(5))
# if n is negative it displays first (total - n) rows
print(df.head(-3))

print("Display of first n rows using tail function : ")
# if n is positive it displays last 5 rows
print(df.tail(5))
# if n is negative it displays last (total - n) rows
print(df.tail(-3))

print("Drop rows of Dataframe having NULL or NaN values using dropna function : \n", df.dropna())

print("Drop columns of Dataframe having NULL or NaN values using dropna function : \n", df.dropna(axis='columns'))

print("Drop duplicates rows of Dataframe having same values in Salary column using dropna function : \n", df.drop_duplicates(subset=['Salary']))

# Replacing NaN or NULL values with mean value
df['YearsExperience'].fillna(value=df['YearsExperience'].mean(), inplace=True)
df['Salary'].fillna(value=df['Salary'].mean(), inplace=True)
print(df)

# Changing datatypes of 'Salary' from 'float64' to 'int64'
print(df.astype({'Salary': 'int64'}).dtypes)
df = df.astype({'Salary': 'int64'})
print(df)

# Data Normalization (Refer Link: https://stackoverflow.com/a/57067342)

# Sklearn normalization (biased)
# Normalization using sklearn (Gives biased estimates, different from pandas)

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()

df.iloc[:,:3] = scaler.fit_transform(df.iloc[:,:3].to_numpy())
print(df)

# MinMax normalization Using sklearn

# 1. Using formula
df = (df - df.min()) / (df.max() - df.min())

# 2. Using built in function
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler() 
arr_scaled = scaler.fit_transform(df) 

print(arr_scaled)

df_scaled = pd.DataFrame(arr_scaled, columns=df.columns,index=df.index)
print(df_scaled)