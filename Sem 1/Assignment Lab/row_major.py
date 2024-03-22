def multiply_matrices_row_major(matrix1, matrix2):
    result = []

    # Check if matrices can be multiplied
    if len(matrix1[0]) != len(matrix2):
        print("Matrices cannot be multiplied. Invalid dimensions.")
        return None

    # Flatten matrices into 1D arrays
    flat_matrix1 = [element for row in matrix1 for element in row]
    flat_matrix2 = [element for row in matrix2 for element in row]

    # Perform matrix multiplication
    for i in range(0, len(flat_matrix1), len(matrix1[0])):
        for j in range(0, len(matrix2[0])):
            s = 0
            for k in range(len(matrix1[0])):
                s += flat_matrix1[i + k] * flat_matrix2[j + len(matrix2[0]) * k]
            result.append(s)

    # Reshape result into a 2D matrix
    result_matrix = [result[i:i+len(matrix2[0])] for i in range(0, len(result), len(matrix2[0]))]

    return result_matrix

# Example matrices
matrix1 = [
    [1, 2, 3, 10],
    [4, 5, 6, 20],
    [7, 8, 9, 30]
]

matrix2 = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1],
    [40, 50, 60]
]

result_matrix = multiply_matrices_row_major(matrix1, matrix2)
if result_matrix:
    print("Result of matrix multiplication in row-major order:")
    for row in result_matrix:
        print(row)
