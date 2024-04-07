# without redused code
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

# reduced code
import pandas as pd

data = pd.read_csv('enjoysport.csv')

hypothesis = ['%' for _ in range(len(data.columns) - 1)]

positive_examples = data[data['EnjoySport'] == 'Yes'].iloc[:, :-1].values.tolist()

for example in positive_examples:
    hypothesis = [example[i] if hypothesis[i] == '%' or hypothesis[i] == example[i] else '?' for i in range(len(example))]

print("The maximally specific Find-S hypothesis for the given training examples is:")
print(hypothesis)
