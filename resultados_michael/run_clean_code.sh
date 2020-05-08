
BENCH=("chebyshev" "mibench" "poly6" "poly8" "poly5" "qspline" "sg")

set -e

for ((i = 0; i < ${#BENCH[@]}; i++)) do
    echo "Benchmark "${BENCH[i]}
    echo > verilog_${BENCH[i]}".out"
    for ((j = 0; j < 100; j++)) do
        for ((k = 1; k < 11; k++)) do
            python3 clean.py ${BENCH[i]}/$j/$k >> "verilog_"${BENCH[i]}".out"
        done
    done
done
