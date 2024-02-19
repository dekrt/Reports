import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_circles
from mpl_toolkits.mplot3d import Axes3D  # 用于3D散点图


# Generate the dataset with two concentric circles
X, y = make_circles(n_samples=500, noise=0.075, factor=0.5, random_state=2023)

# Convert the dataset to PyTorch tensors
X = torch.tensor(X, dtype=torch.float)
y = torch.tensor(y.reshape(-1, 1), dtype=torch.float)

# Split the dataset into training and testing sets
split = int(0.8 * len(X))
X_train, y_train = X[:split], y[:split]
X_test, y_test = X[split:], y[split:]

# 修改后的BinaryClassifier类
class BinaryClassifier(nn.Module):
    def __init__(self):
        super(BinaryClassifier, self).__init__()
        self.fc1 = nn.Linear(2, 4)
        self.fc2 = nn.Linear(4, 1)

    def forward(self, x):
        self.hidden_output = torch.sigmoid(self.fc1(x))  # 保存隐层输出以便可视化
        x = torch.sigmoid(self.fc2(self.hidden_output))
        return x



# Create an instance of the model
model = BinaryClassifier()

# Define the loss function and optimizer
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=0.02)

# Train the model
hidden_outputs = []  # 用于记录隐层输出
weights_history = []  # 用于记录权重

for epoch in range(250):
    optimizer.zero_grad()
    outputs = model(X_train)
    loss = criterion(outputs, y_train)
    loss.backward()
    optimizer.step()

    # 记录隐层输出和权重
    with torch.no_grad():
        hidden_outputs.append(model.hidden_output.numpy())
        weights_history.append(model.fc1.weight.data.numpy())

    if (epoch + 1) % 10 == 0:
        print(f'Epoch {epoch + 1}/250, Loss: {loss.item():.4f}')

# (代码省略，与示例相同)

# IV. 数据可视化分析
# A. 隐层数据分布可视化
# 1. 数据处理：已在训练循环中完成
# 2. 图表展示：隐层数据在二维平面的可视化
final_hidden_outputs = hidden_outputs[-1]  # 取最后一个epoch的隐层输出

# 绘制隐层数据的二维散点图
plt.figure(figsize=(8, 6))
plt.scatter(final_hidden_outputs[:, 0], final_hidden_outputs[:, 1], c=y_train.squeeze(), edgecolors='k')
plt.title('Hidden Layer Output (2D projection)')
plt.xlabel('Hidden Neuron 1')
plt.ylabel('Hidden Neuron 2')
plt.show()

# 绘制隐层数据的三维散点图
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')
ax.scatter(final_hidden_outputs[:, 0], final_hidden_outputs[:, 1], final_hidden_outputs[:, 2], c=y_train.squeeze())
ax.set_title('Hidden Layer Output (3D projection)')
ax.set_xlabel('Hidden Neuron 1')
ax.set_ylabel('Hidden Neuron 2')
ax.set_zlabel('Hidden Neuron 3')
plt.show()

# B. 权重变化过程可视化
# 1. 训练过程记录：已在训练循环中完成
# 2. 图表展示：权重变化曲线
weights_history = np.array(weights_history)  # 将权重历史转换为NumPy数组

# 绘制权重变化
plt.figure(figsize=(10, 8))
for i in range(weights_history.shape[2]):
    plt.plot(weights_history[:, 0, i], label=f'Weight {i + 1}')
plt.title('Weights Change Over Epochs')
plt.xlabel('Epoch')
plt.ylabel('Weight Value')
plt.legend()
plt.show()
