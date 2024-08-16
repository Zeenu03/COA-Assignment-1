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
sizes = [64,128,256,512,1024]
for size in sizes:
  start_time = time.process_time()  
  n = size
  A = generate_matrix(n)
  B = generate_matrix(n)
  result = [[0]*n for i in range(n)]

  matrix_multiply(A, B,result)
  end_time = time.process_time()  

  # Calculate elapsed time
  elapsed_time_s = end_time - start_time 
  #Print results
  print(f"Size {1024}x{1024}:")
  print(f"  Time taken = {elapsed_time_s:.9f} seconds")
  print()

for size in sizes:
  start_time = time.process_time()  
  n = size
  A = generate_matrix_double(n)
  B = generate_matrix_double(n)
  result = [[0]*n for i in range(n)]

  matrix_multiply(A, B,result)
  end_time = time.process_time()  

  # Calculate elapsed time
  elapsed_time_s = end_time - start_time 
  #Print results
  print(f"Size {1024}x{1024}:")
  print(f"  Time taken = {elapsed_time_s:.9f} seconds")
  print()
