puts [t=1000]*?\s
t.times{
  puts [n=20, m=rand(1..1000)]*?\s
  puts (0..100).to_a.shuffle.take(n)*?\s
  puts (1..n).map{rand(1..20)}*?\s
}
