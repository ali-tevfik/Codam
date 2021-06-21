for i in {1..120};
do ruby -e "puts (1..5).to_a.shuffle.join(' ')";ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"` ; ./push_swap $ARG| wc -l ;ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG; done
