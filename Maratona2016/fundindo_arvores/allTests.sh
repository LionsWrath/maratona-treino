for ((sz=1; sz<=40; sz++)) do
    OUTPUT=$(./a.out < ../input-output/F/input/F_${sz}) && CORRECT=$( cat ../input-output/F/output/F_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG ERR=${OUTPUT} OUT=${CORRECT}" 
    fi
    
    printf "\n"
done
