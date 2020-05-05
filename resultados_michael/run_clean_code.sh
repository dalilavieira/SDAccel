
BENCH=("chebshev" "mibench" "p6" "p8" "poly5" "qspline" "sg")

set -e

for ((i = 0; i < ${#BENCH[@]}; i++)) do
    echo "Benchmark "${BENCH[i]}
    echo > ${BENCH[i]}".out"
    for ((j = 0; j < 100; j++)) do
        for ((k = 0; k < 10; k++)) do
            python3 clean.py ${BENCH[i]}/$j/$k >> ${BENCH[i]}".out"
        done
    done
done