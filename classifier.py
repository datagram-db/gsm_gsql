import pandas
import numpy
import seaborn as sns

from sklearn import tree
from sklearn import metrics

import viterbi
import math

import matplotlib.pyplot as plt
from mlxtend.plotting import plot_decision_regions
import matplotlib.colors as mcolors

dpiGraph = 300
fileName = 'lift10k.csv'
ml_data = pandas.read_csv("/home/giacomo/projects/gsm_gsql/csv_files/" + fileName)

#Check if circling
#https://github.com/marcin-osowski/igc_lib/blob/master/igc_lib.py
emissions = []
for bearing_rate in ml_data['bearing_rate']:
    bearing_change = math.fabs(bearing_rate)
    bearing_change_enough = (
        bearing_change > 40.0
    )
    if bearing_change_enough:
        emissions.append(1)
    else:
        emissions.append(0)
decoder = viterbi.SimpleViterbiDecoder(
    # More likely to start in straight flight than in circling
    init_probs=[0.80, 0.20],
    transition_probs=[
        [0.982, 0.018],  # transitions from straight flight
        [0.030, 0.970],  # transitions from circling
    ],
    emission_probs=[
        [0.942, 0.058],  # emissions from straight flight
        [0.093, 0.907],  # emissions from circling
    ])
output = decoder.decode(emissions)

liftValue = ml_data['lift'].values
classification = list()
for i in range(len(ml_data)):
    if output[i] == 1:
        # classification.append("thermal")
        if liftValue[i] == 1:
            classification.append("thermal")
        else:
            classification.append("none")
    else:
        if liftValue[i] == 1:
            classification.append("lift")
        else:
            classification.append("none")
ml_data['classification'] = classification
print(classification.count('thermal'))
print(classification.count('lift'))
print(classification.count('none'))

# ------------------ Make table for plotting where is circle
plotDataFrame = pandas.DataFrame(ml_data['unix_time'])
plotDataFrame['pressure_altitude'] = ml_data['pressure_altitude']
plotDataFrame['circle'] = output
plotDataFrame['lift'] = ml_data['lift']

# ------------------- Plot of time against altitude with colors
colors = list()
for i in range(len(plotDataFrame['circle'])):
    if plotDataFrame['lift'][i] == 1 and plotDataFrame['circle'][i] == 1:
        colors.append('red')
    elif plotDataFrame['circle'][i] == 1:
        colors.append('yellow')
    elif plotDataFrame['lift'][i] == 1:
        colors.append('orange')
    else:
        colors.append('whitesmoke')

# for i in range(len(ml_data['classification'])):
#     if ml_data['classification'][i] == 'thermal':
#         colors.append('red')
#     elif ml_data['classification'][i] == 'lift':
#         colors.append('yellow')
#     else:
#         colors.append('whitesmoke')

plt.figure(dpi=dpiGraph)
plt.scatter(x=ml_data['unix_time'], y=ml_data['pressure_altitude'], c=(colors), s=0.1)
plt.title(fileName)
plt.show()



# ml_data.insert(2, "classification", classification, True)




Y = ml_data['classification']
X = ml_data.drop(columns=['lift', 'classification', 'longitude_double', 'latitude_double', 'unix_time', 'weather_vc'])


from sklearn.model_selection import StratifiedKFold
skf = StratifiedKFold(n_splits=2)
StratifiedKFold(n_splits=2, random_state=None, shuffle=True)
for i, (train_index, test_index) in enumerate(skf.split(X, Y)):
    Y_train = ml_data.iloc[train_index]['classification']
    Y_test = ml_data.iloc[test_index]['classification']
    cp = ml_data.drop(columns=['lift', 'classification', 'longitude_double', 'latitude_double', 'unix_time', 'weather_vc'])
    X_train = cp.iloc[train_index]
    X_test = cp.iloc[test_index]
    break

model = tree.DecisionTreeClassifier(min_impurity_decrease=.0001) # criterion='entropy', max_depth=7
model.fit(X_train, Y_train)

# ------------------------------- PLOT TREE

plt.figure(dpi=dpiGraph)
tree.plot_tree(model,feature_names=X.columns)
plt.show()

y_pred = model.predict(X_test)
#y_pred = model.predict(X)
print("Accuracy:", metrics.accuracy_score(Y_test, y_pred))
print(set(y_pred))


probs = model.predict_proba(X_test)
heatMapValues = probs[:, list(model.classes_).index("lift")]



"""

colors_model = list()
for i in range(len(y_pred)):
    if y_pred[i] == 'thermal':
        colors_model.append('red')
    elif y_pred[i] == 'lift':
        colors_model.append('blue')
    else:
        colors_model.append('whitesmoke')
plt.figure(dpi=dpiGraph)
plt.scatter(x=plotDataFrame['unix_time'], y=plotDataFrame['pressure_altitude'], c=(colors_model), s=0.1)
plt.title("TEST")
plt.show()


"""

"""
X = ml_data.drop(columns=['lift'])
Y = ml_data['lift']

X_train, X_test, Y_train, Y_test = sklearn.model_selection.train_test_split(X, Y, test_size=0.2)

model = tree.DecisionTreeClassifier()
model.fit(X_train, Y_train)



print("test values input:\n")
print(X_test.values)

print("predictions for those inputs:\n")
predictions = model.predict(X_test.values)
print(predictions)


print("how accurate these predictions were:\n")
score = sklearn.metrics.accuracy_score(Y_test, predictions)
print(score)
"""
