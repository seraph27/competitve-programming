puts [t=1]*?\s
t.times{
  puts [n=5, m=rand(1..100)]*?\s
  puts (1..10).to_a.shuffle.take(n)*?\s
  puts (1..n).map{rand(1..10)}*?\s
}
