# step 1) generate the data

import random
import string

def generate_random_string(length):
    """Generate a random string of uppercase letters."""
    return ''.join(random.choice(string.ascii_uppercase) for _ in range(length))

# Generate 20 records with at least five fields
data = []

for _ in range(20):
    record = {
        'Name': generate_random_string(5),
        'Age': random.randint(18, 60),
        'City': generate_random_string(8),
        'Salary': random.randint(30000, 80000),
        'Is_Employee': random.choice([True, False])
    }
    data.append(record)

# Print the generated data
for record in data:
    print(record)

# step 2) process    the data


def process_data(data):
    """Process and manipulate the generated data."""
    processed_data = []

    for record in data:
        # Add a new field 'Tax' based on Salary
        record['Tax'] = record['Salary'] * 0.2

        # Change 'Is_Employee' to 'Employee' or 'Non-Employee'
        record['Employee_Type'] = 'Employee' if record['Is_Employee'] else 'Non-Employee'
        del record['Is_Employee']  # Remove the old field

        # Modify the 'City' field to lowercase
        record['City'] = record['City'].lower()

        processed_data.append(record)

    return processed_data

# Process and manipulate the data
processed_data = process_data(data)

# Print the processed data
for record in processed_data:
    print(record)
