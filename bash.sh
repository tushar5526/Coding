rm out1 out2 f
for((i = 1; i <= 1000000; ++i)); do
    echo $i
    ./a $i > int
    ./a $i >> f
    ./w < int >> out1
    ./r < int >> out2
    diff -w out1 out2 || break
done