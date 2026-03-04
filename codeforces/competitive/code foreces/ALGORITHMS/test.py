def create_file(filename):
    """Create an empty file."""
    try:
        with open(filename, 'w') as f:
            pass  # Just create the file, do not write anything yet
        print(f"File created: {filename}")
    except IOError as e:
        print(f"Error creating file: {e}")

def write_large_test_case(filename):
    """Write a large test case to the file."""
    # Parameters
    n = 500  # Number o  f items
    k = 1  # Maximum total increase
    item_cost = 10 # Cost of each item

    try:
        with open(filename, 'w') as f:
            # Write the number of test cases
            f.write("100\n")
            for i in range(100):
                # Write the number of items and maximum total increase
                f.write(f"{n} {k}\n")
                
                # Create the output as a list of strings to write in one go
                item_costs = f"{item_cost} " * n
                f.write(item_costs.strip() + "\n")
        
        print(f"Test case successfully written to {filename}")

    except IOError as e:
        print(f"Error writing to file: {e}")

if __name__ == "__main__":
    # Define the path to the file
    file_path = "large_test_case.txt"  # Change this path if needed

    # Create the file
    create_file(file_path)

    # Write the large test case to the file
    write_large_test_case(file_path)
