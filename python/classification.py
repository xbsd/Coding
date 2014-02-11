
# Several different classification methods
# Results were aggregated from the different classifiers to create ensemble

import numpy as np
from sklearn import grid_search
from sklearn import cross_validation as cv
from sklearn.svm import SVC
from sklearn.decomposition import PCA
from sklearn.cross_validation import StratifiedKFold
from sklearn import preprocessing

workDir = '/Users/xbsd/Desktop/'


names = ('STATE', ... other information has been removed)

formats = ('S10','i10', ... other information has been removed)

train = np.loadtxt(open(workDir + 'train.csv','rb'), delimiter = ',', skiprows=1,
	dtype={'names':names, 'formats':formats})

test = np.loadtxt(open(workDir + 'test.csv','rb'), delimiter = ',', skiprows=1,
	dtype={'names':names, 'formats':formats})

target = np.loadtxt(open(workDir + 'trainLabels.csv','rb'), delimiter=',', skiprows = 1)


le1 = preprocessing.LabelEncoder()

train['STATE'] = le1.fit_transform(train['STATE'])
... other statements removed ... repeat above for all categorical variables

test['STATE'] = le1.fit_transform(test['STATE'])
... other statements removed ... repeat above for all categorical variables


testl = []
testcomb = []
for w in test:
	testl = []
	for item in w:
		testl.append(int(item))
	testcomb.append(testl)

trainl = []
traincomb = []
for w in train:
	trainl = []
	for item in w:
		trainl.append(int(item))
	traincomb.append(trainl)

test  = np.array(testcomb)
train = np.array(traincomb)

pca = PCA(n_components=12,whiten=True)
train = pca.fit_transform(train)
test = pca.transform(test)


C_range = 10.0 ** np.arange(7,10)
gamma_range = 10.0 ** np.arange(-4,0)
class_weight_status=['auto']
params = dict(gamma=gamma_range,C=C_range, class_weight=class_weight_status)
cvk = StratifiedKFold(target,k=3)
classifier = SVC()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)
clf.fit(train,target)
print("The best classifier is: ",clf.best_estimator_)

C_range = 10.0 ** np.arange(8,10,.25)
gamma_range = np.arange(0.00001,0.0005,0.0001)

params = dict(gamma=gamma_range,C=C_range)
cvk = StratifiedKFold(target,k=3)
classifier = SVC()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)
clf.fit(train,target)
print("The best classifier is: ",clf.best_estimator_)



# Estimate score
scores = cv.cross_val_score(clf.best_estimator_, train, target, cv=30)

# Predict and save
result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_svc.csv', result, fmt='%d')


## 1. Testing with Ada Boost

cvk = StratifiedKFold(target,k=3)

estimators = np.arange(100,300,100)
learning_rate = np.arange(1,3,.25)
params = dict(n_estimators=estimators, learning_rate=learning_rate)

classifier = AdaBoostClassifier()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)
clf.fit(train,target)

print("The best classifier is: ",clf.best_estimator_)

result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_ada.csv', result, fmt='%d')


## 2. Testing with Stochastic Gradient Descent

from sklearn.linear_model import SGDClassifier

cvk = StratifiedKFold(target,n_folds=3)
alpha_estimates = np.arange(0.0001,0.001,0.0001)
shuffle_status = [True]
params = dict(alpha=alpha_estimates, shuffle=shuffle_status)
classifier = SGDClassifier()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)

clf.fit(train,target)

print("The best classifier is: ",clf.best_estimator_)

result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_gbm.csv', result, fmt='%d')


## 3. Testing with Random Forest

from sklearn.ensemble import RandomForestClassifier

cvk = StratifiedKFold(target,n_folds=3)
n_values = np.arange(100,1000,100)
minSplit = np.arange(1,10,1)
params = dict(n_estimators=n_values, min_samples_split=minSplit)
classifier = RandomForestClassifier()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)

clf.fit(train,target)

print("The best classifier is: ",clf.best_estimator_)

result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_rf.csv', result, fmt='%d')



## 4. Testing with Stochastic Gradient Descent

from sklearn.ensemble import GradientBoostingClassifier

cvk = StratifiedKFold(target,n_folds=3)
n_values = np.arange(10,1000,100)
learning_rate_values = np.arange(1,3,.25)

params = dict(n_estimators=n_values, learning_rate=learning_rate_values)
classifier = GradientBoostingClassifier()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)

clf.fit(train,target)

print("The best classifier is: ",clf.best_estimator_)

result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_gb2.csv', result, fmt='%d')


## 5. Testing with K Neighbours Classifier

from sklearn.neighbors import KNeighborsClassifier

cvk = StratifiedKFold(target,n_folds=3)
neighbours = np.arange(5,10,2)
weights_value = ['distance']

params = dict(n_neighbors = neighbours, weights=weights_value)
classifier = KNeighborsClassifier()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)

clf.fit(train,target)

print("The best classifier is: ",clf.best_estimator_)

result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_kn.csv', result, fmt='%d')


## 6. Testing with SVM


C_range = 10.0 ** np.arange(7,10)
gamma_range = 10.0 ** np.arange(-4,0)
class_weight_status=['auto']
params = dict(gamma=gamma_range,C=C_range, class_weight=class_weight_status)
cvk = StratifiedKFold(target,k=3)
classifier = SVC()
clf = grid_search.GridSearchCV(classifier,param_grid=params,cv=cvk, n_jobs=8)
clf.fit(train,target)
print("The best classifier is: ",clf.best_estimator_)
result = clf.best_estimator_.predict(test)
np.savetxt(workDir + 'result_svc.csv', result, fmt='%d')















