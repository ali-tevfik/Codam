for i in {1..120};
do ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $ARG| wc -l ;ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG; done
