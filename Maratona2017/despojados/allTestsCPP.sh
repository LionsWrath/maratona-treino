
for ((sz=1; sz<=31; sz++)) do
    OUTPUT=$(time ./a.out < ../ES/D/input/D_${sz}) && CORRECT=$( cat ../ES/D/output/D_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
