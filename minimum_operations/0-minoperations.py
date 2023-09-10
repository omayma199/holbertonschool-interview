#!/usr/bin/python3
"""
Minimum Operations
"""


def isPremium(n):
    """
    Checks if a number is premium
    """
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def minOperations(n):
    """
    defines minimum operations
    """
    if n < 2:
        return 0
    op_calc = 2
    opp = 0
    while(n != 1):
        if (isPremium(op_calc)):
            if (n % op_calc == 0):
                n = n / op_calc
                opp = opp + op_calc
            else:
                op_calc += 1
        else:
            op_calc += 1
    return opp
