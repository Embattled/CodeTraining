import math

def basic_sigmoid(x):
    s = 1/(1+math.exp(-x))
    return s


import numpy as np
def sigmoid(x):
    s = 1/(1+np.exp(-x))
    return s


def sigmoid_derivative(x):
    s = sigmoid(x)
    ds = s*(1-s)
    return ds

def image2vector(image):
    v = image.reshape((image.shape[0]*image.shape[1]*image.shape[2],1))  
    return v    

def normalizeRows(x):
    """
    Implement a function that normalizes each row of the matrix x (to have unit length).
    
    Argument:
    x -- A numpy matrix of shape (n, m)
    
    Returns:
    x -- The normalized (by row) numpy matrix. You are allowed to modify x.
    """
    x_norm = np.linalg.norm(x, ord = 2, axis = 1, keepdims = True)
    x = x/x_norm
    return x


def softmax(x):
    """Calculates the softmax for each row of the input x.

    Your code should work for a row vector and also for matrices of shape (m,n).

    Argument:
    x -- A numpy matrix of shape (m,n)

    Returns:
    s -- A numpy matrix equal to the softmax of x, of shape (m,n)
    """
    x_exp = np.exp(x)
    x_sum = np.sum(x_exp,axis=1,keepdims=True)
    s = x_exp/x_sum
    return s

def L1(yhat, y):
    """
    Arguments:
    yhat -- vector of size m (predicted labels)
    y -- vector of size m (true labels)
    
    Returns:
    loss -- the value of the L1 loss function defined above
    """
    
    loss = abs(y-yhat).sum()
    return loss

def L2(yhat, y):
    """
    Arguments:
    yhat -- vector of size m (predicted labels)
    y -- vector of size m (true labels)
    
    Returns:
    loss -- the value of the L2 loss function defined above
    """
    loss = np.dot((y-yhat),(y-yhat))
    return loss