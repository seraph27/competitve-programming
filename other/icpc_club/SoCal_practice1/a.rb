n = 200_000
m = n

puts "#{n} #{m}"

# Generate a connected random tree with edges
edges = []
(2..n).each do |i|
  # Connect each node to a random previous node to ensure connectivity
  parent = rand(1...i)
  edges << [parent, i]
end

# Shuffle edges for randomness and print them
edges.shuffle.each do |edge|
  puts "#{edge[0]} #{edge[1]}"
end

# Generate queries that go from leaves to the root
# This is simply achieved by printing nodes in descending order
n.downto(1) do |i|
  puts i
end
