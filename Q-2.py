import time
import numpy as np
def matrix_multiply(A, B,result):
    # Get the number of rows/columns (since it's NxN)
    N = len(A)
    
    # Initialize the result matrix with zeros
    
    # Perform matrix multiplication
    for i in range(N):
        for j in range(N):
            for k in range(N):
                result[i][j] += A[i][k] * B[k][j]
    

def generate_matrix(N):
    # Generate a matrix of size NxN with random integers between 0 and 9
    return np.random.randint(0, 10, size=(N, N)).tolist()

def generate_matrix_double(N):
    # Generate a matrix of size NxN with random floating-point numbers between 0 and 9
    return np.random.uniform(0, 10, size=(N, N)).tolist()
    

# List of sizes to iterate through
#sizes = [64, 128, 256, 512, 1024]





#for N in sizes:
    # Generate two NxN matrices
n = 1024
A = generate_matrix_double(n)
B = generate_matrix_double(n)
result = [[0]*n for i in range(n)]
# Measure time taken for multiplication
start_time = time.process_time()  
matrix_multiply(A, B,result)
end_time = time.process_time()  

# Calculate elapsed time
elapsed_time_s = end_time - start_time 
print(elapsed_time_s)
# Print results
# print(f"Size {1024}x{1024}:")
# print(f"  Time taken = {elapsed_time_s:.9f} seconds")
# print()

# for N in sizes:
#     # Generate two NxN matrices
#     A = generate_matrix_double(N)
#     B = generate_matrix_double(N)
    
#     # Measure time taken for multiplication
#     start_time = time.process_time()  
#     result = matrix_multiply(A, B)
#     end_time = time.process_time()  
    
#     # Calculate elapsed time
#     elapsed_time_s = end_time - start_time
    
#     # Print results
#     print(f"Size {N}x{N}:")
#     print(f"  Time taken = {elapsed_time_s:.11f} seconds")
#     print()

'''
Integer:
Size 64x64:
  Time taken = 0.015625000 seconds

Size 128x128:
  Time taken = 0.078125000 seconds

Size 256x256:
  Time taken = 0.750000000 seconds

Size 512x512:
  Time taken = 6.484375000 seconds

Size 1024x1024:
  Time taken = 52.828125000 seconds

Size 64x64:
  Time taken = 0.000000000 seconds

Size 128x128:
  Time taken = 0.046875000 seconds

Size 256x256:
  Time taken = 0.515625000 seconds

Size 512x512:
  Time taken = 7.062500000 seconds

Size 1024x1024:
  Time taken = 49.546875000 seconds
  
Size 64x64:
  Time taken = 0.000000000 seconds

Size 128x128:
  Time taken = 0.062500000 seconds

Size 256x256:
  Time taken = 0.406250000 seconds

Size 512x512:
  Time taken = 5.609375000 seconds

Size 1024x1024:
  Time taken = 62.671875000 seconds
'''

'''
Floating Point:
Size 64x64:
  Time taken = 0.01562500000 seconds

Size 128x128:
  Time taken = 0.04687500000 seconds

Size 256x256:
  Time taken = 0.68750000000 seconds

Size 512x512:
  Time taken = 6.75000000000 seconds

Size 1024x1024:
  Time taken = 66.54687500000 seconds
  

'''