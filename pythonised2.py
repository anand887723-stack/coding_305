# User authentication system

# Define the file path
user_file = "users.txt"

# Function to read user credentials from the file
def read_users():
    users = {}
    with open(user_file, "r") as file:
        for line in file:
            username, password = line.strip().split()
            users[username] = password
    return users

# Function to write user credentials to the file
def write_users(users):
    with open(user_file, "w") as file:
        for username, password in users.items():
            file.write(f"{username} {password}\n")

# Function to login and return the user's role
def login(username, password, users):
    if username in users and users[username] == password:
        if username == "admin":
            return "admin"
        return "user"
    return None

# Function to display the list of users
def list_users(users):
    for i, username in enumerate(users.keys(), 1):
        print(f"{i}. {username}")

# Function to add a new user
def add_user(users):
    username = input("Enter the new username: ")
    if username in users:
        print("Username already exists.")
        return
    password = input("Enter the new password: ")
    users[username] = password
    write_users(users)
    print("User added successfully.")

# Function to delete a user
def delete_user(users):
    list_users(users)
    try:
        user_index = int(input("Enter the sequence number of the user to delete: ")) - 1
        if 0 <= user_index < len(users):
            username_to_delete = list(users.keys())[user_index]
            del users[username_to_delete]
            write_users(users)
            print(f"{username_to_delete} has been deleted.")
        else:
            print("Invalid sequence number.")
    except ValueError:
        print("Invalid input. Please enter a valid number.")

# Main authentication loop
if __name__ == "__main__":
    users = read_users()
    flag = 1  # A flag to control the main loop

    while flag:
        print("Welcome to the User Authentication System")
        username = input("Enter your username: ")
        password = input("Enter your password: ")
        role = login(username, password, users)

        if role is None:
            print("Authentication failed. Please try again.")
        elif role == "user":
            print(f"Hello {username}")
        elif role == "admin":
            print("Welcome, admin!")
            print("1. List users")
            print("2. Add user")
            print("3. Delete user")
            print("4. Exit")    
            choice = input("Enter your choice (1/2/3/4): ")

            if choice == "1":
                list_users(users)
            elif choice == "2":
                add_user(users)
            elif choice == "3":
                delete_user(users)
            elif choice == "4":
                flag = 0  # Set the flag to 0 to exit the loop
            else:
                print("Invalid choice. Please enter a valid option.")
