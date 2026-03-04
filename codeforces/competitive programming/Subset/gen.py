def generate_beautiful_test_case(filename='beautiful_test_case.txt'):
    import math

    # Determine the maximum perfect square length less than 2 * 10^5
    max_side_length = 140  # 140x140 matrix is the largest square matrix fitting within 2 * 10^5
    max_length = max_side_length * max_side_length

    # Number of test cases
    t = 100

    # Open the file for writing
    with open(filename, 'w') as file:
        file.write(f"{t}\n")  # Write the number of test cases

        for _ in range(t):
            # Construct a beautiful binary matrix of size max_side_length x max_side_length
            matrix = []
            for i in range(max_side_length):
                if i == 0 or i == max_side_length - 1:
                    # First and last rows are all 1s
                    row = '1' * max_side_length
                else:
                    # Inner rows: first and last elements are 1s, others are 0s
                    row = '1' + '0' * (max_side_length - 2) + '1'
                matrix.append(row)
            
            # Convert matrix to a single string
            s = ''.join(matrix)
            
            # Write the test case to the file
            file.write(f"{max_length}\n")
            file.write(f"{s}\n")

# Call the function to generate and save the test case
generate_beautiful_test_case()
