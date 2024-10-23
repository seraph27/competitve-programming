def generate_input(n)
  # Generate an array from 1 to n
  original = (1..n).to_a
  
  # Shuffle to create permutations
  permutation_a = original.shuffle
  permutation_b = original.shuffle

  # Print the permutations
  puts n
  puts permutation_a.join(" ")
  puts permutation_b.join(" ")
end

# Example usage
n = 500000 # Adjust n as needed
generate_input(n)
