echo "runnin"
for((i = 1; i <= 10000; ++i)); do
    echo $i
    python3 testing.py
    ./test < testcases >> out1
    ./test2 < testcases >> out2
    diff -w out1 out2 || break
done