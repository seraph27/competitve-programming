puts [n=rand(1..5), m=rand(1..n)]*?\s

puts (1..n).to_a.sample(m)*?\s
puts (1..m).map{ rand(1..n) }*?\s
