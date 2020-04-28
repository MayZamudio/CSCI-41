#!/bin/tcsh

#This tests your program named a.out in the current directory
set a = "./a.out";
set dir = `dirname $0`;

if (! -e $a) then
	echo "Please type in local executable name: ";
	set a = $<
	if (! -x $a) then
		echo "Executable not found, aborting"
		exit 1;
	endif
endif

if (! -d $dir) then
	echo "Please type in the directory with the inputfiles: ";
	set dir = $<
	if (! -d $a) then
		echo "Directory not found, aborting"
		exit 1;
	endif
endif

echo "Running all the tests..."

foreach x ( `seq 0 40` )
	if (-e $dir/inputfile$x) then
		if (-e $dir/outputfile$x) then
			echo "Test $x : $a < $dir/inputfile$x | diff -B -w - $dir/outputfile$x"
			$a < $dir/inputfile$x | diff -B -w - $dir/outputfile$x
			if (`$a < $dir/inputfile$x | diff -B -w - $dir/outputfile$x | wc -l` == 0) then
				echo "TEST PASSED!";
			endif
		else
			echo "Error: outputfile$x not found";
			exit 1
		endif
	endif
end
