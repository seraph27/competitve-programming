puts [n=100000, t=100000]*' '
t.times{
  l = rand(1..n)
  puts "#{l} #{rand(l..n)} #{rand(1..9999999)}"
}
