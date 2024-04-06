# Implement and demonstrate the FIND-S algorithm for finding the most specific hypothesis
# based on a given set of training data samples. Read the training data from a .CSV file

import pandas as pd

data = pd.read_csv('enjoysport.csv')

hypothesis = ['%' for _ in range(len(data.columns) - 1)]

positive_examples = data[data['EnjoySport'] == 'Yes'].iloc[:, :-1].values.tolist()

for example in positive_examples:
    for i in range(len(example)):
        if hypothesis[i] != '%' and hypothesis[i] != example[i]:
            hypothesis[i] = '?'
        else:
            hypothesis[i] = example[i]

print("The maximally specific Find-S hypothesis for the given training examples is:")
print(hypothesis)
