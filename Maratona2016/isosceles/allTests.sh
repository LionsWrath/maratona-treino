
for ((sz=1; sz<=21; sz++)) do
    OUTPUT=$(./a.out < ../input-output/I/input/I_${sz}) && CORRECT=$( cat ../input-output/I/output/I_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
