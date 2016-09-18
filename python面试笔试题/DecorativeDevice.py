__author__ = 'zhangxp'
#装饰器本质上是一个Python函数，它可以让其他函数在不需要做任何代码变动的前提下增加额外功能，装饰器的返回值也
# 是一个函数对象。它经常用于有切面需求的场景，比如：插入日志、性能测试、事务处理、缓存、权限校验等场景。装饰
# 器是解决这类问题的绝佳设计，有了装饰器，我们就可以抽离出大量与函数功能本身无关的雷同代码并继续重用。概括的
# 讲，装饰器的作用就是为已经存在的对象添加额外的功能。
# 有如下函数:
def foo():
    print("hello world");
# 现在有一个新的需求，希望可以记录下函数的执行日志，于是在代码中添加日志代码：
def foo():
    print('i am foo')
 #   print("foo is runing")
# bar()、bar2()也有类似的需求，怎么做？再写一个logging在bar函数里？这样就造成大量雷同的代码，为了减少重复写
# 代码，我们可以这样做，重新定义一个函数：专门处理日志 ，日志处理完之后再执行真正的业务代码
# def use_log(func):
#     print("%s is runing"%func.__name__)
#     func()
# 逻辑上不难理解， 但是这样的话，我们每次都要将一个函数作为参数传递给use_logging函数。而且这种方式已经破坏了原
# 有的代码逻辑结构，之前执行业务逻辑时，执行运行bar()，但是现在不得不改成use_logging(bar)。那么有没有更好的方
# 式的呢？当然有，答案就是装饰器。
def use_log(func):
    def wrapper(*args, **kwargs):
        print("%s is running..."%func.__name__)
        return func(*args, **kwargs)
    return wrapper
def bar():
    print("I'm a bar!")
bar = use_log(bar)
#函数use_logging就是装饰器，它把执行真正业务方法的func包裹在函数里面，看起来像bar被use_logging装饰了。在这个例
#子中，函数进入和退出时 ，被称为一个横切面(Aspect)，这种编程方式被称为面向切面的编程
#(Aspect-Oriented Programming)。
#@符号是装饰器的语法糖，在定义函数的时候使用，避免再一次赋值操作
@use_log
def func1():
    print("I'm a func1()")
# 如上所示，这样我们就可以省去bar = use_logging(bar)这一句了，直接调用bar()即可得到想要的结果。如果我们有其他的
# 类似函数，我们可以继续调用装饰器来修饰函数，而不用重复修改函数或者增加新的封装。这样，我们就提高了程序的可重复利用
# 性，并增加了程序的可读性。
# 装饰器在Python使用如此方便都要归因于Python的函数能像普通的对象一样能作为参数传递给其他函数，可以被赋值给其他变量，
# 可以作为返回值，可以被定义在另外一个函数内。
#带参数的装饰器
def use_loglever(level):
    def decarator(func):
        def warpper(*args, **kwargs):
            print("Log Level:%s, %s is Running..."%(level,func.__name__))
            return func()
        return warpper
    return decarator

@use_loglever("Debug_Level")
def func2():
    print("I'm func2")

#类装饰器
class Foo(object):
    def __init__(self, func):
        self._func = func

    def __call__(self):
        print ('class decorator runing')
        self._func()
        print ('class decorator ending')

@Foo
def bar1():
    print ('bar')



if __name__=="__main__":
    # bar()
    # func1()
    # func2()
    bar1()
    print("%s"%func2.__name__)



