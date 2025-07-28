a = int(input());

if(a > 9223372036854775807): print("BigInteger")
elif(a > 2147483647): print("long")
elif(a > 32767): print("int")
elif(a > 127): print("short")
else: print("byte")
