def is_odd_even(a):
    if(int(a)%2):
        return "odd"
    else:
        return "even"

a = input(f'Please enter the number: ')
print(is_odd_even(a))