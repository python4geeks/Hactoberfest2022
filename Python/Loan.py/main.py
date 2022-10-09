from ast import Index

import inline
import matplotlib
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

import warnings
warnings.filterwarnings("ignore")
train =pd.read_csv (r'C:\Users\HP\PycharmProjects\loan\train_ctrUa4K.csv')

print(train.head())


test = pd.read_csv(r'C:\Users\HP\PycharmProjects\loan\Test_Loan_Home.csv')
print(test.head())

sample = pd.read_csv(r'C:\Users\HP\PycharmProjects\loan\sample_submission_49d68Cx.csv')
print(sample.head())


print(train.columns)

print(test.columns)

print(sample.columns)

print(train.dtypes)

print(test.dtypes)

print(sample.dtypes)

print(train.shape)

print(test.shape)

print(sample.shape)

print(train["Loan_Status"].value_counts())

print(train["Loan_Status"].value_counts(normalize=True))

train["Loan_Status"].value_counts().plot.bar()
plt.show()

train["Gender"].value_counts(normalize=True).plot.bar(figsize=(20,10), title="Gender")
plt.show()
train["Married"].value_counts(normalize=True).plot.bar(title="Married")
plt.show()
train["Self_Employed"].value_counts(normalize=True).plot.bar(title="Self_Employed")
plt.show()
train["Credit_History"].value_counts(normalize=True).plot.bar(title="Credit_History")
plt.show()
