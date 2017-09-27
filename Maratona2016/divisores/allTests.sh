
for ((sz=1; sz<=78; sz++)) do
    OUTPUT=$(./a.out < ../input-output/D/input/D_${sz}) && CORRECT=$( cat ../input-output/D/output/D_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
