
for ((sz=1; sz<=13; sz++)) do
    OUTPUT=$(time python jogo.py < ../ES/J/input/J_${sz}) && CORRECT=$( cat ../ES/J/output/J_${sz} )
    
    printf "TEST ${sz}: "
    
    if diff <(echo "$OUTPUT") <(echo "$CORRECT") &> /dev/null; then
        printf "OK"
    else
        printf "WRONG"
    fi
    
    printf "\n"
done
