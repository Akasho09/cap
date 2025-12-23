## 1️⃣ Bias (Error due to wrong assumptions)
- Bias is the error caused by a model being too simple and making strong assumptions about the data.
- Using a straight line to fit data that is actually curved.

## 2️⃣ Variance (Error due to sensitivity to data)
- Variance is the error caused by a model being too complex and reacting too much to small changes in training data.
- A very complex curve that passes through every training point.

## Activation Functions (Neural Networks)
- An activation function decides whether a neuron should be activated or not by adding non-linearity.
- Without activation functions → neural networks become linear (useless for complex tasks).
1. 1️⃣ Sigmoid
- Output: (0, 1)
- Used in binary classification
❌ Problem: Vanishing gradient

2. 2️⃣ ReLU (Rectified Linear Unit)
- f(x)=max(0,x)
- Most popular
- Fast computation
- Solves vanishing gradient
❌ Problem: Dying ReLU

3. 3️⃣ Tanh
- tanh(x)
- Output: (−1, 1)
- Zero-centered
- Better than sigmoid

4. 4️⃣ Softmax
- Converts outputs into probabilities
- Used in multi-class classification

| Function | Output Range     | Used In                 |
| -------- | ---------------- | ----------------------- |
| Sigmoid  | 0 to 1           | Binary classification   |
| Tanh     | −1 to 1          | Hidden layers           |
| ReLU     | 0 to ∞           | Hidden layers (default) |
| Softmax  | 0 to 1 (sum = 1) | Output layer            |

```yml
Bias → error from simplicity → underfitting
Variance → error from complexity → overfitting
Activation functions → add non-linearity so neural networks can learn complex patterns
```

