def generate_test_case
  # Test case parameters
  n = rand(3..10) # Number of columns, adjust range as needed (minimum 3 to include 0, 1, and 2)
  
  # Ensure at least one 0, 1, and 2
  inscriptions = [0, 1, 2]
  
  # Fill the rest of the array with random values (0, 1, or 2)
  inscriptions += Array.new(n - 3) { rand(0..2) }
  
  # Shuffle the array to randomize the order
  inscriptions.shuffle!
  
  # Generate the test case as a string
  test_case = "#{n}\n" + inscriptions.join(" ")
  puts test_case
end

# Generate a single test case
puts "1" # Number of test cases is 1
generate_test_case
