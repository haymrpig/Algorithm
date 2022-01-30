import math
global count
def isPrimeNum(num : int) -> bool:
    """check if the number is prime number
    
    Args:
        num (int) : the number want to check
        
    Return:
        bool : return True if the number is prime number
    """
    if num == 1 or num == 2:
        return True
    
    for i in range(2, int(math.sqrt(num))+1):
        if num % i == 0:
            return False
    return True

def DFS(nums : list, sum_ : int, d : int)-> None:
    """ Get combinations of numbers from number list and count prime numbers
        Using DFS algorithm, get combinations compose of three numbers from number list
        When three numbers of combination's sum is a prime number, increase count (global variable)
        So you can get the total number of prime numbers comsists of three numbers from the number list
        
    
    Args:
        nums (list) : total number list
        sum_ (int) : each sum of the combination of numbers
        d (int) : count numbers composing the combination
        
    Return:
        None
    """
    
    global count
    if d==3:
        if isPrimeNum(sum_):
            count+=1
            return
        else:
            return
        
    for i, num in enumerate(nums):
        DFS(nums[i+1:], sum_+num, d+1)
        
    return

def solution(nums):
    global count
    answer = -1
    count=0
    DFS(nums, 0, 0)
    answer = count
    return answer
