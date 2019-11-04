for((i = 0; i<1000 ; ++i)); do
    echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./a < int) <(./brute < int) || break
done
