echo "runnin"
for((i = 1; i <= 1000; ++i)); do
    echo $i
    python3 testing.py
    ./test < testcases > out1
    ./neural_networks < testcases > out2
    diff -w out1 out2 || break
done