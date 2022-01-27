def solution(dartResult : str ) -> int:
    """[summary] 
        this function calculate points by the method of the input.
        there are three types of values(number, bonus, options)
        number has a value from 0 to 10
        bonus has three types : single, double, triple,
                               each means(num**1, num**2, num**3)
        options has two types : *, #
                                '*' doubles your previous, current number
                                '#' change your current number to negative
                                
    Args:
        dartResult (str): 3set of string include point|bonus|options
        
    Returns:
        int: caculated total points
    """
    answer = 0
    if "10" in dartResult:
        dartResult = dartResult.replace("10", "&") 
    bonus={'S':1, 'D':2, 'T':3}
    option={'*':2, '#':-1}
    num_list = []
    num=0
    for i, s in enumerate(dartResult):
        if (s >='0' and s<='9') or s=='&':
            if i!=0:
                num_list.append(num)
            if s=='&':
                num = 10
            else:
                num = ord(s)-ord('0')
        elif s in bonus.keys():
            num = num**bonus[s]
        elif s in option.keys():
            if s == '*'and len(num_list)!=0:
                try:
                    num_list[-1]*=2
                except Exception as err:
                    print(err)
                    print(i)
            num*=option[s]
            
    num_list.append(num)
    answer = sum(num_list)
    return answer
