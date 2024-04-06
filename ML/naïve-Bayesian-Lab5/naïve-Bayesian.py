import pandas as pd
from sklearn.naive_bayes import GaussianNB
from sklearn import metrics

train_data, test_data = pd.read_csv('PlayTennis.csv'), pd.read_csv('test.csv')

for data in [train_data, test_data]:
    data['Outlook'] = data['Outlook'].map({'Sunny': 0, 'Overcast':1, 'Rain': 2})
    data['Temperature'] = data['Temperature'].map({'Hot': 0,'Mild': 1, 'Cool': 2})
    data['Humidity'] = data['Humidity'].map({'High': 0, 'Normal':1})
    data['Wind'] = data['Wind'].map({'Weak': 0, 'Strong': 1})
    data['PlayTennis'] = data['PlayTennis'].map({'No': 0, 'Yes':1})

X_train, y_train = train_data.drop('PlayTennis', axis=1), train_data['PlayTennis']
X_test, y_test = test_data.drop('PlayTennis', axis=1), test_data['PlayTennis']

nb_classifier = GaussianNB().fit(X_train, y_train)
y_pred = nb_classifier.predict(X_test)

print("Predicted Output:")
for i, prediction in enumerate(y_pred):
    print(f"Sample {i + 1}: {'Yes' if prediction == 1 else 'No'}")

accuracy = metrics.accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)
