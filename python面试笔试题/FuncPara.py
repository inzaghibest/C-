__author__ = 'zhangxp'
def func(foo):
    foo[0] = 10
if __name__=="__main__":
    # foo = 2
    list1 = [1]
    # func(foo)
    func(list1)
    # print("foo = %d"%foo)
    print(list1)