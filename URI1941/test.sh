
rm output.txt sol.txt

for ((sz=1; sz<=34; sz++)) do
    ./${1}.out < K/K_${sz}.in >> output.txt
    cat K/K_${sz}.sol >> sol.txt
done

diff sol.txt output.txt
