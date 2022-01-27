def solution(number : str, k : int) -> str:
    """Remove k numbers from original number to make biggest number.
    k must be a integer less than or equal to the original number length. 
    
    Args:
        number  (str) : original number with str type
        k       (int) : size of numbers to remove
        
    Returns:
        str: the biggest number after removing k numbers
    """
    answer = ''
    check = 0
    while k > 0 :
        if check >= len(number)-1:
            break
        if number[check] < number[check+1]:
            number = number[:check] +number[check+1:]
            check = check-1 if check!=0 else check
            k-=1
        else:
            check+=1
    
    answer = number[:-k] if k>0 else number
    
    return answer
