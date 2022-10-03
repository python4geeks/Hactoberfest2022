# Step 1 - Load data
import pandas as pd
file_path='https://raw.githubusercontent.com/omairaasim/machine_learning/master/project_9_predict_weight_sex/weight-height.csv'
df = pd.read_csv(file_path)
df.head()
df['Gender'][:100]

# Step 2 - Analyze data
df.info()
df.describe()
df.isnull().sum()

# Step 3 - Convert Gender to number 
# Using LabelEncoder Start # Comment this section if using other option
X = df.iloc[:, :-1].values
y = df.iloc[:, 2].values
from sklearn.preprocessing import LabelEncoder
labelEncoder_gender =  LabelEncoder()
X[:,0] = labelEncoder_gender.fit_transform(X[:,0])

import numpy as np
X = np.vstack(X[:, :]).astype(np.float)
# Using LabelEncoder End #

# Step 4 - Split data
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Step 5 - Fit Regression Model
from sklearn.linear_model import LinearRegression
lin_reg = LinearRegression()
lin_reg.fit(X_train, y_train)

# Step 6 - Make Prediction using test data
lin_pred = lin_reg.predict(X_test)

# Step 7 - Model Accuracy
from sklearn import metrics
print('R square = ',metrics.r2_score(y_test, lin_pred))
print('Mean squared Error = ',metrics.mean_squared_error(y_test, lin_pred))
print('Mean absolute Error = ',metrics.mean_absolute_error(y_test, lin_pred))

# Step 8 - Predict my weight
my_weight_pred = lin_reg.predict([[0,74]])
print('My predicted weight = ',my_weight_pred)