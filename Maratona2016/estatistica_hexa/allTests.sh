
for ((sz=1; sz<=30; sz++)) do
    OUTPUT=$(time ./a.out < ../input-output/E/input/E_${sz}) && CORRECT=$( cat ../input-output/E/output/E_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
