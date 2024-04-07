import numpy as np
import math
import csv

def read_data(filename):
    with open(filename, 'r') as csvfile:
        datareader = csv.reader(csvfile, delimiter=',')
        headers = next(datareader)
        metadata = []
        traindata = []
        for name in headers:
            metadata.append(name)
        for row in datareader:
            traindata.append(row)
    return metadata, np.array(traindata)

class Node:
    def __init__(self, attribute):
        self.attribute = attribute
        self.children = []
        self.answer = ""

    def __str__(self):
        return self.attribute

    def is_leaf(self):
        return self.answer != ""

def subtables(data, col, delete):
    dict = {}
    items = np.unique(data[:, col])
    count = np.zeros((items.shape[0], 1), dtype=np.int32)
    for x in range(items.shape[0]):
        for y in range(data.shape[0]):
            if data[y, col] == items[x]:
                count[x] += 1
    for x in range(items.shape[0]):
        dict[items[x]] = np.empty((int(count[x]), data.shape[1]), dtype="|S32")
        pos = 0
        for y in range(data.shape[0]):
            if data[y, col] == items[x]:
                dict[items[x]][pos] = data[y]
                pos += 1
        if delete:
            dict[items[x]] = np.delete(dict[items[x]], col, 1)
    return items, dict

def entropy(S):
    items = np.unique(S)
    if items.size == 1:
        return 0
    counts = np.zeros((items.shape[0], 1))
    sums = 0
    for x in range(items.shape[0]):
        counts[x] = sum(S == items[x]) / (S.size * 1.0)
    for count in counts:
        sums += -1 * count * math.log(count, 2)
    return sums

def gain_ratio(data, col):
    items, dict = subtables(data, col, delete=False)
    total_size = data.shape[0]
    entropies = np.zeros((items.shape[0], 1))
    intrinsic = np.zeros((items.shape[0], 1))
    for x in range(items.shape[0]):
        ratio = dict[items[x]].shape[0]/(total_size * 1.0)
        entropies[x] = ratio * entropy(dict[items[x]][:, -1])
        intrinsic[x] = ratio * math.log(ratio, 2)
    total_entropy = entropy(data[:, -1])
    iv = -1 * sum(intrinsic)
    for x in range(entropies.shape[0]):
        total_entropy -= entropies[x]
    return total_entropy / iv

def create_node(data, metadata):
    if len(set(data[:, -1])) == 1:
        node = Node("")
        node.answer = data[0, -1]
        return node
    gains = np.array([gain_ratio(data, col) for col in range(data.shape[1] - 1)])
    split = np.argmax(gains)
    node = Node(metadata[split])
    metadata = np.delete(metadata, split, 0)
    items, dict = subtables(data, split, delete=True)
    for x in range(items.shape[0]):
        child = create_node(dict[items[x]], metadata)
        node.children.append((items[x], child))
    return node

def empty(size):
    return " " * size

def print_tree(node, level):
    if node.is_leaf():
        print(empty(level), node.answer)
    else:
        print(empty(level), node.attribute)
        for value, child in node.children:
            print(empty(level + 1), value)
            print_tree(child, level + 2)

metadata, traindata = read_data("tennisdata.csv")
node = create_node(traindata, metadata)
print_tree(node, 0)

# reduced code -----------------------------------------------------------------------------------------------

import numpy as np
import math
import csv

def read_data(filename):
    with open(filename, 'r') as csvfile:
        datareader = csv.reader(csvfile, delimiter=',')
        metadata = [name for name in next(datareader)]
        traindata = np.array([row for row in datareader])
    return metadata, traindata

class Node:
    def __init__(self, attribute):
        self.attribute, self.children, self.answer = attribute, [], ""
    
    def __str__(self):
        return self.attribute

    def is_leaf(self):
        return bool(self.answer)

def subtables(data, col, delete):
    items = np.unique(data[:, col])
    dict = {
        item: np.array([row for row in data if row[col] == item])
        for item in items
    }
    if delete:
        dict = {
            item: np.delete(table, col, axis=1)
            for item, table in dict.items()
        }
    return items, dict

def entropy(S):
    items, counts = np.unique(S, return_counts=True)
    if len(items) == 1:
        return 0
    probs = counts / len(S)
    return -np.sum(probs * np.log2(probs))

def gain_ratio(data, col):
    items, dict = subtables(data, col, delete=False)
    total_size = data.shape[0]
    entropies = np.array([ratio * entropy(subtable[:, -1]) for ratio, subtable in [(dict[item].shape[0] / total_size, dict[item]) for item in items]])
    total_entropy = entropy(data[:, -1])
    iv = np.sum([(dict[item].shape[0] / total_size) * math.log(dict[item].shape[0] / total_size, 2) for item in items])
    return total_entropy / iv - np.sum(entropies)

def create_node(data, metadata):
    if len(set(data[:, -1])) == 1:
        node = Node("")
        node.answer = data[0, -1]
        return node
    gains = np.array([gain_ratio(data, col) for col in range(data.shape[1] - 1)])
    split = np.argmax(gains)
    node = Node(metadata[split])
    metadata = np.delete(metadata, split, 0)
    items, dict = subtables(data, split, delete=True)
    node.children = [(items[x], create_node(dict[items[x]], metadata)) for x in range(items.shape[0])]
    return node

def empty(size):
    return " " * size

def print_tree(node, level):
    if node.is_leaf():
        print(empty(level), node.answer)
    else:
        print(empty(level), node.attribute)
        [print(empty(level + 1), value) or print_tree(child, level + 2) for value, child in node.children]

metadata, traindata = read_data("tennisdata.csv")
node = create_node(traindata, metadata)
print_tree(node, 0)

