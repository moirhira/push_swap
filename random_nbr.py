import random

# Generate 20 unique random numbers
random_numbers = random.sample(range(0, 600), 100)

# Join them with spaces
output = " ".join(map(str, random_numbers))
print(output)
