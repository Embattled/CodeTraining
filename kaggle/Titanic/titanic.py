# data analysis and wrangling
import pandas as pd
import numpy as np
import random as rnd

# visualization
import seaborn as sns
import matplotlib.pyplot as plt

# machine learning
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC, LinearSVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.linear_model import Perceptron
from sklearn.linear_model import SGDClassifier
from sklearn.tree import DecisionTreeClassifier

train_df = pd.read_csv(
    '/home/eugene/workspace/CodeTraining/kaggle/Titanic/data/train.csv')
test_df = pd.read_csv(
    '/home/eugene/workspace/CodeTraining/kaggle/Titanic/data/test.csv')
combine = [train_df, test_df]

# print(train_df.columns)
# print(train_df.size)
# print(train_df.shape)
# print(train_df.ndim)


# train_df[['Pclass', 'Survived']].groupby(
#     ['Pclass'], as_index=False).mean().sort_values(by='Survived', ascending=False)

# train_df[["Sex", "Survived"]].groupby(
#     ['Sex'], as_index=False).mean().sort_values(by='Survived', ascending=False)

# train_df[["SibSp", "Survived"]].groupby(
#     ['SibSp'], as_index=False).mean().sort_values(by='Survived', ascending=False)


train_df = train_df.drop(['Ticket', 'Cabin'], axis=1)
test_df = test_df.drop(['Ticket', 'Cabin'], axis=1)