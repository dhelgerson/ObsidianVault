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
    a = int(input())
    b = int(input())

    return a/b

if __name__ == 'main':
    print(inputs())