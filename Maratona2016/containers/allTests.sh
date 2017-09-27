
for ((sz=1; sz<=40; sz++)) do
    OUTPUT=$(time ./a.out < ../input-output/C/input/C_${sz}) && CORRECT=$( cat ../input-output/C/output/C_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
