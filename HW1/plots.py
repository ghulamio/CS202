import matplotlib.pyplot as plt
import numpy as np


# Plot expected curves
# x = np.linspace(10, 100000)
# a = x * x
# b = x * np.log(x)
# c = x
# d = np.log(x)
#
#
# fig = plt.figure(figsize = (5, 5))
# p1 = plt.plot(x, a, c="red", alpha=0.5)
# p2 = plt.plot(x, b, c="green", alpha=0.5)
# p3 = plt.plot(x, c, c="blue", alpha=0.5)
# p3 = plt.plot(x, d, c="purple", alpha=0.5)
# plt.legend(["1", "2", "3", "4"], title="Algorithm")

# Plot individual scatter plots
x1 = [10, 100, 1000, 10000, 100000]
y1 = [0.002, 0.013, 0.94, 81.36, 7381.01]
y2 = [0.001, 0.009, 0.125, 1.312, 15.817]
y3 = [0.007, 0.011, 0.109, 0.853, 6.29]
# x1 = [10, 100, 1000]
# y1 = [0.002, 0.013, 0.94]
# y2 = [0.001, 0.009, 0.125]
# y3 = [0.007, 0.011, 0.109]
#
# p1 = plt.scatter(x1, y1, c="red", alpha=0.5)
# p2 = plt.scatter(x1, y2, c="green", alpha=0.5)
# p3 = plt.scatter(x1, y3, c="blue", alpha=0.5)
p1 = plt.plot(x1, y1, '-o', c="red", alpha=0.5)
p2 = plt.plot(x1, y2, '-o', c="green", alpha=0.5)
p3 = plt.plot(x1, y3, '-o', c="blue", alpha=0.5)

# plt.legend((p1, p2, p3), ("1", "2", "3"), scatterpoints=1, loc="upper left", title="Algorithm")
plt.legend(["1", "2", "3"], title="Algorithm")


plt.ylim((-10, 100))
# plt.yscale("log")
# plt.xscale("log")
plt.title("Actual run times")
plt.xlabel("N")
plt.ylabel("Runtime (ms)")
plt.savefig("output.png")
