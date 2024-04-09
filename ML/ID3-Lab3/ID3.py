#SHORTENED VERSION OF AMRITHS CODE

import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.tree import DecisionTreeClassifier, export_text

data = pd.read_csv('tennisdata.csv')

features = data.apply(LabelEncoder().fit_transform)
target_column = features.pop('PlayTennis')

visualization = export_text(
    DecisionTreeClassifier(criterion='entropy').fit(features, target_column),
    feature_names=list(features), class_names=['No', 'Yes'])

print(visualization)
