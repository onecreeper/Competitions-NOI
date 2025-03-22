import math

# 定义函数来计算组合数
def combination(n, k):
    return math.factorial(n) // (math.factorial(k) * math.factorial(n - k))

# 定义函数来计算排列数
def permutation(n, k):
    return math.factorial(n) // math.factorial(n - k)

# 计算 C(1000, 100)
A_1000_100 = permutation(1000, 100)
# 计算 A(100, 100)
A_100_100 = permutation(100, 100)

# 计算 C(1000, 100) / A(100, 100)
result = A_1000_100 / A_100_100

print(result)