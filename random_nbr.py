import random

# Generate 20 unique random numbers
random_numbers = random.sample(range(-100, 100), 20)

# Join them with spaces
output = " ".join(map(str, random_numbers))
print(output)
