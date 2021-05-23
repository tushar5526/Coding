def sudo_main(n):
    def calc_bits(n):
        bits = 1
        while(2 ** bits <= n):
            bits += 1
        return bits

    def calc_setbits(n):
        bits = calc_bits(n)
        set_bits = 0
        for i in range(bits):
            if (n & (1 << i)):
                set_bits += 1
        return set_bits


    print(f'bin for n is {bin(n)}')
    set_bitsn = calc_setbits(n)

    print(f'set bits in n is {set_bitsn}')
    count = 0
    for i in range(1, n):
        set_bitsi = calc_setbits(i)
        if set_bitsn == set_bitsi:
            print(i, bin(i))
            count += 1
    # print('Total such no:', count)
    print(n, count)
  
sudo_main(25)  
# for i in range(1,50):
#     sudo_main(i)