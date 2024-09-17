def func():
    return True
def doNothing():
    pass

def convert(item):
    try:
        item = int(item)
    except:
        print('whoopsies, wrong datatype')
    
def returnSum(a,b):
    return a+b

def inputs():
    a = input()
    b = input()

    return a/b