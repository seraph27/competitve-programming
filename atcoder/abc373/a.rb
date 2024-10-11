t = 1
t.times{
  n = rand(1..8)
  m = rand(1..n)
  k = rand(1..100)

  puts [n, m, k].join(" ")
  sum = 0

  n.times do |i|
    val = rand(0..k-sum)
    sum += val
    puts val
  end
}
