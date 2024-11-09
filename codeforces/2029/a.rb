# generator.rb
# Generates input based on the pattern described

# Define constraints
t = rand(1..1) # number of test cases
max_n = 15 # limit n to less than 10 for each test case

# Output the number of test cases
puts t

# Generate each test case
t.times do
  n = rand(max_n..max_n) # random number of contests for each test case, limited to max_n
  puts n
  # Generate n random ratings between 1 and n
  ratings = Array.new(n) { rand(1..n) }
  puts ratings.join(" ")
end
