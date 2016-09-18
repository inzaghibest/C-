__author__ = 'zhangxp'


if __name__ == "__main__":
# 什么是列表解析
# 简单来说，列表解析（list comprehension）提供了一种优雅的生成列表的方法，能用一行代码代替十几行代码，而且
# 不损失任何可读性。而且，性能还快很多很多简单给个例子，如果我们需要0~100所有偶数组成的列表，正常的代码应该是
# 这样的：
#     a = []
# for i in range(101):
#     if(i%2 == 0):
#         a.append(i)
# 用列表解析是这样的:
# 简单的一行代码代替了4行代码
# 从上面的例子来看列表解析的语法其实不难，可以分成三个部分来看
# x：我们需要的列表里面的结果(1st part)
# for x in range(101):x来源——0~100的数字(2nd part)
# if x%2==0:x成立的条件，如果不成立就不放在列表里了(3rd part)
#     a = [x for x in range(101) if x%2==0]
#     for i in a:
#             print(i)
#     text = "hello world mfc best"
#     first_word = [word[0] for word in text.split()]
#     for c in first_word:
#         print(c)
    a = [1,2,3,4,5,6,7,8,9,0]
    b = (1,2,3,4,5)
    print(a)
    print(b)

