
for ((sz=1; sz<=36; sz++)) do
    OUTPUT=$(time ./a.out < ../input-output/G/input/G_${sz}) && CORRECT=$( cat ../input-output/G/output/G_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
