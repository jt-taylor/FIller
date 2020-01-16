#!/bin/bash
#brew install coreutils for gtimeout --> cause the filler_vm
timeout=10
path=./resources
maps=/maps
players=/players
my_player=./jtaylor\.filler
mkdir results
for j in abanlin carli champely grati hcao superjeannot
do
	echo $j >> sum_out
	for k in map00 map01 map02
	do
		echo $k >> sum_out
		for i in 0 1 2 3 4
		do
	#		echo "${path}/filler_vm -f ${path}${maps}/${k} -p2 ${path}${players}/${j} -p1 ${my_player} -q" >> what_will_run
	#		touchresult/result\.${j}\.${k}\.${i}
			if [ $(( ( RANDOM % 2) )) -eq 0 ]
				then
				first_p=\-p1
				secon_p=\-p2
			else
				first_p=\-p2
				secon_p=\-p1
			fi
			#echo "${path}/filler_vm -f ${path}${maps}/${k} ${first_p} ${path}${players}/${j} ${secon_p} ${my_player} -q > results/result\.${j}\.${k}\.${i}"
			echo "Running "${k} " " ${first_p} " " ${j}\.filler ${secon_p} ${my_player}
			#mac doesn't have timeout
			#brew install coreutils lets you use it [prefixed with g]
			gtimeout 30s ${path}/filler_vm -f ${path}${maps}/${k} ${first_p} ${path}${players}/${j}\.filler ${secon_p} ${my_player} -q | tee -a sum_out results/result\.${j}\.${k}\.${i}
			cat filler.trace >> sum_out && echo "\n" >> sum_out
		done
	done
done
