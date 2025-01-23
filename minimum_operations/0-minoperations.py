#!/usr/bin/python3
"""
Module qui calcule le nombre minimum d'opérations
pour obtenir n caractères 'H'
"""

def minOperations(n):
    """
    Calcule le nombre minimum d'opérations nécessaires
    pour obtenir exactement n caractères 'H'
    
    Args:
        n (int): nombre de caractères 'H' souhaités
        
    Returns:
        int: nombre minimum d'opérations nécessaires
    """
    if n <= 1:
        return 0
        
    operations = 0
    diviseur = 2
    
    while n > 1:
        while n % diviseur == 0:
            operations += diviseur
            n = n // diviseur
        diviseur += 1
        
        if diviseur * diviseur > n:
            if n > 1:
                operations += n
                break
                
    return operations
