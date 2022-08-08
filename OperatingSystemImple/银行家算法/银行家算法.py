import numpy as np
print("Please input n(how many process) and m(how many resource)")
n, m = map(int, input().split())
Max, Allocation, Need = [[0] * m for i in range(n)], [[0] * m for i in range(n)], [[0] * m for i in range(n)]
Request, Available = [0] * m, [0] * m

Max = np.array(Max)
Allocation = np.array(Allocation)
Need = np.array(Need)
Request = np.array(Request)
Available = np.array(Available)

print("Max")
for i in range(n):
    Max[i] = np.array(list(map(int, input().split())))
print("Allocation")
for i in range(n):
    Allocation[i] = np.array(list(map(int, input().split())))
print("Need")
Need = Max - Allocation
print(Need)
print("Request")
Request = np.array(list(map(int, input().split())))
print("Available")
Available = np.array(list(map(int, input().split())))

class Banker:
    def __init__(self, n, m, Max, Allocation, Need, Available):

        # 最大需求
        self.Max = Max
        # 已分配
        self.Allocation = Allocation
        # 目前需要
        self.Need = Need
        # 当前请求
        # self.Request = Request
        # 目前还剩
        self.Available = Available

        # 数组大小
        self.n = n
        self.m = m

    def requestSafe(self, i:int, Request:np.array)->bool:
        """
        银行家算法
        :param i: 表示第i个进程的请求
        :return: bool
        """
        if (Request > self.Need[i]).all():
            return False
        elif (Request > self.Available).all():
            return False
        else:
            self.Available = self.Available - Request
            self.Allocation[i] = self.Allocation[i] + Request
            self.Need[i] = self.Need[i] - Request
            if self.isSafe():
                return True
            else:
                self.Available = self.Available + Request
                self.Allocation[i] = self.Allocation[i] + Request
                self.Need[i] = self.Need[i] + Request
                return False

    def isSafe(self)->bool:
        # 安全性算法
        safe = 0
        flag = [False] * n
        for i in range(self.n):
            for j in range(self.n):
                # 对每个进程尝试分配
                if (self.Need[j] <= self.Available).all() and not flag[j]:
                    self.Available += self.Allocation[j]
                    safe += 1
                    flag[j] = True

        if safe == self.n:
            # 表示安全
            return True
        else:
            return False

b = Banker(n, m, Max, Allocation, Need, Available)
print("Safe?:", b.isSafe())
print("Banker?:", b.requestSafe(0, Request))
