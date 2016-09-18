# python yeild 浅析
# 先看一个生成斐波纳契数列的例子
from inspect import isgeneratorfunction
__author__ = 'zhangxp'
# def fab(max):
#     n,a,b=0,0,1
#     while n<max:
#         print(b)
#         a,b=b,a+b
#         n = n+1
# 提高复用性返回一个list
# def fab(max):
#     n,a,b=0,0,1
#     L = []
#     while n<max:
#         L.append(b)
#         a,b=b,a+b
#         n = n + 1
#     return L
# 内存性能考虑
def fab(max):
    n,a,b=0,0,1
    while n<max:
        yield b
        a,b=b,a+b
        n = n + 1

def read_file(fpath):
    BLOCK_SIZE = 1024
    with open(fpath, 'rb') as f:
        while True:
            block = f.read(BLOCK_SIZE)
            if block:
                yield block
            else:
                return
if __name__=="__main__":
    text = read_file(r"F:\自己的项目\我的简历\1.txt")
    for s in text:
        print(s)
    # for x in fab(10):
    #     print(x)
    # f = fab(10)
    # try:
    #     while(1):
    #         {
    #                 print(f.__next__())
    #         }
    # except StopIteration:
    #     print("over")
    #
    # print("fab %s GeneratorFunction"%"is" if isgeneratorfunction(fab) else "not")

