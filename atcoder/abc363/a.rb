puts [n=1000,m=1000]*?\s
n.times{
  puts (1..m).map{rand(1..999)}*?\s
}
