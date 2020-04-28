#!/bin/tcsh
foreach x (`seq 0 2`) #`seq 0 2` = 0 1 2
	echo "Running it in mode $x";
	foreach y (pushsearch*) #Uses all inputfiles starting with "pushsearch"
		echo "Running a.out $x < $y (5 repetitions)"
		foreach t (`seq 0 4`) #Repetitions
			a.out $x < $y > /dev/null
		end
	end
end

